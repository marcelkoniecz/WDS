#include "gameWindow.hpp"
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

gameWindow::gameWindow(QMainWindow* parent) {
  setupUi(this);
  this->CentralWidget = new mainWidget(this,&gameInfo);
  this->connectionDialog = new conDialog;
  this->device = new QSerialPort;
  this->disconnectionDialog = new disDialog();
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
   // if (hexCRC8 == line.mid(pos2 + 1, pos1 - 1).trimmed())
      //std::cout<<str;
     // qDebug() << lineWOHex;
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
    //qDebug() << gameInfo.XVal << gameInfo.YVal << gameInfo.ZVal << "to sie wczytalo";
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