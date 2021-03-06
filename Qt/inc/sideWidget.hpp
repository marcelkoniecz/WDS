#ifndef SIDEWIDGET_HPP
#define SIDEWIDGET_HPP

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
#include "gameWindow.hpp"
#include "gameParameters.hpp"
#include "ui_sidePanelWidget.h"

/**
 *@file
 *  @brief Definicja klasy SidePanelWidget
 *
 * Plik nagłówkowy klasy SidePanelWidget
 *
 */


class mainGameWidget;
class gameWindow;

/**
 * @brief Klasa reprezentująca panel boczny aplikacji
 *
 * Klasa jest widgetem zawierajacym czas gry oraz przyciski do
 * zarzadzania gra
 */
class SidePanelWidget :public QWidget, public Ui::sidePanelWidget {
    Q_OBJECT

private:
    /**
     * @brief Wskaźnik na klasę gameParameters
     *
     * Wzkaźnik na klasę zawierającą statystyki dotyczące danej gry,
     * jest on uzywany w celu zapisania aktualnego czasu gry i wyswietlenia
     * go w oknie statystyk.
     */
    gameParameters* gamePar;
    /**
     * @brief Wzkażnik na klasę UARTVal
     *
     * Wskaźnik na klasę zawierającą dane odczytane z UART, jest on ożywany w celu
     * sprawdzania czy aktualnie gra jest połączona z urządzeniem.
     */
    UARTVal* gameUART;

    /**
     * @brief Wskaźnik na zegar aplikacji
     *
     * Wskaźnik na QTimer odpowiedzialny za pomiar czasu aplikacji.
     */
    QTimer* timer;
    /**
     * @brief Pole odmierząjące aktualny czas aplikacji w sekundach
     *
     * Pole odmierząjące aktualny czas aplikacji w sekundach
     */
    QTime accTime;

    /**
     * @brief Pole odpowiedzialne za sterowniem odmierzaniem czasu
     *
     * @retval true -- aplikacja jest uruchomiona,
     * @retval false -- aplikacja jest zatrzymana.
     */
    bool isStarted = false;
public:
    /**
     * @brief Konstruktor panela bocznego aplikacji
     */
    SidePanelWidget(mainWidget* parent = nullptr, gameWindow* gameWin = nullptr);
    /**
     * @brief Metoda sprawdzania połączenia z urządzeniem
     *
     */
    void checkConnection();

public slots:
    /**
    * @brief Slot zakończenia programu 
     *
     */
    void EndProgram();
    /**
     * @brief Slot aktualizacji czasu
     */
    void updateTime();
    /**
     * @brief Slot obługi przycisku Resume
     */
    void writeTime();
    /**
     * @brief Slot końca gry
     */
    void EndGame();
    /**
     * @brief Slot odpowiedzialny za wyzerowanie czasu zegara
     */
    void setTimerNull();
    /**
     * @brief Slot przetłumaczenia widgeta
     *
     */
    void retranslatePanel();
    /**
    * @brief Slot blokowania przycisków
     */
    void checkBlockButtons();
    /**
     * @brief Slot zatrzymywania gry
     */
    void pauzeGameFun();
signals:
    /**
     * @brief Sygnał zamknięcia aplikacji
     *
     * Sygnał zamknięcia aplikacji w momencie wciśnięcia przycisku Exit Application
     */
    void EmitClosing();
    /**
     * @brief Sygnał końca gry
     *
     * Sygnał końca gry wysyłany w momencie naciśnięcia przycisku End game.
     */
    void EmitEndGame();
};
#endif