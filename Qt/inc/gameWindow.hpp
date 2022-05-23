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
#include "dialogs.hpp"
#include "ui_gameWindow.h"

class mainWidget;

/**
 * @brief Klasa zawierajaca informacje na temat gry
 */
class gameParameters {
public:
    /**
     * @brief  Pole nazwy podlaczonego urzadzenia
     */
    QString devName;
    /**
     * @brief Pole predkosc pilki
     */
    double ballVel;
    /**
     * @brief Pole predkosc plytki gracza
     */
    double userPlateVel;
    /**
     * @brief Pole predkosc plytki sterowanej przez komputer
     */
    double comPlateVel;
    double XVal;
    double YVal;
    double ZVal;
    /**
     * @brief  Pole typu bool reprezentujaca kierunek poruszania sie pilki
     *  Dla wartosci rownej 1 pilka porusza sie do gory
     *  Dla wartosci rownej 0 pilka porusza sie w dol
     */
    int ballDirection = 1; //dir = 0 bottom, dir = 1 top
   /**
    * @brief Pole typu bool reprezentujaca czy gra sie aktualnie toczy
    *  Dla wartosci rownej 0 gra jest nieaktywna
    *  Dla wartosci rownej 1 gra jest aktywna
    */
    bool isGameActive = 0; //If game is started
    /**
     * @brief Pole typu bool reprezentujaca czy urzadzenie jest podlaczone
    * Dla wartosci rownej 0 urzadzenie nie jest podlaczone
     * Dla wartosci rownej 1 jest podlaczone urzadzenie
     */
    bool isConnected = 0;  //If device is connected
    void calculateVel();
};

/**
 * @brief Klasa reprezentujaca glowne okno
 *
 * Klasa ta jest glownym elementem aplikacji,
 */
class gameWindow :public QMainWindow, public Ui::gameWindow {
    Q_OBJECT

        /**
         * @brief Pole Urzadzenie podlaczone do gry
         */
        QSerialPort* device;
    /**
     * @brief Dialog polaczenia
     */
    conDialog* connectionDialog;
    /**
     * @brief Dialog rozlaczenia
     */
    QDialog* disconnectionDialog;
    /**
     * @brief  Widget paska bocznego
     */
    gameParameters gameInfo;
    /**
     * @brief Widget gry
     */
    mainWidget* CentralWidget;

public:
    /**
     * @brief Konstruktor nowego okna gry
     * @param parent Rodzic qmainWindow domyslnie wskazujacy na NULL
     */
    gameWindow(QMainWindow* parent = nullptr);
    //  virtual ~gameWindow() = default;

public slots:
    /**
     * @brief Slot dla wcisnietego przycisku 
     * 
     */
    void on_actionSettings_triggered();
    /**
     * @brief Slot dla wcisnietego przycisku
     *
     */
    void on_actionConnect_triggered();
    /**
     * @brief Slot dla wcisnietego przycisku rozlaczenia
     * Po wcisnieciu przycisku  aktualne polaczone urzadzenie jest rozlacznie
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief
     *
     * @param devName
     */
    void initDevice(QString devName);
    /**
     * @brief Slot dla 
     *
     */
    void ReadTransmision();
};


#endif