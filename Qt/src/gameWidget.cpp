#include "gameWidget.hpp"
#include <cmath>

inline
double Deg2Rad(double Ang_deg)
{
  return Ang_deg * M_PI / 180;
}

mainGameWidget::mainGameWidget(QWidget* parent, UARTVal* gameInformations, QTimer* appTimer, gameParameters* gameParamtr) :QWidget(parent) {
  background.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/tlo.png");
  computerPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  userPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  ball.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/circle.png");
  //life.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/zyciebez.png");
  gameTimer = appTimer;
  gameInfo = gameInformations;
  gameParame = gameParamtr;
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  initValues(1, 1);
  timerun = 0;
  //gameInfo->isGameActive = 1;
  //gameParam.currentAngle = 90;
}

void mainGameWidget::initValues(int comLives, int userLives) {

  gameParam.currentAngle = 90;
  gameInfo->isGameActive = true;
  gameParam.ballPos[0] = 200;
  gameParam.ballPos[1] = 200;
  gameParam.ballSpeed = 5;
  gameParam.plateSpeed = 3;
  gameParam.userLives = comLives;
  gameParam.compLives = userLives;

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
      timerun += 0.1;
      //qDebug()<<gameInfo->YVal<<timerun;
      //gameParame->accValues.append(gameInfo->YVal);
      gameParame->accValues.append(timerun,gameInfo->YVal);
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
      gameParam.currentAngle = rand() % 120 + 30;
      gameParam.currentAngle = gameParam.currentAngle * -1;
      //gameParam.ballSpeed=rand()%5;
    }
  }
  //Sprawdzenie czy od gornej plytki
  else {
    if (gameParam.comPlateLoc[0][0] < (gameParam.ballPos[0] + 29) &&
      (gameParam.ballPos[0] + 29) < gameParam.comPlateLoc[0][1] &&
      gameParam.comPlateLoc[1][0] + 50 > (gameParam.ballPos[1])) {
      gameParam.currentAngle = (rand() % 120 + 30);
      gameParam.currentAngle = gameParam.currentAngle;
    }

  }
}

void mainGameWidget::calculateComPlatePosition() {
  //Obliczenie gdzie bedzie w przyszlosci pilka

    //Przesuniecie platformy w to miejsce
  gameParam.comPlateLoc[0][0] = gameParam.ballPos[0] - 30;
  gameParam.comPlateLoc[0][1] = gameParam.ballPos[0] + 150;
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