#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <iostream>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QtWidgets>
#include <QLabel>
#include <QList>
#include <QTextEdit>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QDialog>
#include "mainWidget.hpp"

class gameParameters;


class imageParameters {
   // double RotationMatrix[2][2];
public:
    double ballSpeed=5;
    double plateSpeed;
    double XtargetComPlate;
    volatile double userPlateLoc[2][2];//
    volatile double comPlateLoc[2][2];
    volatile double ballPos[2]={200,200};  //x y
    volatile double currentAngle;
    double newScala;

    void calculatePosition(double const angle);
    bool calculateIfBounced(bool turn,int height,volatile gameParameters *game);
};
//Pole gry

class mainGameWidget :public QWidget {
    Q_OBJECT

        QImage background;
    QImage computerPlate;
    imageParameters imageInfo;
    imageParameters gameParam;
    QImage userPlate;
    QImage ball;
    volatile gameParameters* gameInfo;
    QTimer* gameTimer;
   // int userPlateX;
    //int comPlateX;
   // double ballCoo[2]{ 200,200 };
  //  double ballPCoo[2]{ 200,199 };
   // double newScala;
    // QSerialPort* device;
public:
    mainGameWidget(QWidget* parent = nullptr, gameParameters* gameInformations = nullptr, QTimer* appTimer = nullptr);
    void paintEvent(QPaintEvent* ptr);
    
    void calculateBallPosition();
    void calculateUserPlate();
    void calculateComPlatePosition();
    void calculateIfBouncedPlate();
    void calculateIfBouncedWall();
    void calculateIfEndGame();
    void initValues();
    
    void makeGameStep();

    void gameEnd();
    void calComPlate();
    void calBal();
public slots:
    void updateTime();

};


#endif