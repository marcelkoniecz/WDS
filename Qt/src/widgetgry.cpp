#include "inc/widgetgry.hpp"
#include <string>
#include "cstring"

mainGameWidget::mainGameWidget(QWidget* parent) :QWidget(parent) {
  background.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/tlo.png");
  computerPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  userPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  // this->resize(1000,200);
  //  QPainter  Rysownik(this);
   // QRectF target(10.0,20.0,80.0,60.0);
   // QRectF source(0.0,0.0,70.0,40.0);
   // QLine line(10.0,80.0,90.0,20.0);
   // Rysownik.drawImage(target,background,source);
   //Rysownik.drawLine(line);
}
void mainGameWidget::paintEvent(QPaintEvent*) {
  QPainter  Rysownik(this);
  Rysownik.drawImage(0, 0, background);
  Rysownik.drawImage(75, 30, computerPlate);
  Rysownik.drawImage(75, 300, userPlate);
  // Rysownik.drawImage(target,background,source);
//  Rysownik.drawLine(line);
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


gameWindow::gameWindow(QWidget* parent) {
  this->CentralWidget = new gameWidget(this);
  setCentralWidget(CentralWidget);
  this->setGeometry(0, 0, 700, 500);

  connect(CentralWidget, SIGNAL(EmitClosing()), this, SLOT(close()));
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

void gameWidget::EndGame() {
  accTime.setHMS(0, 0, 0);
  QString time_text = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
  isStarted = 0;
  timer->stop();
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
