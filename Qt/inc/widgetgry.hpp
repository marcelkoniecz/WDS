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


class disDialog :public QDialog, public Ui::disDialog {
    Q_OBJECT
public:
    disDialog();

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
    // void on_connectButton_clicked();

signals:
    //void EmitSearchDev();
    void EmitChooseDev();
};

//Pole gry
class mainGameWidget :public QWidget {
    Q_OBJECT
        QImage background;
    QImage computerPlate;
    QImage userPlate;
    QImage ball;
public:
    mainGameWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* ptr);
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
        mainGameWidget* okienko;

public:
    gameWidget* statystyki;
    mainWidget(QWidget* parent = nullptr);
};


//Okno 
class gameWindow :public QMainWindow, public Ui::gameWindow {
    Q_OBJECT
        QSerialPort* device;
    mainWidget* CentralWidget;
    //QMenuBar *menuBar;
    //QMenu *menuUstawienia;
    QDialog* connectionDialog;
    // QDialog *disconnectionDialog;
    QDialog* settingsDialog;
public:
    gameWindow(QWidget* parent = nullptr);
    //  virtual ~gameWindow() = default;

public slots:
    void on_actionSettings_triggered();
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
};



#endif