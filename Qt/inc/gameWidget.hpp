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
#include "gameSettings.hpp"
#include "imageParameters.hpp"

class UARTVal;
class mainWidget;
class gameWindow;


//Pole gry

class mainGameWidget :public QWidget {
    Q_OBJECT
private:
    QImage background;
    QImage computerPlate;
    //  imageParameters imageInfo;
    imageParameters gameParam;
    QImage userPlate;
    QImage ball;
    QImage life;
    UARTVal* gameInfo;
    QTimer* gameTimer;
    gameParameters* gameParame;
    gameSettings* gameSettgs;
    double timerun;
public:
    //  mainGameWidget(QWidget* parent = nullptr, UARTVal* gameInformations = nullptr,
     //     QTimer* appTimer = nullptr, gameParameters* gameParamtr = nullptr);
    mainGameWidget(mainWidget* parent = nullptr, gameWindow* gameWin = nullptr);

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