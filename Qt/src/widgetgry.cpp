#include "inc/widgetgry.hpp"
#include <string>
#include "cstring"
/*
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
*/
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





