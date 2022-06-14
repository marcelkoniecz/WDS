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
#include "gameParameters.hpp"
#include "mainWidget.hpp"
#include "gameStatistics.hpp"
#include "dialogs.hpp"
#include "ui_gameWindow.h"
#include "uartParam.hpp"
#include "gameSettings.hpp"


class mainWidget;
class gameStatistics;
class settDialog;
class endDialog;
class disDialog;
class conDialog;
class gameStatisticsWidget;

/**
 * @file
 * @brief Definicja klasy gameWindow
 *
 * Plik nagłówkowy  klasą okna apliji 
 */


 /**
  * @brief Klasa reprezentujaca glowne okno
  *
  * Klasa reprezentujaca glowne okno aplikacji, klasa ta jest glownym elementem aplikacji,
  *odpowiada za odczytywanie danych z mikrokontrolera, zawiera widget gry oraz statystyk, oraz
  *odpowiednie dialogi.
  */
class gameWindow :public QMainWindow, public Ui::gameWindow {
    Q_OBJECT
private:
    /**
     * @brief Pole urzadzenia podlaczonego do gry
     *
     * Pole reprezentujące urzadzenia podlaczone do gry, używane w celu odczytywania danych.
     */
    QSerialPort* device;
    /**
     * @brief Pole dialogu połączenia
     *
     * Pole reprezentujące dialog połączenia, który jest wywoływany podczas wybrania
     * opcji connect w menu.
     */
    conDialog* connectionDialog;
    /**
     * @brief Pole dialogu rozłączenia
     *
     * Pole reprezentujące dialog rozłączenia, który jest wywoływany podczas wybrania
     * opcji disconnect w menu.
     */
    disDialog* disconnectionDialog;
    /**
     * @brief Pole dialogu rozłączenia
     *
     * Pole reprezentujące dialog końca gry, który jest wywoływany podczas zakończenia
     * gry przez jednego z graczy.
     */
    endDialog* endGameDialog;
    /**
     * @brief Pole dialogu ustawień
     *
     * Pole reprezentujące dialog ustawień, który jest wywoływany podczas wybrania
     * opcji settings w menu.
     */
    settDialog* settingsDialog;
    /**
     * @brief Pole przechowujące informacje na temat połączenia uart
     *
     * Pole przechowujące informacje na temat połączenia uart.
     */
    UARTVal gameInfo;
    /**
     * @brief Pole zawierające ustawienia gry
     *
     * Pole przechowujące informacje na temat ustawień gry.
     */
    gameSettings gameSett;
    /**
     * @brief Pole widgetu głównego aplikacji
     *
     * Pole widgetu głównego aplikacji, składa się widgetu gry oraz widgetu panelu bocznego.
     */
    mainWidget* CentralWidget;
    /**
     * @brief Pole stacked Widgetu
     *
     *  Pole stacked Widgetu składającego się z widgetu głównego aplikacji oraz widgetu statystyk
     * widget jest zmieniany w chwili wybrania przez użytkownika opcji Statistics podczas końcay 
     * podczas naciśnięcia przycisku return, wyświetlany widget jest zmieniany na widget główny aplikacji.
     */
    QStackedWidget* stackWidget;
    /**
     * @brief Pole widgetu statystyk
     *
     * Pole widgetu statystyk, widget jest wyświetlany podczas wybrania przez użytkownika oi 
     * Statistics podczas końca g 
     */
    gameStatisticsWidget* statsWidget;
    /**
     * @brief Pole przechowujące statystyki gry
     *
     * Pole przechowujące statystyki  aktualnej gry
     */
    gameParameters gameParam;

    friend class SidePanelWidget;
    friend class settDialog;
    friend class mainWidget;
    friend class mainGameWidget;
    friend class  gameStatisticsWidget;

public:

    /**
     * @brief Konstruktor nowego okna gry
     */
    gameWindow(QMainWindow* parent = nullptr);
    virtual void changeEvent(QEvent* event) override;

public slots:
    /**
     * @brief Slot obsługujący wybranie opcji ustawień
     */
    void on_actionSettings_triggered();
    /**
     * @brief Slot obsługujący wybranie opcji połąnia 
     */
    void on_actionConnect_triggered();
    /**
     * @brief  Slot obsługujący wybranie opcji rozłączenia
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief Slot inicjalizujacy połączenie z mikrokontrolerem
     */
    void initDevice(QString devName);
    /**
     * @brief Slot  odpowiedzialny za odczytywanie danych z UART
     */
    void ReadTransmision();
    /**
     * @brief Slot odpowiedzialny za obsługę restartu gry
     */
    void restartGame();
    /**
     * @brief Slot odpowiedzialny za obsługę końca gry
     */
    void endGame();
    /**
     * @brief Slot odpowiedzialny za zmianę stackwidgeta na widget z statystykami
     */
    void openStatisticsWidget();
    /**
     * @brief Slot odpowiedzialny za zmianę stackwidgeta na widget z g 
     */
    void openGameWidget();
    /**
     * @brief Slot rozłączający połączone urządzenie
     */
    void disconnectDevice();
    /**
     * @brief Slot sprawdzający czy wystąpiła zmiana języka
     */
    void checkLanguage();
signals:
    /**
     * @brief Sygnał informujący że wystąpił reset gry
     *
     *Sygnał informujący że wystąpił reset gry.
     */
    void EmitRestartGame();
    /**
     * @brief Sygnał informujący o wystąpienniu zmiany języka
     *
     * Sygnał informujący o wystąpieniu zmiany języka, odbiera go każdy z diogów 
     * oraz widgetów aplikacji.
     */
    void EmitRetranslate();
    /**
     * @brief Sygnał zablokowania przycisków
     *
     * Sygnał zablokowania przycisków, informujący że na ekranie pojawił się dialog końca gry,
     * pozwala zablokować przyciski aby gracz nie włączył gry z wyświetlonym dialogiem końca gry.
     */
    void EmitBlockButtons();
    /**
     * @brief Sygnął zatrzymania gry
     * 
     * Sygnał zatrzymania gry, emitowany podczas wywołania dialogu.
     */
    void EmitPauzeGame();

};


#endif