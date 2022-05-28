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



class gameStatisticsWidget :public QWidget, public Ui::gameStatistics {
    Q_OBJECT

public:
    gameStatisticsWidget();
public slots:
    void on_returnButton_clicked();
signals:
    void EmitChangeWidget();
};

















#endif