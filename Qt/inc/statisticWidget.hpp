#ifndef STATISTICWIDGET_HPP
#define STATISTICWIDGET_HPP

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
#include "ui_gameWidget.h"

class mainGameWidget;

//panel boczny
/**
 * @brief 
 * 
 */
class gameWidget :public QWidget, public Ui::gameWidget {
    Q_OBJECT
        mainGameWidget* oknogry;

    QTimer* timer;
    QTime accTime;
    bool isStarted = 0;
public:
    gameWidget(QWidget* parent = nullptr, QTimer* applTimer=nullptr);

public slots:
    void EndProgram();
    void updateTime();
    void writeTime();
    void EndGame();
signals:
    void EmitClosing();
};
#endif