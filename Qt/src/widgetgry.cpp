#include "inc/widgetgry.hpp"
#include <string>
#include "cstring"

disDialog::disDialog() {
  setupUi(this);


  //text->setReadOnly(true);
}

conDialog::conDialog() {
  setupUi(this);
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
  // devicesList.clear()

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
//void on_connectButton_clicked() {



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

mainWidget::mainWidget(QWidget* parent) {
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


gameWindow::gameWindow(QWidget* parent) {
  setupUi(this);
  this->CentralWidget = new mainWidget(this);
  setCentralWidget(CentralWidget);
  // this->setGeometry(0, 0, 620, 410);
  // menuBar=new QMenuBar(this);
  // menuBar->setObjectName("menuBar");
  // menuBar->setGeometry(QRect(0, 0, 759, 22));
  // menuUstawienia=new QMenu(menuBar);
  // menuUstawienia->setObjectName(QStringLiteral("menu_Ustawienia"));

  connect(CentralWidget->statystyki, SIGNAL(EmitClosing()), this, SLOT(close()));
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


void gameWindow::on_actionConnect_triggered() {
  conDialog* connectionDialog = new conDialog;
  connectionDialog->show();
}

void gameWindow::on_actionSettings_triggered() {
  close();
}
void gameWindow::on_actionDisconnect_triggered() {
  //QDialog *disconnectionDialog=new QDialog();
  disDialog* disconnecionDialog = new disDialog;
  disconnecionDialog->show();
}
