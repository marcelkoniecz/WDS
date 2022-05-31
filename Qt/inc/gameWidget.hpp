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
#include "gameParameters.hpp"

class UARTVal;


class imageParameters {
public:
    double ballSpeed;
    double plateSpeed;
    double XtargetComPlate;
    int userLives;
    int compLives;
    volatile double userPlateLoc[2][2];//
    volatile double comPlateLoc[2][2];
    volatile double ballPos[2];  //x y
    volatile double currentAngle;
    double newScala;
};
//Pole gry

class mainGameWidget :public QWidget {
    Q_OBJECT
private:
    QImage background;
    QImage computerPlate;
    imageParameters imageInfo;
    imageParameters gameParam;
    QImage userPlate;
    QImage ball;
    QImage life;
    volatile UARTVal* gameInfo;
    QTimer* gameTimer;
    gameParameters* gameParame;
    double timerun;
public:
    mainGameWidget(QWidget* parent = nullptr, UARTVal* gameInformations = nullptr,
        QTimer* appTimer = nullptr, gameParameters* gameParamtr = nullptr);
    void paintEvent(QPaintEvent* ptr);

    void calculateBallPosition();
    void calculateUserPlate();
    void calculateComPlatePosition();
    void calculateIfBouncedPlate();
    void calculateIfBouncedWall();
    void calculateIfEndGame();
    void initValues(int comLives, int userLives);

    void makeGameStep();

    void gameEnd();
    void calComPlate();
    void calBal();
public slots:
    void updateTime();

signals:
    void EmitEndGame();

};


#endif