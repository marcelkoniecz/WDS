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

/*
class UARTRead :public QWidget {
    Q_OBJECT
        QTextEdit* text;
public:
    UARTRead(QWidget* parent = nullptr);
    void EditText(QString textToWrite);
public slots:
    void EndProgram();
    void StartTransmit();

signals:
    void EmitClosing();
    void EmitStartUART();
};



class UARTWindow :public QMainWindow {
    Q_OBJECT
        QSerialPort* device;
    UARTRead* CentralWidget;
public:
    UARTWindow(QWidget* parent = nullptr);
public slots:
    void ConnectDevice();
    void ReadTransmision();
};
*/


