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
  gameParame = &(gameWin->gameParam);
  gameSettgs = &(gameWin->gameSett);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  initValues(1, 1);
  timerun = 0;
  gameParame->averageBallVel = gameParam.ballSpeed;

  //gameInfo->isGameActive = 1;
  //gameParam.currentAngle = 90;
}

void mainGameWidget::initValues(int comLives, int userLives) {

  gameParam.currentAngle = 90;
  gameInfo->isGameActive = true;
  gameParam.ballPos[0] = (width() / 2 - 50);
  gameParam.ballPos[1] = (height() / 2);
  gameParam.ballSpeed = 5;
  gameParam.plateSpeed = 3;
  // gameParam.userLives = comLives;
 //  gameParam.compLives = userLives;
  gameParame->ballBounceNumber = 0;
  gameParame->averageBallVel = gameParam.ballSpeed;
  timerun = 0;
}



void mainGameWidget::updateTime() {

  if (gameInfo->resetPosition) {
    initValues(1, 1);
    gameInfo->resetPosition = false;
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
  if (gameInfo->isGameActive) {
    if (gameParam.userPlateLoc[0][0] + gameInfo->YVal + 120 < width() - 60 &&
      gameParam.userPlateLoc[0][0] + gameInfo->YVal > 0) {
      timerun += 0.01;
      //qDebug()<<gameInfo->YVal<<timerun;
      //gameParame->accValues.append(gameInfo->YVal);
      gameParame->accValues.append(timerun, gameInfo->YVal);
      //(gameParame->accValues)<<QPointF(gameInfo->YVal,timerun);
      gameParam.userPlateLoc[0][0] += gameInfo->YVal;
      gameParam.userPlateLoc[0][1] += gameInfo->YVal;
    }
  }
}



void mainGameWidget::calculateBallPosition() {

  double angRad = Deg2Rad(gameParam.currentAngle);
  double sn = sin(angRad), cs = cos(angRad);
  gameParam.ballPos[1] = gameParam.ballPos[1] + gameParam.ballSpeed * sn;
  gameParam.ballPos[0] = gameParam.ballPos[0] + gameParam.ballSpeed * cs;

}

void mainGameWidget::calculateIfEndGame() {
  //Sprawdzenie czy na gorze
  if (gameParam.currentAngle > 0) {
    if (gameParam.ballPos[1] > (height() - 60)) {
      qDebug() << "Koniec";
      gameTimer->stop();
      gameInfo->isGameActive = false;
      emit EmitEndGame();
    }
  }
  else {
    if (gameParam.ballPos[1] < 30) {
      qDebug() << "Koniec2";
      gameTimer->stop();
      gameInfo->isGameActive = false;
      emit EmitEndGame();
    }
  }
}
void mainGameWidget::calculateIfBouncedWall() {
  // Sprawdzenie Odbicie lewa sciana
  if (gameParam.ballPos[0] < 0 && gameParam.currentAngle < 0) {//Do gory
    gameParam.ballPos[0] = 0;
    gameParam.currentAngle = -180 - gameParam.currentAngle;
  }
  else if (gameParam.ballPos[0] < 0 && gameParam.currentAngle>0) {//W dol
    gameParam.ballPos[0] = 0;
    gameParam.currentAngle = 180 - gameParam.currentAngle;
  }
  //Sprawdzenie Odbicie prawa sciana
  if (gameParam.ballPos[0] > (width() - 55) && gameParam.currentAngle < 0) {
    gameParam.ballPos[0] = width() - 55;
    gameParam.currentAngle = -180 - gameParam.currentAngle;
  }
  else if (gameParam.ballPos[0] > (width() - 55) && gameParam.currentAngle > 0) {//W dol
    gameParam.ballPos[0] = width() - 55;
    gameParam.currentAngle = 180 - gameParam.currentAngle;
  }
}

void mainGameWidget::calculateIfBouncedPlate() {
  //Sprawdzenie czy od od dolnej plytki

  if (gameParam.currentAngle > 0) {
    if (gameParam.userPlateLoc[0][0] < (gameParam.ballPos[0] + 29) &&
      (gameParam.ballPos[0] + 29) < gameParam.userPlateLoc[0][1] &&
      gameParam.userPlateLoc[1][0] < (gameParam.ballPos[1] + 55)) {
      if (gameSettgs->rndBcnPlts) {
        gameParam.currentAngle = (rand() % 120 + 30);
        gameParam.currentAngle = gameParam.currentAngle * -1;
      }
      else {
        if (gameInfo->YVal > 0.5 || gameInfo->YVal < -0.5) {
          gameParam.currentAngle = (gameInfo->YVal * gameParam.currentAngle * 4) / 10;
          if (gameParam.currentAngle < -140)
            gameParam.currentAngle = -140;
          else if (gameParam.currentAngle > -40)
            gameParam.currentAngle = -40;
        }
        else {
          gameParam.currentAngle = gameParam.currentAngle * -1;
        }
      }
      gameParame->ballBounceNumber++;

      if (gameSettgs->randomBallSpeed) {
        gameParam.ballSpeed = (rand() % 7 + 3);
      }
      else if (gameParame->setBallSpeed != 0) {

        if (gameParame->setBallSpeed > 0) {
          gameParam.ballSpeed = gameParam.ballSpeed * 1.5;
          if (gameParam.ballSpeed > 10)
            gameParam.ballSpeed = 10;
        }
        else {
          gameParam.ballSpeed = gameParam.ballSpeed * 0.75;
          if (gameParam.ballSpeed < 3)
            gameParam.ballSpeed = 3;
        }
        gameParame->setBallSpeed = 0;
      }
      gameParame->ballBounceNumber++;
    //  qDebug()<<"Przed "<<gameParame->averageBallVel;
      gameParame->averageBallVel = (gameParame->averageBallVel * timerun * 100 + gameParam.ballSpeed) / (timerun * 100+1);
      //      qDebug()<<"Po "<<gameParame->averageBallVel;
    }
  }
  //Sprawdzenie czy od gornej plytki
  else {
    if (gameParam.comPlateLoc[0][0] < (gameParam.ballPos[0] + 29) &&
      (gameParam.ballPos[0] + 29) < gameParam.comPlateLoc[0][1] &&
      gameParam.comPlateLoc[1][0] + 50 > (gameParam.ballPos[1])) {
      if (gameSettgs->rndBcnPlts) {
        gameParam.currentAngle = (rand() % 120 + 30);
      }
      else {
        gameParam.currentAngle = -1 * gameParam.currentAngle;
      }
      gameParame->ballBounceNumber++;
      if (gameSettgs->randomBallSpeed) {
        gameParam.ballSpeed = (rand() % 7 + 3);
      }
      gameParame->averageBallVel = (gameParame->averageBallVel * timerun * 100 + gameParam.ballSpeed) / (timerun * 100);

    }

  }
}



void mainGameWidget::calculateComPlatePosition() {
  //Obliczenie gdzie bedzie w przyszlosci pilka

   /* //Przesuniecie platformy w to miejsce
  gameParam.comPlateLoc[0][0] = gameParam.ballPos[0] - 30;
  gameParam.comPlateLoc[0][1] = gameParam.ballPos[0] + 150;*/

  switch (gameSettgs->gamelvl) {
  case easy:
    gameParam.plateSpeed = width() * 0.00165 + height() * 0.0005;
    qDebug() << gameParam.plateSpeed;
    break;
  case medium:
    gameParam.plateSpeed = width() * 0.002 + height() * 0.00065;
    break;
  case hard:
    gameParam.plateSpeed = width() * 0.0023 + height() * 0.00085;

    break;

  }

  gameParam.XtargetComPlate = gameParam.ballPos[0] - 70;
  // qDebug() << gameParam.ballPos[0] - 30;
  if (gameParam.XtargetComPlate >= gameParam.comPlateLoc[0][0] &&
    gameParam.comPlateLoc[0][1] < width())
  {
    gameParam.comPlateLoc[0][0] += gameParam.plateSpeed;
    gameParam.comPlateLoc[0][1] += gameParam.plateSpeed;
  }
  else if (gameParam.XtargetComPlate < gameParam.comPlateLoc[0][0]
    && gameParam.comPlateLoc[0][0]>0) {

    gameParam.comPlateLoc[0][0] -= gameParam.plateSpeed;
    gameParam.comPlateLoc[0][1] -= gameParam.plateSpeed;

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

  if (gameParam.newScala != Skala) {
    Rysownik.drawImage(width() / 2 - 100, 30, computerPlate);
    Rysownik.drawImage(width() / 2 - 100, height() - 60, userPlate);
    gameParam.userPlateLoc[0][0] = (width() / 2 - 100);
    gameParam.userPlateLoc[1][0] = height() - 60;
    gameParam.userPlateLoc[0][1] = (width() / 2 - 100) + 180;
    gameParam.userPlateLoc[1][1] = height() - 60;
    gameParam.comPlateLoc[0][0] = (width() / 2 - 100);
    gameParam.comPlateLoc[1][0] = 30;
    gameParam.comPlateLoc[0][1] = (width() / 2 - 100) + 180;
    gameParam.comPlateLoc[1][1] = 30;
    gameParam.newScala = Skala;
  }
  Rysownik.drawImage(100, 100, life);
  Rysownik.drawImage(gameParam.ballPos[0], gameParam.ballPos[1], ball);
  Rysownik.drawImage(gameParam.userPlateLoc[0][0], gameParam.userPlateLoc[1][0], userPlate);
  Rysownik.drawImage(gameParam.comPlateLoc[0][0], gameParam.comPlateLoc[1][0], computerPlate);
}