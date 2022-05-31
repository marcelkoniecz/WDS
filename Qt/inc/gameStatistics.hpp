#ifndef GAMESTATISTICS_HPP
#define GAMESTATISTICS_HPP

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
#include "ui_gameStatistics.h"
#include <QChart>
#include <QPainter>
#include <QtCharts>
#include "gameParameters.hpp"
#include <QLineSeries>
// class myChart :public QChart {
//     Q_OBJECT
// private:
//     QChart* chart;
// public:
//     myChart();

// }




class gameStatisticsWidget :public QWidget, public Ui::gameStatistics {
    Q_OBJECT
public:
    QChart* chart;
    gameParameters *gameParam;
    QLineSeries* points;

public:
    gameStatisticsWidget(gameParameters *game=nullptr);
    void printChart();
public slots:
    void on_returnButton_clicked();
signals:
    void EmitChangeWidget();
};

















#endif