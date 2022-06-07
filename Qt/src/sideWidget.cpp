#include "sideWidget.hpp"

SidePanelWidget::SidePanelWidget(mainWidget* parent, gameWindow* gameWin) {
  timer = parent->gameTimer;
  gamePar = &(gameWin->gameParam);
  gameUART = &(gameWin->gameInfo);

  accTime.setHMS(0, 0, 0);
  setupUi(this);
  //checkConnection();


  pauzeGame->setText("Start");
  lineEdit->setReadOnly(true);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
  connect(pauzeGame, SIGNAL(clicked()), this, SLOT(writeTime()));
  connect(endGame, SIGNAL(clicked()), this, SLOT(EndGame()));
  connect(exitAplication, SIGNAL(clicked()), this, SLOT(EndProgram()));
  connect(gameWin, SIGNAL(EmitRestartGame()), this, SLOT(setTimerNull()));
  connect(gameWin, SIGNAL(EmitRetranslate()), this, SLOT(retranslatePanel()));
  connect(gameWin, SIGNAL(EmitBlockButtons()), this, SLOT(checkBlockButtons()));
}

void SidePanelWidget::checkBlockButtons() {
  if (gamePar->blockButtons) {
    pauzeGame->setEnabled(false);
    endGame->setEnabled(false);
  }
  else {
    pauzeGame->setEnabled(true);
    endGame->setEnabled(true);
  }
}

void SidePanelWidget::retranslatePanel() {
  retranslateUi(this);
}
//slots
void SidePanelWidget::EndProgram() {
  std::cout << std::endl << "Koniec programu" << std::endl;
  emit EmitClosing();
}
void SidePanelWidget::updateTime() {
  //checkConnection();
  accTime = accTime.addMSecs(10);
  //accTime = accTime.addSecs(1);
  QString time_text = accTime.toString("hh:mm:ss");
  gamePar->gameTime = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
  //qDebug()<<time_text;
}
//void SidePanelWidget::checkNewGame(){
  //if(gamePar->resetPosition)
//}

void SidePanelWidget::checkConnection() {
  if ((gameUART->isConnected))
    pauzeGame->setEnabled(true);
  else
    pauzeGame->setEnabled(false);
}

void SidePanelWidget::writeTime() {
  checkBlockButtons();
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

void SidePanelWidget::setTimerNull() {
  accTime.setHMS(0, 0, 0);
  QString time_text = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
}


void SidePanelWidget::EndGame() {
  setTimerNull();
  isStarted = 0;
  timer->stop();
  emit EmitEndGame();
  checkBlockButtons();
}

