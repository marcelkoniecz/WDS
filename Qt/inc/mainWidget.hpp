#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#pragma once
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
#include "statisticWidget.hpp"

class mainGmaeWidget;
class gameWidget;
class gameWindow;
class gameParameters;



//Widget zawierajacy pole gry oraz panel boczny
/**
 * @brief Klasa reprezentujaca widget glowny
 *
 */
class mainWidget :public QWidget {
    Q_OBJECT
        /**
         * @brief Pole reprezentujace timer
         */
        QTimer* gameTimer;
public:
    /**
     * @brief
     *
     */
    mainGameWidget* okienko;
    /**
     * @brief
     *
     */
    gameWidget* statystyki;
    //mainWidget(gameWindow* parent = nullptr);
    /**
     * @brief Construct a new main Widget object
     *
     * @param parent
     * @param gameInfo
     */
    mainWidget(gameWindow* parent = nullptr, gameParameters* gameInfo = nullptr);
public slots:
    /**
     * @brief
     *
     */
    void updateTime();
};

#endif