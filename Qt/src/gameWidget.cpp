#include "gameWidget.hpp"
#include <cmath>

inline
double Deg2Rad(double Ang_deg)
{
  return Ang_deg * M_PI / 180;
}


void imageParameters::calculatePosition(double const angle) {
  double angRad = Deg2Rad(angle);
  double sn = sin(angRad), cs = cos(angRad);
  double tmp[2] = { ballPos[0],ballPos[1] };
  //ballPos[0] = tmp[0] + (tmp[0] * cs - tmp[1] * sn);
  //ballPos[1] = tmp[1] + (tmp[0] * sn + tmp[1] * cs);
  //ballPos[0] = tmp[0] + (ballSpeed * cs - ballSpeed * sn);
  //ballPos[1] = tmp[1] + (ballSpeed * sn + ballSpeed * cs);
  //ballPos[1] = tmp[0] + ballSpeed * sn;
  //ballPos[0] = tmp[1] + ballSpeed * cs;
  ballPos[1] = ballPos[1] + ballSpeed * sn;
  ballPos[0] = ballPos[0] + ballSpeed * cs;
  // qDebug()<<(ballSpeed * sn );
 // qDebug()<<(ballSpeed * sn)<<(ballSpeed * cs);
   //qDebug()<<ballPos[0]<<ballPos[1];

}


//Sprawdzenie czy pilka sie odbije od plytki
bool imageParameters::calculateIfBounced(bool turn, int height, volatile gameParameters* game) {
  if (game->ballDirection) {
    //qDebug() << userPlateLoc[0][0] << ballPos[0] << userPlateLoc[0][1];
    qDebug() << userPlateLoc[1][0] << (ballPos[1] + 30);
    if (userPlateLoc[0][0] < (ballPos[0] + 29) &&
      (ballPos[0] + 20) < userPlateLoc[0][1] &&
      userPlateLoc[1][0] < (ballPos[1] + 60)) {
      game->ballDirection = -1;
      return true;
    }
    else {
      return false;
    }
  }
  else {
    if (comPlateLoc[0][0]<ballPos[0] &&
      comPlateLoc[0][1]>ballPos[0] &&
      comPlateLoc[1][0] > ballPos[1]) {
      game->ballDirection = 1;
      return true;
    }
    else
      return false;
  }
}





mainGameWidget::mainGameWidget(QWidget* parent, gameParameters* gameInformations, QTimer* appTimer) :QWidget(parent) {
  background.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/tlo.png");
  computerPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  userPlate.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/plytka.png");
  ball.load("/home/marcel/Documents/semestrVI/WDS/Qt/res/img/circle.png");
  // background=background.scaled(500,Qt::IgnoreAspectRatio);
  gameTimer = appTimer;
  gameInfo = gameInformations;
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  gameInfo->isGameActive = 1;
  gameParam.currentAngle = 90;
  // update();
   /*gameParam.userPlateLoc[0][0] = (width() / 2 - 25);
   gameParam.userPlateLoc[1][0] = height() - 60;
   gameParam.userPlateLoc[0][1] = (width() / 2 - 25) + 180;
   gameParam.userPlateLoc[1][1] = height() - 60;

   gameParam.comPlateLoc[0][0] = (width() / 2 - 25);
   gameParam.comPlateLoc[1][0] = 60;
   gameParam.comPlateLoc[0][1] = (width() / 2 - 25) + 180;
   gameParam.comPlateLoc[1][1] = 60;
  qDebug()<< gameParam.userPlateLoc[0][0];
  qDebug()<<width();*/
}

void mainGameWidget::updateTime() {
  this->makeGameStep();
  //this->calBal();
  update();
}

void mainGameWidget::makeGameStep() {
  /*  gameParam.userPlateLoc[0][0] = (width() / 2 - 100);
    gameParam.userPlateLoc[1][0] = height() - 60;
    gameParam.userPlateLoc[0][1] = (width() / 2 - 100) + 100;
    gameParam.userPlateLoc[1][1] = height() - 60;
    gameParam.comPlateLoc[0][0] = (width() / 2 - 100);
    gameParam.comPlateLoc[1][0] = 60;
    gameParam.comPlateLoc[0][1] = (width() / 2 - 100) + 100;
    gameParam.comPlateLoc[1][1] = 60;*/

    //przesuniecie pilki
    //sprawdzenie koniec gry
    //sprawdzenie odbicia od sciany
    //sprawdzenie odbicia od plytki
    //przesuniecie plytki komputera
  calculateUserPlate();
  calculateBallPosition();
  calculateIfEndGame();
  // qDebug() << "Aktualny kat" << gameParam.currentAngle;
  calculateIfBouncedWall();
  // qDebug() << "Aktualny kat 2" << gameParam.currentAngle;
  calculateIfBouncedPlate();
  calculateComPlatePosition();

}
void mainGameWidget::calculateUserPlate() {
  if (gameInfo->isGameActive) {
    if (gameParam.userPlateLoc[0][0] + gameInfo->YVal + 120 < width() - 60 &&
      gameParam.userPlateLoc[0][0] + gameInfo->YVal > 0) {
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
    if (gameParam.ballPos[1] > (height() - 60))
      qDebug() << "Koniec";
    //gameEnd();

  }
  else {
    if (gameParam.ballPos[1] < 30) {
      int x;
      std::cin >> x;
      qDebug() << "Koniec 2";
    }
    // gameEnd();
  }
  //Sprawdzenie czy na dole

}
void mainGameWidget::calculateIfBouncedWall() {
  // Sprawdzenie Odbicie lewa sciana
  //qDebug() << "Aktualny kat" << gameParam.currentAngle;
  // qDebug() << "Aktualny kat" <<ballCoo[0] << (width() - 60);
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
    //qDebug() << (gameParam.ballPos[0] + 29) << gameParam.userPlateLoc[0][1];

    if (gameParam.userPlateLoc[0][0] < (gameParam.ballPos[0] + 29) &&
      (gameParam.ballPos[0] + 29) < gameParam.userPlateLoc[0][1] &&
      gameParam.userPlateLoc[1][0] < (gameParam.ballPos[1] + 55)) {
      gameParam.currentAngle = rand() % 120 + 30;
      gameParam.currentAngle = gameParam.currentAngle * -1;
      qDebug() << "NIE";
      //gameParam.ballSpeed=rand()%5;
    }
  }
  //Sprawdzenie czy od gornej plytki
  else {
    qDebug() << gameParam.comPlateLoc[0][0] << (gameParam.ballPos[0] + 29);
    qDebug() << (gameParam.ballPos[0] + 29) << gameParam.comPlateLoc[0][1];
    qDebug() << (gameParam.comPlateLoc[1][0] + 50) << (gameParam.ballPos[1]);

    if (gameParam.comPlateLoc[0][0] < (gameParam.ballPos[0] + 29) &&
      (gameParam.ballPos[0] + 29) < gameParam.comPlateLoc[0][1] &&
      gameParam.comPlateLoc[1][0] + 50 > (gameParam.ballPos[1])) {
      gameParam.currentAngle = (rand() % 120 + 30);
      gameParam.currentAngle = gameParam.currentAngle;
      qDebug() << "TAK";
    }

  }
}

