#ifndef DIALOGS_HPP
#define DIALOGS_HPP

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
#include "ui_disDialog.h"
#include "ui_conDialog.h"
#include "ui_endGameDialog.h"
#include "ui_settDialog.h"
//#include "gameWindow.hpp"

class settDialog :public QDialog, public Ui::settDialog {
    Q_OBJECT

public:
    settDialog();
public slots:
    void on_saveButton_clicked();
    void on_returnButton_clicked();

};


class endDialog :public QDialog, public Ui::endGameDialog {
    Q_OBJECT
private:

public:
    endDialog();
public slots:
    void on_statisticsButton_clicked();
    void on_restartButton_clicked();
    void on_exitButton_clicked();
signals:
    void EmitClosing();
    void EmitRestartGame();
    void EmitOpenStatistics();
};

class disDialog :public QDialog, public Ui::disDialog {
    Q_OBJECT
public:
    disDialog(QString connectedDev = "No device connected");
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

#endif