
#include <iostream>
#include <QtSerialPort/QtSerialPort>
#include <QtWidgets>
#include <QLabel>
#include "mainWidget.hpp"
#include "gameWindow.hpp"

/**
 *  @file
 *  @brief Plik główny aplikacji
 *
 * Plik główny aplikacji odpowiedzialny za stworzenie i uruchomienie gry.
 */

int main(int argc, char* argv[])
{
    QApplication App(argc, argv);
    //UARTWindow Start;

    gameWindow Start;

    Start.show();
    return App.exec();
}