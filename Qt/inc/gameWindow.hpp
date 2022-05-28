#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

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
#include "gameStatistics.hpp"
#include "dialogs.hpp"
#include "ui_gameWindow.h"
#include "uartParam.hpp"
#include "gameSettings.hpp"

class mainWidget;
class gameStatistics;



/**
 * @brief Klasa reprezentujaca glowne okno
 *
 * Klasa ta jest glownym elementem aplikacji,
 */
class gameWindow :public QMainWindow, public Ui::gameWindow {
    Q_OBJECT
private:
    /**
     * @brief Pole Urzadzenia podlaczonego do gry
     */
    QSerialPort* device;
    /**
     * @brief Pole dialog polaczenia
     */
    conDialog* connectionDialog;
    /**
     * @brief Pole dialog rozlaczenia
     */
    QDialog* disconnectionDialog;
    /**
     * @brief  Pole struktury z odczytami
     */
    endDialog *endGameDialog;
    settDialog *settingsDialog;

    UARTVal gameInfo;
    /**
     * @brief Pole widgetu gry
     */
    mainWidget* CentralWidget;
    QStackedWidget *stackWidget;
    gameStatisticsWidget* statsWidget;

public:
    /**
     * @brief Konstruktor nowego okna gry
     * @param parent Rodzic qmainWindow domyslnie wskazujacy na NULL
     */
    gameWindow(QMainWindow* parent = nullptr);
    //  virtual ~gameWindow() = default;

public slots:
    /**
     * @brief Slot wywowujacy dialog z ustawieniami
     *
     */
    void on_actionSettings_triggered();
    /**
     * @brief Slot wywołujacy dialog z polaczeniem
     */
    void on_actionConnect_triggered();
    /**
     * @brief Slot dla wcisnietego przycisku rozlaczenia
     * Po wcisnieciu przycisku  aktualne polaczone urzadzenie jest rozlacznie
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief Slot inicjalizujacy polaczenie z mikrokontrolerem
     *
     * @param devName Nazwa polaczonego urzadzenia
     */
    void initDevice(QString devName);
    /**
     * @brief Slot do odczytywania danych z UART
     * Za pomocą tej funkcji odczytywane oraz zapisywane są dane w jaki sposób porusza się akcelerometr
     *
     */
    void ReadTransmision();
    void restartGame();
    void endGame();
    void openStatisticsWidget();
    void openGameWidget();
};


#endif