//#include <QDir>
#include <iostream>
#include <QtSerialPort/QtSerialPort>
#include <QtWidgets>
#include <QLabel>
#include "inc/odczyt.hpp"
#include "inc/crc8.hpp"

int main(int argc, char *argv[])
{
    QApplication App(argc,argv);
    UARTWindow Start;
    Start.show();
    return App.exec();
}