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
#include "gameSettings.hpp"
#include "gameWindow.hpp"

class gameWindow;

class settDialog :public QDialog, public Ui::settDialog {
    Q_OBJECT
private:
    gameSettings* ptrGameSett;

public:
    settDialog(gameWindow* parent = nullptr);
    void loadParam();
public slots:
    void on_saveButton_clicked();
    void on_returnButton_clicked();
    void retranslate();
signals:
    void EmitSettingsSaved();


};


class endDialog :public QDialog, public Ui::endGameDialog {
    Q_OBJECT
private:

public:
    endDialog(gameWindow* parent = nullptr);
public slots:
    void on_statisticsButton_clicked();
    void on_restartButton_clicked();
    void on_exitButton_clicked();
     void retranslate();
signals:
    void EmitClosing();
    void EmitRestartGame();
    void EmitOpenStatistics();
};

class disDialog :public QDialog, public Ui::disDialog {
    Q_OBJECT
public:
    disDialog(gameWindow* parent = nullptr);
    void StartDialog(QString connectedDev);
public slots:
    void on_disconnectButton_clicked();
    void on_cancelButton_clicked();
     void retranslate();
signals:
    void EmitDisconnectDevice();

};

class conDialog :public QDialog, public Ui::conDialog {
    Q_OBJECT
        QList<QSerialPortInfo> portList;
public:
    conDialog(gameWindow* parent = nullptr);
public slots:
    //void searchDev();
    //void chooseDev();
    void on_searchDeviceButton_clicked();
    void on_cancelButton_clicked();
    void on_connectButton_clicked();
     void retranslate();

signals:
    //void EmitSearchDev();
    void EmitChoosenDev(QString);
    void EmitClosing();
};

#endif