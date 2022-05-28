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



//Widget zawierajacy pole gry oraz panel boczny
/**
 * @brief Klasa reprezentujaca widget glowny
 * Klasa jest odpowiedzialna za stworzenie w widgecie glownym widgetu z gra
 * oraz widgetu panelu bocznego z opcjami
 *
 */
class mainWidget :public QWidget {
    Q_OBJECT
private:

public:
    /**
     * @brief Pole reprezentujace timer gry
     */
    QTimer* gameTimer;
    /**
     * @brief Pole reprezentujace widget z gra
     *
     */
    mainGameWidget* okienko;
    /**
     * @brief Pole reprezentujace widget z panelem bocznym
     *
     */
    SidePanelWidget* statystyki;
    //mainWidget(gameWindow* parent = nullptr);
    /**
     * @brief Konstruktor tworzący widget glowny aplikacji
     *
     * @param parent Wskaznik do rodzica
     * @param gameInfo Wskaznik do struktury z danymi odczytanymi z akcelerometru
     */
    mainWidget(gameWindow* parent = nullptr, UARTVal* gameInfo = nullptr);
public slots:
    /**
     * @brief Slot odwiezenia czasu
     *
     */
    void updateTime();
};

#endif