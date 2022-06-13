#include "dialogs.hpp"


/**
 * @brief Konstruktor dialogu ustawień
 *
 * @param[in] parent -- Wskaźnik na klasę okna głównego aplikacji
 *
 * Konstruktor kopiuje adres wskaźnika do ustawień gry do pola klasy ptrGameSett
 *  oraz za pomocą setupUi tworzy dialog stworzony w qtDesignerze. Na końcu następuje
 * połączenie sygnału przetłumaczenia z wywołaniem slotu retlasate().
 */
settDialog::settDialog(gameWindow* parent) {
  ptrGameSett = &(parent->gameSett);
  setupUi(this);
  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}

/**
 * @brief Slot zmiany języka
 *
 * Gdy klasa okna głównego wyśle sygnał że należy przeprowadzić translacje uruchomiony
 * zostaje poniższy slot. Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void settDialog::retranslate() {
  retranslateUi(this);
}

/**
 * @brief Metoda ładowania parametrów ustawień
 *
 * Metoda odczytuje wartości wskaźnika do ustawień aplikacji, na podstawie odczytanych
 * parametrów  dialog ustawień wyświetla odpowiednie opcje które są w danym momencie wybrane.
 * Metoda nie przyjmuje żadnych parametrów oraz nic nie zwr. 
 */
void settDialog::loadParam() {
  switch (ptrGameSett->language) {
  case english:
    languageBox->setCurrentIndex(english);
    break;
  case polish:
    languageBox->setCurrentIndex(polish);
    break;
  }

  switch (ptrGameSett->lifes) {
  case 1:
    lifeBox->setCurrentIndex(0);
    break;
  case 2:
    lifeBox->setCurrentIndex(1);
    break;
  case 3:
    lifeBox->setCurrentIndex(2);
    break;
  }

  switch (ptrGameSett->gamelvl) {
  case easy:
    levelBox->setCurrentIndex(easy);
    break;
  case medium:
    levelBox->setCurrentIndex(medium);
    break;
  case hard:
    levelBox->setCurrentIndex(hard);
    break;
  }

  if (ptrGameSett->rndBcnPlts) {
    bouncingCheck->setCheckState(Qt::Checked);
  }
  if (ptrGameSett->randomBallSpeed) {
    vellCheck->setCheckState(Qt::Checked);
  }
}

/**
 * @brief Slot obsługujący kliknięcie przycisku return
 *
 *  Slot jest wywyoływany gdy nie mają zostać zapisane żadne ustawienia.
 *  Slot nie przyjmuje argumentów i nic nie zwraca.
 *
 */
void settDialog::on_returnButton_clicked() {
  if (!ptrGameSett->rndBcnPlts) {
    bouncingCheck->setCheckState(Qt::Unchecked);
  }
  if (!ptrGameSett->randomBallSpeed) {
    vellCheck->setCheckState(Qt::Unchecked);
  }
  this->close();
}

/**
 * @brief Slot obsługujący klikniecie przycisku Save
 *
 * Slot jest wywoływany w momencie gdy ustawienia mają zostać zapie. 
 * W momencie wywołania do struktury ustawień programu zostają zapisane wybrane opcje.
 * Slot nie przyjmuje argumentów i nic nie zwraca.
 */
void settDialog::on_saveButton_clicked() {
  ptrGameSett->language = applicationLanguage(languageBox->currentIndex());
  ptrGameSett->lifes = (lifeBox->currentIndex() + 1);
  ptrGameSett->gamelvl = gameDifficulty(levelBox->currentIndex());
  if (vellCheck->checkState() == (Qt::Checked))
    ptrGameSett->randomBallSpeed = true;
  else
    ptrGameSett->randomBallSpeed = false;
  if (bouncingCheck->checkState() == (Qt::Checked))
  ptrGameSett->rndBcnPlts =true;
  else 
  ptrGameSett->rndBcnPlts =false;
    emit EmitSettingsSaved();
  this->close();
}






/**
 * @brief Konstruktor dialogu końca gry
 *
 * @param[in] parent -- Wskaźnik na klasę okna głównego aplikacji
 *
 * Konstruktor za pomocą setupUi tworzy dialog stworzony w qtDesignerze. Na końcu następuje
 * połączenie sygnału przetłumaczenia z wywołaniem slotu retranslate().
 */
endDialog::endDialog(gameWindow* parent) {

  setupUi(this);
  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}

/**
 * @brief Slot zmiany języka
 *
 * Gdy klasa okna głównego wyśle sygnał że należy przeprowadzić translacje uruchomiony
 * zostaje poniższy slot. Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void endDialog::retranslate() {
  retranslateUi(this);
}

/**
 * @brief Slot kliknięcia przycisku statystyk
 *
 * W momencie kliknięcia przycisku ustawienia zostaje wysłany sygnał EmitOpenStatistics
 * oraz zostaje zamknięty dialog końca . 
 *  Slot nie przyjmuje żadnych parametrów oraz nic nie zwr. 
 */
void endDialog::on_statisticsButton_clicked() {
  emit EmitOpenStatistics();
  this->close();
}
/**
 * @brief Slot kliknięcia przycisku Restart
 * W momencie kliknięcia przyciku restart zostaje wysłany sygnał EmitRestarme 
 * oraz zostaje zamknięty dialog końca gry.
 *  Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void endDialog::on_restartButton_clicked() {
  emit EmitRestartGame();
  this->close();
}

/**
 * @brief Slot kliknięcia przycisku Restart
 *
 *  W momencie kliknięcia przycisku exit zostaje wysłany sygnał EmitClosing
 * oraz zostaje zamknięty dialog końca gry.
 *  Slot nie przyjmuje żadnych parametrów oraz nic nie zwr. 
 */
