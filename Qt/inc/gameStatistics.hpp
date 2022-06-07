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
#include <QValueAxis>
#include "gameWindow.hpp"
// class myChart :public QChart {
//     Q_OBJECT
// private:
//     QChart* chart;
// public:
//     myChart();

// }

class gameWindow;


class gameStatisticsWidget :public QWidget, public Ui::gameStatistics {
    Q_OBJECT
public:
    QChart* chart;
    gameParameters *gamePrmts;
    QLineSeries* points;
    QVBoxLayout* layout;
    QChartView* chartView;
    QValueAxis* axis;

public:
    gameStatisticsWidget(gameWindow *parent=nullptr);
    void printChart();

public slots:
    void on_returnButton_clicked();
    void retranslate();
signals:
    void EmitChangeWidget();
};

















#endif