void mainGameWidget::calculateComPlatePosition() {
  //Obliczenie gdzie bedzie w przyszlosci pilka
 /* if (gameParam.currentAngle > -90 && gameParam.currentAngle < 0) {
    gameParam.XtargetComPlate = (tan(gameParam.currentAngle)*(width()-55-gameParam.ballPos[0])-)/
    (tan())

  }
  else if (gameParam.currentAngle > -180 && gameParam.currentAngle < -90)
    gameParam.XtargetComPlate =*/

    //Przesuniecie platformy w to miejsce
  gameParam.comPlateLoc[0][0] = gameParam.ballPos[0] - 30;
  gameParam.comPlateLoc[0][1] = gameParam.ballPos[0] + 150;
}

/*
void mainGameWidget::calBal() {
  bool temp;
  imageInfo.userPlateLoc[0][0] = (width() / 2 - 100);
  imageInfo.userPlateLoc[1][0] = height() - 60;
  imageInfo.userPlateLoc[0][1] = (width() / 2 - 100) + 100;
  imageInfo.userPlateLoc[1][1] = height() - 60;
  imageInfo.calculatePosition(gameInfo->ballDirection * 90);
  ballCoo[0] = imageInfo.ballPos[0];
  ballCoo[1] = imageInfo.ballPos[1];
  temp = imageInfo.calculateIfBounced(1, height(), gameInfo);
  qDebug() << temp;
  /*double tmp[2] = { ballCoo[0],ballCoo[1] };

  if (gameInfo->ballDirection) {
    qDebug() << height();
    if (ballCoo[1] > (height() - 113)) {
      ballPCoo[1] += 2 * (ballCoo[1] - ballPCoo[1]);
      gameInfo->ballDirection = 0;
      return;
    }
    ballCoo[0] += ballCoo[0] - ballPCoo[0];
    ballCoo[1] += ballCoo[1] - ballPCoo[1];
    ballPCoo[0] = tmp[0];
    ballPCoo[1] = tmp[1];
    //qDebug() << "przed" << ballCoo[1]<<(double)ballPCoo[1];
    std::cout << ballCoo[1] << " " << ballPCoo[1] << std::endl;
  }
  else {
    if (ballCoo[1] < 58)
    {
      qDebug() << "przed" << ballPCoo[1];
      gameInfo->ballDirection = 1;
      ballPCoo[1] += 2 * (ballCoo[1] - ballPCoo[1]);

      //qDebug()<< ballCoo[1]<<ballPCoo[1];
      return;
    }
    //qDebug() << "przed" << ballCoo[0] << ballCoo[1];
    ballCoo[0] += ballCoo[0] - ballPCoo[0];
    ballCoo[1] += ballCoo[1] - ballPCoo[1];
    //qDebug() << "w trakcie" << ballCoo[1];
    ballPCoo[0] = tmp[0];
    ballPCoo[1] = tmp[1];
    //qDebug() << ballCoo[0] << ballCoo[1];
  }



}*/


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
  //
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
    gamaeParam.newScala = Skala;
    qDebug() << "Nowa skala";

  }
  Rysownik.drawImage(gameParam.ballPos[0], gameParam.ballPos[1], ball);
  Rysownik.drawImage(gameParam.userPlateLoc[0][0], gameParam.userPlateLoc[1][0], userPlate);
  Rysownik.drawImage(gameParam.comPlateLoc[0][0], gameParam.comPlateLoc[1][0], computerPlate);
  //qDebug() << gameParam.userPlateLoc[0][0];
  /* if (gameInfo->isGameActive) {

     if (userPlateX + gameInfo->YVal + 120 < width() - 60 && userPlateX + gameInfo->YVal > 0) {
       userPlateX += gameInfo->YVal;
       Rysownik.drawImage(userPlateX, height() - 60, userPlate);
     }
     else
       Rysownik.drawImage(userPlateX, height() - 60, userPlate);
   }
   Rysownik.drawImage(gameParam.comPlateLoc[0][0], 30, computerPlate);
   Rysownik.drawLine(0, 60, 300, 60);
   Rysownik.drawLine(0, height() - 60, 300, height() - 60);
   //qDebug() << Skala;*/

}