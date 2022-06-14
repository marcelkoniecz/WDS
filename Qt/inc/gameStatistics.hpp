#ifndef GAMESTATISTICS_HPP
#define GAMESTATISTICS_HPP

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
#include "ui_gameStatistics.h"
#include <QChart>
#include <QPainter>
#include <QtCharts>
#include "gameParameters.hpp"
#include <QLineSeries>
#include <QValueAxis>
#include "gameWindow.hpp"

/**
 * @file
 * @brief  Definicja klasy gameStatisticsWidget
 *
 *  Plik nagłówkowy zawierający widget statystyk.
 */

class gameWindow;

/**
 * @brief Klasa reprezentująca widget statystyk końcowych
 *
 * Klasa reprezentująca widget statystyk końcowych, widget ukazuje siędy 
 * użytkownik zechce zobaczyć statystyki właśnie skończogry. 
 */
class gameStatisticsWidget :public QWidget, public Ui::gameStatistics {
    Q_OBJECT
private:
    /**
     * @brief Wskaźnik na wykres
     *
     * Wskaźnik na wykres, używany w celu generowania wykresu.
     */
    QChart* chart;
    /**
     * @brief Wskaźnik na klasę statystyk gy 
     *
     * Wskaźnik na klasę statystyk gry, zostanie do niego przypisany adres z okna głównego aplikacji,
     * wykorzystywany w celu wyświetlenia statystyk końcowych gry.
     */
    gameParameters* gamePrmts;
    /**
     * @brief Wskaźnik na punkty wykresu
     *
     * Wskaźnik na punkty wykresu, za pomcą tych punktów jest generowany wykres przyśpieszenia
     * akkcelerometru.
     */
    QLineSeries* points;
    /**
     * @brief Wskaźnik na widget wyświetlający wykres
     *
     * Wskaźnik na widget wyświetlający wykres, dodajemy do niego wykres.
     */
    QChartView* chartView;
    /**
     * @brief Wskaźnik na osie wykresu
     *
     * Wskaźnik na osie wykresu, za pomocą tego wskaźnika są ustawiane wartości poszczególych
     * osi na wykresie.
     */
    QValueAxis* axis;
    /**
     * @brief Zaprzyjaźniona klasa okna główngo 
     *
     * Zaprzyjaźniona klasa okna głównego w celu skorzystania z prywatnego pola - gameParameters.
     */
    friend gameWindow;
public:
    /**
     * @brief Konstruktor widgetu statystyk

     */
    gameStatisticsWidget(gameWindow* parent = nullptr);
    /**
     * @brief Metoda odpowiedzialna za rysowanie wykresu
     */
    void printChart();

public slots:
    /**
     * @brief Slot obsługujący kliknięcie przycisku return
     */
    void on_returnButton_clicked();
    /**
     * @brief Slot zmiany języka
     */
    void retranslate();
signals:

    /**
     * @brief Sygnał przejścia do głównego widgetu aplikacji
     *
     * Sygnał przejścia do widgetu gry, wysyłany w chwili naciśnięcia przycisku
     * return. Za pomocą tego sygnału zmieniany jest główny widget aplji. 
     */
    void EmitChangeWidget();
};

















#endif