void endDialog::on_exitButton_clicked() {
  emit  EmitClosing();
  this->close();
}



/**
 * @brief Konstruktor dialogu ustawień
 *
 * @param[in] parent -- Wskaźnik na klasę okna głównego aplikacji
 *
 * Konstruktor pomocą setupUi tworzy dialog stworzony w qtDesignerze i blokuje możliwość
 * naciśnięcia przyciku Connect aby nastapiło najpierw wyszukiwanie dostępnych urządzeń.
 * Na końcu następuje połączenie sygnału przetłumaczenia z wywołaniem slotu retlasate().
 */
conDialog::conDialog(gameWindow* parent) {
  setupUi(this);
  connectButton->setEnabled(false);

  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}

/**
 * @brief Slot zmiany języka
 *
 * Gdy klasa okna głównego wyśle sygnał że należy przeprowadzić translacje uruchomiony
 * zostaje poniższy slot. Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void conDialog::retranslate() {
  retranslateUi(this);
}

/**
 * @brief Slot kliknięcia przycisku cancel
 *
 * W momencie kliknieia przycisku cencel dialog połączenia się zamyka.
 * Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void conDialog::on_cancelButton_clicked() {
  this->close();
}

/**
 * @brief Slot wyszukania dostępnych urządzeń
 *
 * W momencie naciśnięcia przycisku Search device następuje wyszukanie urzązeń 
 * połączonych do kompuetera. Jeśli żadne urządzenie nie zostało znalezione to pojawia się
 * informacja że żadne urządzenie nie zostało znalezione.
 * Slot nie przyjmuje żadnych argumentów i nic nie zwraca.
 */
void conDialog::on_searchDeviceButton_clicked() {
  devicesList->clear();
  portList = QSerialPortInfo::availablePorts();
  if (portList.count() == 0) {
    devicesList->addItem("No devices to connect");
    connectButton->setEnabled(false);
    return;
  }
  connectButton->setEnabled(true);
  int devNum = 0;
  for (devNum = 0;devNum < portList.count();devNum++) {
    devicesList->addItem(portList.at(devNum).description());

  }
}

/**
 * @brief  Slot połączenia z urządzenia
 *
 * W chwili naciśnięcia przycisku connect następuje wysłanie sygnału EmitChonDev 
 * z nazwą urządzenia. Jeśli nie zostało znalezione żadne urządzenie to nasępuje tylko
 * zamknięcie okna dialogu.
 * Slot nie przyjmuje żadnych argumentów i nic nie zwra 
 */
void conDialog::on_connectButton_clicked() {
  if (devicesList->itemText(devicesList->currentIndex()) == "No devices to connect") {
    this->close();
    return;
  }
  QSerialPort tmpDev;
  QString portName = portList.at(devicesList->currentIndex()).portName();
  emit EmitChoosenDev(portName);
  this->close();
}




/**
 * @brief Konstruktor dialogu ustawień
 *
 * @param[in] parent -- Wskaźnik na klasę okna głównego aplikacji
 *
 * Konstruktor za pomocą setupUi oraz dziediczonej klasy, tworzy dialog stworzony w qtDesignerze.
 *  Na końcu następuje połączenie sygnału przetłumaczenia z wywołaniem slotu retlasate().
 */
disDialog::disDialog(gameWindow* parent) {
  setupUi(this);
  lineEdit->setReadOnly(true);
  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}

/**
 * @brief Slot zmiany języka
 *
 * Gdy klasa okna głównego wyśle sygnał że należy przeprowadzić translacje uruchomiony
 * zostaje poniższy slot. Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void disDialog::retranslate() {
  retranslateUi(this);
}

/**
 * @brief Metoda wyświetlająca dany stan połączenia
 *
 * @param[in] connectedDev-- Nazwa aktualnie połączonego urządzenia
 *
 *
 * Metoda wyświetla w polu lineEdit aktualną nazwe urządzenia oraz w zależności czy
 * jest połączone urządzenie czy nie pozwala rozłąc je. 
 * Metoda jako argument przyjmuje QString który jest nazwą aktualnie połączonego urządzenia
 * i nic nie zwraca.
 */
void disDialog::StartDialog(QString connectedDev) {
  lineEdit->setText(connectedDev);
  if (connectedDev == "No device to connect" || connectedDev == "") {
    lineEdit->setText("No device to connect");
    disconnectButton->setEnabled(false);
  }
  else
    disconnectButton->setEnabled(true);
}

/**
 * @brief Slot rozłączania podłączonego urządzenia
 *
 * W momencie kliknięcia przycisku disconnect emitowany jest sygnał EmitDisconnectDevice
 * oraz zamykany jest dialog rozłączania urządzenia.
 * Slot nie przyjumje argumentów i nic nie zwraca.
 */
void disDialog::on_disconnectButton_clicked() {
  emit EmitDisconnectDevice();
  this->close();
}

/**
 * @brief Slot powrotu
 *
 * W momencie klikniecia przycisku return zamykany jest dialog rozłączania.
 * Slot nie przyjmuje żadnych argumentów i nic nie zwraca.
 */
void disDialog::on_cancelButton_clicked() {
  this->close();
}