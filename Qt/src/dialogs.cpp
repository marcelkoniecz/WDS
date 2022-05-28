#include "dialogs.hpp"

settDialog::settDialog() {
  setupUi(this);
}

void settDialog::on_returnButton_clicked(){
  this->close();
}
void settDialog::on_saveButton_clicked() {
  this->close();
}


endDialog::endDialog() {
  setupUi(this);
}



void endDialog::on_statisticsButton_clicked() {
  emit EmitOpenStatistics();
  this->close();
}

void endDialog::on_restartButton_clicked() {
  emit EmitRestartGame();
  this->close();
}

void endDialog::on_exitButton_clicked() {
  emit  EmitClosing();
  this->close();
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