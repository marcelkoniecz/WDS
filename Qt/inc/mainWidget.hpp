#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

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
#include "gameWindow.hpp"
#include "gameWidget.hpp"
#include "sideWidget.hpp"

class mainGameWidget;
class SidePanelWidget;
class gameWidget;
class gameWindow;
class UARTVal;

/**
 * @file 
 * @brief Definicja klasy  mainWidget
 * 
 * Plik nagłówkowy zawierający klasę mainWidget
 */


//Widget zawierajacy pole gry oraz panel boczny
/**
 * @brief Klasa reprezentujaca widget glowny
 * 
 * Klasa jest odpowiedzialna za stworzenie w widgecie glownym widgetu z gra
 * oraz widgetu panelu bocznego
 */
class mainWidget :public QWidget {
    Q_OBJECT
private:

public:
    /**
     * @brief Wskaźnik na timer gry
     * 
     * Wskaźnik na timer gry, pole zostaje zaalokowany w konstruktorze, 
     * odpowiada za odmierzanie czasu gry.
     */
    QTimer* gameTimer;
    /**
     * @brief Pole reprezentujące widget gry
     *
     * Pole reprezentujące widget gry, zostaje zaalokowane w konstruktorze.
     */
    mainGameWidget* okienko;
    /**
     * @brief Pole reprezentujace widget z panelem bocznym
     *
     * Pole reprezentujace widget z panelem bocznym, zostaje zaalokowane w konstruktorze.
     */
    SidePanelWidget* statystyki;
    /**
     * @brief Konstruktor tworzący widget glowny aplikacji
     */
    mainWidget(gameWindow* parent=nullptr);
public slots:
    /**
     * @brief Slot obsługujacy timeout() zegara
     *
     * Slot obsługujący timeout zegara, timeout występuje z interwałem 10 mil. sec.
     */
    void updateTime();
};

#endif