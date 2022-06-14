#include "gameWindow.hpp"
#define POLYNOMIAL 0x161

/**
 * @file
 * @brief Definicje metod klasy gameWindow
 *
 * Plik zawiera metody klasy gameWindow, która jest klasą pochodną
 * QMainWindow.
 */


uint16_t CRCSingleByte(uint16_t data) {
  uint16_t poly = (POLYNOMIAL << 7);
  for (uint8_t i = 0; i < 8; i++) {
    if ((data & 0x8000) != 0)
      data ^= poly;
    data <<= 1;
  }
  return data;
}

uint16_t CalculateCRC8(char* ptr) {
  uint16_t data = ptr[0] << 8;

  for (uint i = 1; i < strlen(ptr); i++) {
    data |= ptr[i];
    data = CRCSingleByte(data);
  }
  data = CRCSingleByte(data);
  return (data >> 8);
}


/**
 * @param[in] parent -- Wskaźnik na klasę QMainWindow
 *
 * Konstruktor alokuje pamięć dla wszystkich wskaźników oraz dodaje do stackWidget'a
 * widget główny oraz widget statystyk. Na koniec łączy przychodzące sygnały z odpowiednimi
 * slotami.
 */
gameWindow::gameWindow(QMainWindow* parent) {
  (void)parent;
  setupUi(this);
  this->CentralWidget = new mainWidget(this);
  this->connectionDialog = new conDialog(this);
  this->device = new QSerialPort;
  this->disconnectionDialog = new disDialog(this);
  this->endGameDialog = new endDialog(this);
  this->settingsDialog = new settDialog(this);
  this->statsWidget = new gameStatisticsWidget(this);
  this->stackWidget = new QStackedWidget();
  stackWidget->addWidget(CentralWidget);
  stackWidget->addWidget(statsWidget);
  this->setCentralWidget(stackWidget);


  connect(CentralWidget->statystyki, SIGNAL(EmitClosing()), this, SLOT(close()));
  connect(CentralWidget->statystyki, SIGNAL(EmitEndGame()), this, SLOT(endGame()));
  connect(CentralWidget->okienko, SIGNAL(EmitEndGame()), this, SLOT(endGame()));
  connect(statsWidget, SIGNAL(EmitChangeWidget()), this, SLOT(openGameWidget()));
  connect(connectionDialog, SIGNAL(EmitChoosenDev(QString)), this, SLOT(initDevice(QString)));
  connect(endGameDialog, SIGNAL(EmitClosing()), this, SLOT(close()));
  connect(endGameDialog, SIGNAL(EmitRestartGame()), this, SLOT(restartGame()));
  connect(endGameDialog, SIGNAL(EmitOpenStatistics()), this, SLOT(openStatisticsWidget()));
  connect(disconnectionDialog, SIGNAL(EmitDisconnectDevice()), this, SLOT(disconnectDevice()));
  connect(settingsDialog, SIGNAL(EmitSettingsSaved()), this, SLOT(checkLanguage()));
}
/**
 *Slot sprawdzający czy wystąpiłą zmiana języka, jest wywoływany podczas wystąpienia sygnału
 * EmitSettingsSaved() który informuje, że zostały zapisane nowe ustawienia gry. Slot jest odpowiedzny 
 * za sprawdzenie oraz jeśli istnieje potrzeba - załadowaniu nowego języka aplikacji.
 */
void gameWindow::checkLanguage() {
  static QTranslator* Trans = new QTranslator();

  switch (gameSett.language) {
  case english:
    qApp->removeTranslator(Trans);
    break;
  case polish:
    if (Trans->load("out/pro/gra_pl.qm", ".")) {
      qApp->installTranslator(Trans);
      qDebug() << "Trans zaladowany";
    }
    else
      std::cerr << "Loading new lang filed";
    break;

  }
  //retranslateUi(this);

}

void gameWindow::changeEvent(QEvent* event) {

  if (event->type() == QEvent::LanguageChange) {
    // std::cout << "Zmiana" << endl;
    retranslateUi(this);
    emit EmitRetranslate();
    return;
  }
  QMainWindow::changeEvent(event);
}
/**
 * Slot odpowiedzialny za rozłączenie aktualnie połączonego urządzenia. Wywoływany przez
 * sygnał EmitDisconnectDevice() przez dialog rozłaczenia.
 */
void gameWindow::disconnectDevice() {
  device->close();

}

/**
 * Slot odpowiedzialny za zmianę wyświetlanego widget'u na widget z grą oraz panelem bocznym, 
 * wywoływany przez sygnał EmitChangeWidget() przez widget statystyk (podczas naciśnięcia 
 * przycisku return).
 */
void gameWindow::openGameWidget() {
  stackWidget->setCurrentIndex(0);
  emit EmitPauzeGame();
  endGameDialog->show();
}
/**
 * Slot odpowiedzialny za zmianę stackwidget'u na widget z statystykami, wywoływany jest przez
 * sygnał EmitOpenStatistics() przez dialog końca gry, podczas naciśnięcia przycisku
 * Statistics.
 */
void gameWindow::openStatisticsWidget() {
  statsWidget->printChart();
  stackWidget->setCurrentIndex(1);
}
/**
 * Slot odpowiedzialny za obsługę końca gry, wywoływany przez sygnał EmitEndGame() emitowany
 * przez widget gry (w momencie gdy jeden z graczy przegra), lub przez widget panelu bocznego
 * (podczas wciśniecia przycisku End Game). Slot wyświetla dialog końca gry. 
 */
