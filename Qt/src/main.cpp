//#include <QDir>
#include <iostream>
#include <QtSerialPort/QtSerialPort>
#include <QtWidgets>
#include <QLabel>
#include "mainWidget.hpp"
#include "gameWindow.hpp"

//#include "odczyt.hpp"
//#include "inc/crc8.hpp"

//#include "oknogry.hpp"
//#include "widgetgry.hpp"

int main(int argc, char *argv[])
{
    QApplication App(argc,argv);
    //UARTWindow Start;
    
    gameWindow Start;

    Start.show();
    return App.exec();
}