#include "inc/widgetgry.hpp"
#include <string>
#include "cstring"

#define POLYNOMIAL 0x161

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

  for (int i = 1; i < strlen(ptr); i++) {
    data |= ptr[i];
    data = CRCSingleByte(data);
  }
  data = CRCSingleByte(data);
  return (data >> 8);
}

void gameParameters::calculateVel() {
  if (ZVal < 8 || ZVal>10)
    ballVel = ballVel * ZVal / 9.81;
  userPlateVel = userPlateVel * YVal / 9.81;
}

/*
UARTThread::UARTThread(gameParameters& gameinfo)
{
  device.setPortName(gameinfo.devName);
  if (device.open(QSerialPort::ReadWrite)) {
    device.setBaudRate(QSerialPort::Baud115200);
    device.setDataBits(QSerialPort::Data8);
    device.setParity(QSerialPort::NoParity);
    device.setStopBits(QSerialPort::OneStop);
    device.setFlowControl(QSerialPort::NoFlowControl);
    // CentralWidget->EditText("Conected with " + devices.at(devNum).description());
    // connect(this->device, SIGNAL(readyRead()), this, SLOT(ReadTransmision()));
  }
  else {
    qDebug() << "Initialization failed";
  }
  qDebug()<<"Powiodla sie";

}
void UARTThread::run() {
  while (1) {
    QString line = device.readLine();
    qDebug()<<line;
    msleep(1000);
  }
  qDebug()<<device.canReadLine();
}
*/

disDialog::disDialog(QString connectedDev) {
  setupUi(this);
  //lineEdit->setReadOnly(true);
  //lineEdit->textEdited(connectedDev);

  //text->setReadOnly(true);
}
void disDialog::StartDialog(QString connectedDev) {
  lineEdit->textEdited(connectedDev);
  qDebug() << connectedDev;
}

conDialog::conDialog() {
  setupUi(this);
  // connect(this,SIGNAL(EmitChooseDev(QString)),parent->centralWidget->okienko,initDevice(QString aa));
 //connect(searchDeviceButton, SIGNAL(clicked()), this, SLOT(searchDev()));
// connect(connectButton, SIGNAL(clicked()), this, SLOT(chooseDev()));
}
//void condDialog::chooseDev(){
//}


void conDialog::on_cancelButton_clicked() {
  this->close();
}

void conDialog::on_searchDeviceButton_clicked() {
  devicesList->clear();
  portList = QSerialPortInfo::availablePorts();
  if (portList.count() == 0) {
    devicesList->addItem("No devices to connect");
    return;
  }
  int devNum = 0;
  for (devNum = 0;devNum < portList.count();devNum++) {
    devicesList->addItem(portList.at(devNum).description());
    //qDebug() << devices.at(devNum).portName() << devices.at(devNum).description();
    //if (devices.at(devNum).description() == "STM32 STLink")
     // break;
  }
}
void conDialog::on_connectButton_clicked() {
  QSerialPort tmpDev;
  QString portName = portList.at(devicesList->currentIndex()).portName();
  //qDebug()<<portName;
  //devicesList->currentIndex();
  emit EmitChoosenDev(portName);
  this->close();
}

/*
  QString portName = devices.at(devNum).portName();

  device->setPortName(portName);

  if (device->open(QSerialPort::ReadWrite)) {
    device->setBaudRate(QSerialPort::Baud115200);
    device->setDataBits(QSerialPort::Data8);
    device->setParity(QSerialPort::NoParity);
    device->setStopBits(QSerialPort::OneStop);
    device->setFlowControl(QSerialPort::NoFlowControl);
    CentralWidget->EditText("Conected with " + devices.at(devNum).description());
    connect(this->device, SIGNAL(readyRead()), this, SLOT(ReadTransmision()));
  }
  else {
    CentralWidget->EditText("Can't connect with device");
  }*/
  //}

mainGameWidget::mainGameWidget(QWidget* parent) :QWidget(parent) {
  background.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/tlo.png");
  computerPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  userPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  // background=background.scaled(500,Qt::IgnoreAspectRatio);

}
void mainGameWidget::paintEvent(QPaintEvent*) {
  QPainter  Rysownik(this);
  double proporcjeWS_Obraz = background.height() / background.width();
  double proporcjeWS_Okno = height() / width();
  double Skala;
  if (proporcjeWS_Obraz < proporcjeWS_Okno) {
    Skala = height() / static_cast<double>(background.height());
  }
  else {
    Skala = width() / static_cast<double>(background.width());
  }
  //Skala=10;

  Rysownik.scale(Skala, Skala);
  Rysownik.drawImage(0, 0, background);
  Rysownik.scale(1 / Skala, 1 / Skala);
  Rysownik.drawImage(width() / 2 - 100, 30, computerPlate);
  Rysownik.drawImage(width() / 2 - 100, height() - 60, userPlate);

}


