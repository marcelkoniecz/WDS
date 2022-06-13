#include "gameWidget.hpp"
#include <cmath>

inline
double Deg2Rad(double Ang_deg)
{
  return Ang_deg * M_PI / 180;
}

//mainGameWidget::mainGameWidget(QWidget* parent, UARTVal* gameInformations, QTimer* appTimer, gameParameters* gameParamtr) :QWidget(parent) {
mainGameWidget::mainGameWidget(mainWidget* parent, gameWindow* gameWin) {
  background.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/tlo.png");
  computerPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  userPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  ball.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/circle.png");
  //life.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/zyciebez.png");
  gameTimer = parent->gameTimer;
  gameInfo = &(gameWin->gameInfo);
  gameParam = &(gameWin->gameParam);
  gameSettgs = &(gameWin->gameSett);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  initValues();
  timerun = 0;
  gameParam->averageBallVel = imgParam.ballSpeed;

  //gameInfo->isGameActive = 1;
  //imgParam.currentAngle = 90;
}

void mainGameWidget::initValues() {
  gameParam->isGameActive = true;
  imgParam.ballSpeed = 5;
  imgParam.plateSpeed = 3;
  imgParam.remainingCompLives = gameSettgs->lifes;
  imgParam.remainingUserLives = gameSettgs->lifes;
  gameParam->ballBounceNumber = 0;
  gameParam->averageBallVel = imgParam.ballSpeed;
  timerun = 0;
}

void mainGameWidget::resetPosition() {
  imgParam.currentAngle = 90;
  imgParam.ballPos[0] = (width() / 2 - 50);
  imgParam.ballPos[1] = (height() / 2 - 30);
  imgParam.userPlateLoc[0][0] = (width() / 2 - 100);
  imgParam.userPlateLoc[1][0] = height() - 60;
  imgParam.userPlateLoc[0][1] = (width() / 2 - 100) + 180;
  imgParam.userPlateLoc[1][1] = height() - 60;
  imgParam.comPlateLoc[0][0] = (width() / 2 - 100);
  imgParam.comPlateLoc[1][0] = 30;
  imgParam.comPlateLoc[0][1] = (width() / 2 - 100) + 180;
  imgParam.comPlateLoc[1][1] = 30;
}

void mainGameWidget::updateTime() {

  if (gameParam->resetPosition) {
    initValues();
    resetPosition();
    gameParam->resetPosition = false;
  }
  this->makeGameStep();
  update();
}

void mainGameWidget::makeGameStep() {
  calculateUserPlate();
  calculateBallPosition();
  calculateIfEndGame();
  calculateIfBouncedWall();
  calculateIfBouncedPlate();
  calculateComPlatePosition();
}

void mainGameWidget::calculateUserPlate() {
  if (gameParam->isGameActive) {
    if (imgParam.userPlateLoc[0][0] + gameInfo->YVal + 120 < width() - 60 &&
      imgParam.userPlateLoc[0][0] + gameInfo->YVal > 0) {
      timerun += 0.01;
      gameParam->accValues.append(timerun, gameInfo->YVal);
      imgParam.userPlateLoc[0][0] += gameInfo->YVal;
      imgParam.userPlateLoc[0][1] += gameInfo->YVal;
    }
  }
}



void mainGameWidget::calculateBallPosition() {

  double angRad = Deg2Rad(imgParam.currentAngle);
  double sn = sin(angRad), cs = cos(angRad);
  imgParam.ballPos[1] = imgParam.ballPos[1] + imgParam.ballSpeed * sn;
  imgParam.ballPos[0] = imgParam.ballPos[0] + imgParam.ballSpeed * cs;

}

void mainGameWidget::calculateIfEndGame() {
  //Sprawdzenie czy na gorze
  if (imgParam.currentAngle > 0) {
    if (imgParam.ballPos[1] > (height() - 60)) {
      if (imgParam.remainingUserLives > 1) {
        imgParam.remainingUserLives--;
        resetPosition();
        emit EmitPauzeGame();
        return;
      }
      gameTimer->stop();
      gameParam->isGameActive = false;
      emit EmitEndGame();
    }
  }
  else {
    if (imgParam.ballPos[1] < 30) {
      if (imgParam.remainingCompLives > 1) {
        imgParam.remainingCompLives--;
        resetPosition();
        emit EmitPauzeGame();
        return;
      }
      gameTimer->stop();
      gameParam->isGameActive = false;
      emit EmitEndGame();
    }
  }
}
void mainGameWidget::calculateIfBouncedWall() {
  // Sprawdzenie Odbicie lewa sciana
  if (imgParam.ballPos[0] < 0 && imgParam.currentAngle < 0) {//Do gory
    imgParam.ballPos[0] = 0;
    imgParam.currentAngle = -180 - imgParam.currentAngle;
  }
  else if (imgParam.ballPos[0] < 0 && imgParam.currentAngle>0) {//W dol
    imgParam.ballPos[0] = 0;
    imgParam.currentAngle = 180 - imgParam.currentAngle;
  }
  //Sprawdzenie Odbicie prawa sciana
  if (imgParam.ballPos[0] > (width() - 55) && imgParam.currentAngle < 0) {
    imgParam.ballPos[0] = width() - 55;
    imgParam.currentAngle = -180 - imgParam.currentAngle;
  }
  else if (imgParam.ballPos[0] > (width() - 55) && imgParam.currentAngle > 0) {//W dol
    imgParam.ballPos[0] = width() - 55;
    imgParam.currentAngle = 180 - imgParam.currentAngle;
  }
}

