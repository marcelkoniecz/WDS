#include "dialogs.hpp"

settDialog::settDialog(gameWindow* parent) {
  ptrGameSett = &(parent->gameSett);
  setupUi(this);
  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}
void settDialog::retranslate() {
  retranslateUi(this);
}

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


void settDialog::on_returnButton_clicked() {
  if (!ptrGameSett->rndBcnPlts) {
    bouncingCheck->setCheckState(Qt::Unchecked);
  }
  if (!ptrGameSett->randomBallSpeed) {
    vellCheck->setCheckState(Qt::Unchecked);
  }
  this->close();
}

void settDialog::on_saveButton_clicked() {
  //static QTranslator *PLTranslator = new QTranslator();

  ptrGameSett->language = applicationLanguage(languageBox->currentIndex());
  // //switch(ptrGameSett){
  //   case english:

  //   break;
  //   case polish:

  //   break;
  // }

  ptrGameSett->lifes = (lifeBox->currentIndex() + 1);
  ptrGameSett->gamelvl = gameDifficulty(levelBox->currentIndex());
  emit EmitSettingsSaved();
  this->close();
}







endDialog::endDialog(gameWindow *parent) {
   
  setupUi(this);
  connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}
void endDialog::retranslate() {
  retranslateUi(this);
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




conDialog::conDialog(gameWindow *parent) {
  setupUi(this);
  connectButton->setEnabled(false);
  // connect(this,SIGNAL(EmitChooseDev(QString)),parent->centralWidget->okienko,initDevice(QString aa));
 //connect(searchDeviceButton, SIGNAL(clicked()), this, SLOT(searchDev()));
// connect(connectButton, SIGNAL(clicked()), this, SLOT(chooseDev()));
connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
}
//void condDialog::chooseDev(){
//}
void conDialog::retranslate() {
  retranslateUi(this);
}

void conDialog::on_cancelButton_clicked() {
  this->close();

}

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
    //qDebug() << devices.at(devNum).portName() << devices.at(devNum).description();
    //if (devices.at(devNum).description() == "STM32 STLink")
     // break;
  }
}

void conDialog::on_connectButton_clicked() {
  if (devicesList->itemText(devicesList->currentIndex()) == "No devices to connect") {
    this->close();
    return;
  }

  QSerialPort tmpDev;
  QString portName = portList.at(devicesList->currentIndex()).portName();
  //qDebug()<<portName;
  //devicesList->currentIndex();
  emit EmitChoosenDev(portName);
  this->close();
}





disDialog::disDialog(gameWindow *parent) {
  setupUi(this);
  lineEdit->setReadOnly(true);
//  lineEdit->setText(connectedDev);
connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));
  //text->setReadOnly(true);
}
void disDialog::retranslate() {
  retranslateUi(this);
}
void disDialog::StartDialog(QString connectedDev) {
  lineEdit->setText(connectedDev);
  if (connectedDev == "No device to connect" || connectedDev == "") {
    lineEdit->setText("No device to connect");
    disconnectButton->setEnabled(false);
  }
  else
    disconnectButton->setEnabled(true);
}

void disDialog::on_disconnectButton_clicked() {
  emit EmitDisconnectDevice();
  this->close();
}

void disDialog::on_cancelButton_clicked() {
  this->close();
}