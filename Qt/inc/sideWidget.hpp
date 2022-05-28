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
#include "ui_sidePanelWidget.h"

//lass mainGameWidget;


/**
 * @brief Klasa panelu bocznego
 *
 * Klasa jest widgetem zawierajacym czas gry oraz przyciski do
 * zarzadzania gra
 */
class SidePanelWidget :public QWidget, public Ui::sidePanelWidget {
    Q_OBJECT

private:
    /**
     * @brief Pole
     *
     */
     //  mainGameWidget* oknogry;
       /**
        * @brief Pole
        *
        */
    QTimer* timer;
    /**
     * @brief Pole
     *
     */
    QTime accTime;
    /**
     * @brief Pole
     *
     */
    bool isStarted = 0;
public:
    /**
     * @brief Construct a new game Widget object
     *
     * @param parent
     * @param applTimer
     */
    SidePanelWidget(QWidget* parent = nullptr, QTimer* applTimer = nullptr);

public slots:
    /**
     * @brief Slot
     *
     */
    void EndProgram();
    /**
     * @brief Slot
     *
     */
    void updateTime();
    /**
     * @brief Slot
     *
     */
    void writeTime();
    /**
     * @brief Slot
     *
     */
    void EndGame();
signals:
    /**
     * @brief Slot
     *
     */
    void EmitClosing();
    void EmitEndGame();
};
#endif