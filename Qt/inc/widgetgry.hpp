#ifndef WIDGETGRY_HPP
#define WIDGETGRY_HPP

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
#include "ui_gameWidget.h"
//#include "ui_aplicationmainwindow.h"

/*
class Test :public QMainWindow,public Ui::MainWindow {

public:
    Test() {
        setupUi(this);
    }
};
*/
class mainGameWidget :public QWidget {
    Q_OBJECT
        QImage background;
    QImage computerPlate;
    QImage userPlate;
    QImage ball;
public:
    mainGameWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *ptr);
  //  virtual void resizeEvent( QResizeEvent * event ) override;

};

class gameWidget :public QWidget, public Ui::gameWidget {
    Q_OBJECT
    mainGameWidget  *oknogry;
    QTimer *timer;
    QTime accTime;
    bool isStarted=0;
public:
    gameWidget(QWidget* parent = nullptr);

public slots:
    void EndProgram();
    void updateTime();
    void writeTime();
    void EndGame();
signals:
    void EmitClosing();
   // virtual void resizeEvent( QResizeEvent * event ) override;
};

class gameWindow :public QMainWindow {
    Q_OBJECT
        QSerialPort* device;
    gameWidget* CentralWidget;
public:
    gameWindow(QWidget* parent = nullptr);
    //  virtual ~gameWindow() = default;
};

#endif