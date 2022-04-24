#include "inc/odczyt.hpp"
//#include "inc/crc8.hpp"
#include <string>
#include "cstring"

#define POLYNOMIAL 0x161

uint16_t CRCSingleByte(uint16_t data) {
    uint16_t poly = (POLYNOMIAL << 7);
    for (uint8_t i = 0; i < 8; i++) {
        if ((data & 0x8000) != 0)
            data ^= poly;
        data <<= 1;
    }
    return data;
}

uint16_t CalculateCRC8(char* ptr) {
    //	std::cout<<ptr;
    uint16_t data = ptr[0] << 8;

    for (int i = 1; i < strlen(ptr); i++) {
        data |= ptr[i];
        data = CRCSingleByte(data);
    }
    data = CRCSingleByte(data);
    return (data >> 8);
}


//Okno z widgetem 
UARTWindow::UARTWindow(QWidget* parent) {
    this->CentralWidget = new UARTRead(this);
    this->device = new QSerialPort(this);
    //statusBar->showMessage(tr("Odczyt UART"));
    setCentralWidget(CentralWidget);
    resize(600, 400);
    connect(CentralWidget, SIGNAL(EmitClosing()), this, SLOT(close()));
    connect(CentralWidget, SIGNAL(EmitStartUART()), this, SLOT(ConnectDevice()));
}

void UARTWindow::ConnectDevice() {
    // std::cout<<"jestem tu";
    if (device->isOpen()) {
        CentralWidget->EditText("Closing conection");
        device->close();

        return;
    }
    CentralWidget->EditText("Searching for devices ...");
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    if (devices.count() == 0) {
        CentralWidget->EditText("No devices to connect");
        return;
    }
    int devNum = 0;
    for (devNum = 0;devNum < devices.count();devNum++) {
        qDebug() << devices.at(devNum).portName() << devices.at(devNum).description();
        if (devices.at(devNum).description() == "STM32 STLink")
            break;
    }
    QString portName = devices.at(devNum).portName();

    device->setPortName(portName);

    if (device->open(QSerialPort::ReadWrite)) {
        device->setBaudRate(QSerialPort::Baud115200);
        device->setDataBits(QSerialPort::Data8);
        device->setParity(QSerialPort::NoParity);
        device->setStopBits(QSerialPort::OneStop);
        device->setFlowControl(QSerialPort::NoFlowControl);
        CentralWidget->EditText("Conected with " + devices.at(devNum).description());
        connect(this->device, SIGNAL(readyRead()), this, SLOT(ReadTransmision()));
    }
    else {
        CentralWidget->EditText("Can't connect with device");
    }
}
//UARTWindow::addToLogs(QString message){}

void UARTWindow::ReadTransmision() {
    uint16_t CRC8;
    std::string str;
    QString hexCRC8;
    QString terminator = " ";
    QString lineWOHex; //line without hex code at end
    while (this->device->canReadLine()) {
        QString line = this->device->readLine();
        if (line.at(0) != "X")
            continue;
        int pos1 = line.lastIndexOf(terminator);
        lineWOHex = line.left(pos1);
        int pos2 = lineWOHex.lastIndexOf(terminator);
        lineWOHex = line.left(pos2);
        // qDebug() <<line.left(pos2);
        // qDebug() <<pos1<<pos2<< line.mid(pos2+1,pos1-1)<<line.length();
        str = line.left(pos2).toStdString();
        CRC8 = CalculateCRC8(const_cast<char*>(str.c_str()));

        hexCRC8 = QString::number(CRC8, 16).toUpper();
        //qDebug()<<"Bez ifa "<<hexCRC8<<line.mid(pos2+1,pos1-1);
        if (hexCRC8 == line.mid(pos2 + 1, pos1 - 1).trimmed())
            this->CentralWidget->EditText(lineWOHex);

        //qDebug() <<CRC8<<hexCRC8;
       // = QString("%1").arg(CRC8,8,16);
       // sprintf(CRC8Convert,"%X",CRC8);
        //qDebug() <<CRC8<<line.mid(pos2+1,pos1-1);
        //qDebug()<<hexCRC8;
      //  qDebug() <<CRC8Convert<<lineWOHex.toUtf8();
        //qDebug()<<line.mid(9,10);
        //std::cout << str;
        // str=line.mid(10,11);
        // if(str==)
        // qDebug()<<line.left((line.length()-2))<<HEX<<CRC8;
        //qDebug() << line.left(pos);

    }

}

//Widget z przyciskiem i polem tekstu
UARTRead::UARTRead(QWidget* parent) :QWidget(parent)
{
    QPushButton* buttonStart = new QPushButton(tr("Start"), this);
    QPushButton* buttonEnd = new QPushButton(tr("End"), this);
    this->text = new QTextEdit(tr("Dane z czujnika"), this);

    this->text->setGeometry(50, 30, 500, 250);
    buttonEnd->setGeometry(325, 300, 225, 30); //lewa gora dlugosc wysokosc
    buttonStart->setGeometry(50, 300, 225, 30);


    this->text->setReadOnly(true);
    //button->move(30, 50);
        // text->move()
    connect(buttonEnd, SIGNAL(clicked()), this, SLOT(EndProgram()));
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(StartTransmit()));
}


//Functions

void UARTRead::EditText(QString textToWrite) {
    this->text->append(textToWrite + "\t");
    //this->text->setText(textToWrite);
}

//Slots

void UARTRead::EndProgram() {
    //static_cast<QWidget*>(parent())->close();
    std::cout << std::endl << "Koniec programu" << std::endl;
    emit EmitClosing();
}

void UARTRead::StartTransmit() {
    std::cout << std::endl << "Nacisniecie szukania" << std::endl;
    emit EmitStartUART();
    //EditText("tak\t");
}

