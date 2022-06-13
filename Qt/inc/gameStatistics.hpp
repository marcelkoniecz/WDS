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
  * @brief Plik nagłówkowy zawierający widget statystyk
  *  Plik nagłówkowy zawierający widget statystyk.
  */

class gameWindow;

/**
 * @brief Klasa reprezentująca widget statystyk końcowych
 * 
 * Klasa reprezentująca widget statystyk końcowych, widget ukazuje się gdy 
 * użytkownik zechce zobaczyć statystyki właśnie skończonej gry. 
 */
class gameStatisticsWidget :public QWidget, public Ui::gameStatistics {
    Q_OBJECT
private:
    QChart* chart;
    gameParameters *gamePrmts;
    QLineSeries* points;
    QVBoxLayout* layout;
    QChartView* chartView;
    QValueAxis* axis;
    friend gameWindow;
public:
    gameStatisticsWidget(gameWindow *parent=nullptr);
    void printChart();

public slots:
    void on_returnButton_clicked();
    void retranslate();
signals:

/**
 * @brief Sygnał przejścia do głównego widgetu aplikacji
 *  
 * Sygnał przejścia do widgetu gry, wysyłany w chwili naciśnięcia przycisku
 * return. Za pomocą tego sygnału zmieniany jest główny widget aplikacji. 
 */
    void EmitChangeWidget();
};

















#endif