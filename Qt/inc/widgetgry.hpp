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
#include <QDialog>
#include "odczyt.hpp"
#include "ui_gameWidget.h"
#include "ui_gameWindow.h"
#include "ui_disDialog.h"
#include "ui_conDialog.h"

class gameWindow;

class gameParameters {
   public:
    QString devName;
    double ballVel;
    double userPlateVel;
    double comPlateVel;
    double XVal;
    double YVal;
    double ZVal;
    void calculateVel();
};
/*
class UARTThread :public QThread {
    Q_OBJECT
        QSerialPort device;
public:
    UARTThread(gameParameters &gameinfo);
    void run();
};

*/

class disDialog :public QDialog, public Ui::disDialog {
    Q_OBJECT
public:
    disDialog(QString connectedDev="No device connected");
    void StartDialog(QString connectedDev);
};

class conDialog :public QDialog, public Ui::conDialog {
    Q_OBJECT
        QList<QSerialPortInfo> portList;
public:
    conDialog();
public slots:
    //void searchDev();
    //void chooseDev();
    void on_searchDeviceButton_clicked();
    void on_cancelButton_clicked();
    void on_connectButton_clicked();

signals:
    //void EmitSearchDev();
    void EmitChoosenDev(QString);
    void EmitClosing();
};

//Pole gry
class mainGameWidget :public QWidget {
    Q_OBJECT
        QImage background;
    QImage computerPlate;
    QImage userPlate;
    QImage ball;
    // QSerialPort* device;
public:
    mainGameWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* ptr);
public slots:
    void tak(){
        qDebug()<<"tak";
    }

};

//panel boczny
class gameWidget :public QWidget, public Ui::gameWidget {
    Q_OBJECT
        mainGameWidget* oknogry;

    QTimer* timer;
    QTime accTime;
    bool isStarted = 0;
public:
    gameWidget(QWidget* parent = nullptr);

public slots:
    void EndProgram();
    void updateTime();
    void writeTime();
    void EndGame();
signals:
    void EmitClosing();
};

//Widget zawierajacy pole gry oraz panel boczny
class mainWidget :public QWidget {
    Q_OBJECT



public:
    mainGameWidget* okienko;
    gameWidget* statystyki;
    mainWidget(gameWindow* parent = nullptr);
};


//Okno 
class gameWindow :public QMainWindow, public Ui::gameWindow {
    Q_OBJECT

        mainWidget* CentralWidget;
    QSerialPort* device;
    conDialog* connectionDialog;
    QDialog *disconnectionDialog;
    gameParameters gameInfo;
    QTimer *gameTimer;

    //QMenuBar *menuBar;
    //QMenu *menuUstawienia;
    //   QDialog* connectionDialog;
    // QDialog *disconnectionDialog;
     // QDialog* settingsDialog;
public:

    gameWindow(QMainWindow* parent = nullptr);
    //  virtual ~gameWindow() = default;

public slots:
    void on_actionSettings_triggered();
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
    void initDevice(QString devName);
    void ReadTransmision();
};



#endif