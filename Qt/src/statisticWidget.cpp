#include "statisticWidget.hpp"

gameWidget::gameWidget(QWidget* parent,QTimer* applTimer) :QWidget(parent) {
  //oknogry = new mainGameWidget(this);
  timer=applTimer;
  //timer = new QTimer(this);
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



//slots
void gameWidget::EndProgram() {
  std::cout << std::endl << "Koniec programu" << std::endl;
  emit EmitClosing();
}
void gameWidget::updateTime() {
  accTime=accTime.addMSecs(10);
  //accTime = accTime.addSecs(1);
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
    timer->start(10);
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