void mainGameWidget::calculateIfBouncedPlate() {
  //Sprawdzenie czy od od dolnej plytki

  if (imgParam.currentAngle > 0) {
    if (imgParam.userPlateLoc[0][0] < (imgParam.ballPos[0] + 29) &&
      (imgParam.ballPos[0] + 29) < imgParam.userPlateLoc[0][1] &&
      imgParam.userPlateLoc[1][0] < (imgParam.ballPos[1] + 55)) {
      if (gameSettgs->rndBcnPlts) {
        imgParam.currentAngle = (rand() % 120 + 30);
        imgParam.currentAngle = imgParam.currentAngle * -1;
      }
      else {
        if (gameInfo->YVal > 0.5 || gameInfo->YVal < -0.5) {
          imgParam.currentAngle = (gameInfo->YVal * imgParam.currentAngle * 4) / 10;
          if (imgParam.currentAngle < -140)
            imgParam.currentAngle = -140;
          else if (imgParam.currentAngle > -40)
            imgParam.currentAngle = -40;
        }
        else {
          imgParam.currentAngle = imgParam.currentAngle * -1;
        }
      }
      gameParam->ballBounceNumber++;

      if (gameSettgs->randomBallSpeed) {
        imgParam.ballSpeed = (rand() % 7 + 3);
      }
      else if (gameParam->setBallSpeed != 0) {

        if (gameParam->setBallSpeed > 0) {
          imgParam.ballSpeed = imgParam.ballSpeed * 1.5;
          if (imgParam.ballSpeed > 10)
            imgParam.ballSpeed = 10;
        }
        else {
          imgParam.ballSpeed = imgParam.ballSpeed * 0.75;
          if (imgParam.ballSpeed < 3)
            imgParam.ballSpeed = 3;
        }
        gameParam->setBallSpeed = 0;
      }
      gameParam->ballBounceNumber++;
      //  qDebug()<<"Przed "<<gameParam->averageBallVel;
      gameParam->averageBallVel = (gameParam->averageBallVel * gameParam->ballBounceNumber + imgParam.ballSpeed) / (gameParam->ballBounceNumber+1);
    //  qDebug()<<gameParam->averageBallVel;
      //      qDebug()<<"Po "<<gameParam->averageBallVel;
    }
  }
  //Sprawdzenie czy od gornej plytki
  else {
    if (imgParam.comPlateLoc[0][0] < (imgParam.ballPos[0] + 29) &&
      (imgParam.ballPos[0] + 29) < imgParam.comPlateLoc[0][1] &&
      imgParam.comPlateLoc[1][0] + 50 > (imgParam.ballPos[1])) {
      if (gameSettgs->rndBcnPlts) {
        imgParam.currentAngle = (rand() % 120 + 30);
      }
      else {
        imgParam.currentAngle = -1 * imgParam.currentAngle;
      }
      gameParam->ballBounceNumber++;
      if (gameSettgs->randomBallSpeed) {
        imgParam.ballSpeed = (rand() % 7 + 3);
      }
    //  qDebug()<<(gameParam->ballBounceNumber);
      qDebug()<<gameParam->averageBallVel ;
      gameParam->averageBallVel = (gameParam->averageBallVel * gameParam->ballBounceNumber + imgParam.ballSpeed) / (gameParam->ballBounceNumber+1);
      qDebug()<<gameParam->averageBallVel ;

    }

  }
}



void mainGameWidget::calculateComPlatePosition() {
  //Obliczenie gdzie bedzie w przyszlosci pilka


  switch (gameSettgs->gamelvl) {
  case easy:
    imgParam.plateSpeed = width() * 0.00165 + height() * 0.0005;
    qDebug() << imgParam.plateSpeed;
    break;
  case medium:
    imgParam.plateSpeed = width() * 0.002 + height() * 0.00065;
    break;
  case hard:
    imgParam.plateSpeed = width() * 0.0023 + height() * 0.00085;

    break;

  }

  imgParam.XtargetComPlate = imgParam.ballPos[0] - 70;
  // qDebug() << imgParam.ballPos[0] - 30;
  if (abs(imgParam.XtargetComPlate - imgParam.comPlateLoc[0][0]) < imgParam.plateSpeed &&
    imgParam.comPlateLoc[0][1] < width() && imgParam.comPlateLoc[0][0]>0){
  imgParam.comPlateLoc[0][0] = imgParam.XtargetComPlate;
  imgParam.comPlateLoc[0][1] = imgParam.XtargetComPlate + 180;
  }

  if (imgParam.XtargetComPlate > imgParam.comPlateLoc[0][0] &&
    imgParam.comPlateLoc[0][1] < width())
  {
    imgParam.comPlateLoc[0][0] += imgParam.plateSpeed;
    imgParam.comPlateLoc[0][1] += imgParam.plateSpeed;
  }
  else if (imgParam.XtargetComPlate < imgParam.comPlateLoc[0][0]
    && imgParam.comPlateLoc[0][0]>0) {

    imgParam.comPlateLoc[0][0] -= imgParam.plateSpeed;
    imgParam.comPlateLoc[0][1] -= imgParam.plateSpeed;

  }

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
  Rysownik.scale(Skala, Skala);
  Rysownik.drawImage(0, 0, background);
  Rysownik.scale(1 / Skala, 1 / Skala);

  if (imgParam.newScala != Skala) {
    Rysownik.drawImage(width() / 2 - 100, 30, computerPlate);
    Rysownik.drawImage(width() / 2 - 100, height() - 60, userPlate);
    resetPosition();
    imgParam.newScala = Skala;
  }
  Rysownik.drawImage(100, 100, life);
  Rysownik.drawImage(imgParam.ballPos[0], imgParam.ballPos[1], ball);
  Rysownik.drawImage(imgParam.userPlateLoc[0][0], imgParam.userPlateLoc[1][0], userPlate);
  Rysownik.drawImage(imgParam.comPlateLoc[0][0], imgParam.comPlateLoc[1][0], computerPlate);
}