void gameWindow::endGame() {
  gameParam.blockButtons = true;
  emit EmitBlockButtons();
  //gameInfo.resetPosition=true;
  endGameDialog->show();
}
/**
 * Slot odpowiedzialny za obsługę restartu gry, wywoływany przez sygnał EmitRestartGame()
 * emitowany przez dialog końcowy. Odpowida za ponowne uruchomienie gry.
 */
void gameWindow::restartGame() {
  CentralWidget->gameTimer->start(10);
  gameParam.blockButtons = false;
  gameParam.isGameActive = true;
  gameParam.resetPosition = true;
  statsWidget->points->clear();
  emit EmitRestartGame();
  emit EmitBlockButtons();
}

/**
 * @param[in] devName -- Nazwa polaczonego urzadzenia
 *
 * Slot inicjalizujący połączenie z mikrokontrolerem, wywoływany przez sygnał
 * o możliwości połączenia z wybranym przez urzytkownika urządzeniem.
 */
void gameWindow::initDevice(QString devName) {
  gameInfo.devName = devName;
  device->setPortName(gameInfo.devName);
  if (device->open(QSerialPort::ReadWrite)) {
    device->setBaudRate(QSerialPort::Baud115200);
    device->setDataBits(QSerialPort::Data8);
    device->setParity(QSerialPort::NoParity);
    device->setStopBits(QSerialPort::OneStop);
    device->setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "Conected with ";
    // CentralWidget->EditText("Conected with " + devices.at(devNum).description());
    connect(this->device, SIGNAL(readyRead()), this, SLOT(ReadTransmision()));
  }
  else {
    qDebug() << "Initialization failed";
  }
  qDebug() << "Powiodla sie";

}
/**
 * Slot odpowiedzialny za odczytywanie danych z UART, wywoływany jest podczas
 * otrzymywania danych za pomocą UART-a.
 *
 */
void gameWindow::ReadTransmision() {
  uint16_t CRC8;
  std::string str;
  QString hexCRC8;
  QString terminator = " ";
  QString lineWOHex;          //line without hex code at end
  while (device->canReadLine()) {
    QString line = device->readLine();
    if (line.at(0) != "X")
      continue;

    int pos1 = line.lastIndexOf(terminator);
    lineWOHex = line.left(pos1);
    int pos2 = lineWOHex.lastIndexOf(terminator);
    lineWOHex = line.left(pos2);
    str = line.left(pos2).toStdString();
    CRC8 = CalculateCRC8(const_cast<char*>(str.c_str()));
    hexCRC8 = QString::number(CRC8, 16).toUpper(); //Cast uint16_t to Qstring
   // if (hexCRC8 == line.mid(pos2 + 1, pos1 - 1).trimmed())
      //std::cout<<str;
     // qDebug() << lineWOHex;
     // qDebug()<<line.left(line.length()-2);
    int ostatni = 0;
    ostatni = lineWOHex.lastIndexOf(terminator);
    gameInfo.ZVal = (lineWOHex.mid(ostatni + 1, lineWOHex.length()).toDouble()) * 0.0625 * 9.81;
    lineWOHex = lineWOHex.left(ostatni);
    ostatni = lineWOHex.lastIndexOf(terminator);
    gameInfo.YVal = (lineWOHex.mid(ostatni + 1, lineWOHex.length()).toDouble()) * 0.0625 * 9.81;
    lineWOHex = lineWOHex.left(ostatni);
    ostatni = lineWOHex.lastIndexOf(terminator);
    gameInfo.XVal = (lineWOHex.mid(ostatni + 1, lineWOHex.length()).toDouble()) * 0.0625 * 9.81;
    lineWOHex = lineWOHex.left(ostatni);

    // qDebug() << gameInfo.XVal;
    if (gameInfo.XVal > 5 && gameParam.setBallSpeed == 0) {
      gameParam.setBallSpeed = -1; //Ustawienie zwolnienie piłki przy odbiciu od platformy gracza

    }
    else if (gameInfo.XVal < -5 && gameParam.setBallSpeed == 0)
      gameParam.setBallSpeed = 1; //Ustawienie przyśpieszenia piłki przy odbiciu od platformy gracza


  }

}
/**
 * Slot obsługujący wybrania opcji połączenia, wywołujacy dialog z polaczeniem.
 */
void gameWindow::on_actionConnect_triggered() {

  connectionDialog->show();
  emit EmitPauzeGame();
}
/**
 * Slot obsługujący wybrania opcji ustawień, wywołuje dialog ustawień.
 */
void gameWindow::on_actionSettings_triggered() {
  settingsDialog->loadParam();
  settingsDialog->show();
  emit EmitPauzeGame();
}
/**
 *  Slot obsługujący wybrania opcji rozłączenia, wywołujacy dialog z rozłączeniem bierzącego urządzenia.
 */
void gameWindow::on_actionDisconnect_triggered() {

  // QDialog *disconnectionDialog=new QDialog();
  disconnectionDialog->StartDialog(gameInfo.devName);
  disconnectionDialog->show();
  emit EmitPauzeGame();

}