gameWidget::gameWidget(QWidget* parent) :QWidget(parent) {
  //oknogry = new mainGameWidget(this);
  timer = new QTimer(this);
  accTime.setHMS(0, 0, 0);
  setupUi(this);
  // gameBox->addWidget(oknogry);
  pauzeGame->setText("Start");
  //pauzeGame->setObjectName(QStringLiteral("Start game"));

  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
  connect(pauzeGame, SIGNAL(clicked()), this, SLOT(writeTime()));
  connect(endGame, SIGNAL(clicked()), this, SLOT(EndGame()));
  connect(exitAplication, SIGNAL(clicked()), this, SLOT(EndProgram()));
}

mainWidget::mainWidget(gameWindow* parent) {
  QHBoxLayout* whZarzadzca = new QHBoxLayout;
  okienko = new mainGameWidget(this);
  statystyki = new gameWidget(this);
  okienko->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  okienko->setMinimumSize(500, 500);
  statystyki->setMinimumSize(250, 500);
  statystyki->setMaximumSize(250, 500);
  // statystyki->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
   // statystyki->move(400,30);
  // std::cout<<"tak";

  whZarzadzca->addWidget(okienko);
  //whZarzadzca->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));
  whZarzadzca->addWidget(statystyki);
  setLayout(whZarzadzca);

};


gameWindow::gameWindow(QMainWindow* parent) {
  setupUi(this);
  this->CentralWidget = new mainWidget(this);
  this->connectionDialog = new conDialog;
  this->device = new QSerialPort;
  this->disconnectionDialog = new disDialog();
  this->gameTimer=new QTimer(this);
  setCentralWidget(CentralWidget);
  // this->setGeometry(0, 0, 620, 410);
  // menuBar=new QMenuBar(this);
  // menuBar->setObjectName("menuBar");
  // menuBar->setGeometry(QRect(0, 0, 759, 22));
  // menuUstawienia=new QMenu(menuBar);
  // menuUstawienia->setObjectName(QStringLiteral("menu_Ustawienia"));
 // connect(gameTimer,SIGNAL(timeout()),this,callOnTimeout())
  connect(CentralWidget->statystyki, SIGNAL(EmitClosing()), this, SLOT(close()));
  //connect(this,SIGNAL(timeout()),CentralWidget->okienko,SLOT(CentralWidget->okienko.tak()));
  // connect(connectionDialog, SIGNAL(EmitClosing()), this, SLOT(close()));
  connect(connectionDialog, SIGNAL(EmitChoosenDev(QString)), this, SLOT(initDevice(QString)));
}


//slots
void gameWidget::EndProgram() {
  std::cout << std::endl << "Koniec programu" << std::endl;
  emit EmitClosing();
}
void gameWidget::updateTime() {
  accTime = accTime.addSecs(1);
  QString time_text = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
  //qDebug()<<time_text;
}

void gameWidget::writeTime() {
  if (isStarted) {
    pauzeGame->setText("Resume");
    timer->stop();
    isStarted = 0;
  }
  else {
    pauzeGame->setText("Pauze");
    timer->start(1000);
    isStarted = 1;
  }
}

void gameWidget::EndGame() {
  accTime.setHMS(0, 0, 0);
  QString time_text = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
  isStarted = 0;
  timer->stop();
}

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
    if (hexCRC8 == line.mid(pos2 + 1, pos1 - 1).trimmed())
      //std::cout<<str;
      qDebug() << lineWOHex;
    //  qDebug()<<line.left(line.length()-4);
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
    qDebug() << gameInfo.XVal << gameInfo.YVal << gameInfo.ZVal << "to sie wczytalo";
    gameInfo.calculateVel();
  }

}
void gameWindow::on_actionConnect_triggered() {

  connectionDialog->show();

}

void gameWindow::on_actionSettings_triggered() {
  close();
}
void gameWindow::on_actionDisconnect_triggered() {

  // QDialog *disconnectionDialog=new QDialog();
  //disconnectionDialog->StartDialog(gameInfo.devName)
  disconnectionDialog->show();

}
