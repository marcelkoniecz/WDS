#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

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
#include "gameParameters.hpp"
#include "gameSettings.hpp"
#include "imageParameters.hpp"

/**
 * @file
 * @brief Plik nagłówkowy klasy mainGameWidget
 *
 * Plik nagłówkowy klasy mainGameWidget która odpowiada za poruszanie gry.
 */

class UARTVal;
class mainWidget;
class gameWindow;


//Pole gry
/**
 * @brief Klasa reprezentująca widget gry
 *
 * Klasa reprezentująca widget gry. Klasa oblicza położenia oraz przemieszcza piłki 
 * oraz płytek.
 */
class mainGameWidget :public QWidget {
    Q_OBJECT
private:
    /**
     * @brief Pole zawierające obraz tła
     *
     * Pole przedstawiające tło gry.
     */
    QImage background;
    /**
     * @brief Pole zawierające obraz płytki komputera
     *
     * Pole zawierające obraz płytki komputera. Zostaje ona wczytana w konstruktorze.
     */
    QImage computerPlate;
    /**
     * @brief Klasa zawierająca informacje na temat gry
     *
     * Klasa zawierająca informacje na temat gry. Zostają one wykorzystane podczas poruszania
     * poszczególnych obrazów.
     */
    imageParameters imgParam;
    /**
     * @brief Pole zawierające obraz płytki gracza
     *
     * Pole zawierające obraz płytki gracza. Zostaje ona wczytana w konstruktorze.
     */
    QImage userPlate;
    /**
     * @brief Pole zawierające obraz piłkii
     *
     * Pole zawierające obraz piłki, którą toczy się gra. Zostaje ona wczytana w konstruktorze.
     */
    QImage ball;
    /**
     * @brief Pole zawierające obraz serca
     *
     * Pole zawierające obraz serca. Zostaje ona wczytana w konstruktorze.
     */
    QImage life;
    /**
     * @brief Wskaźnik na klasę UART
     *
     * Wskaźnik na klasę związaną z pobieraniem danych za pomocą UART-u, w kontruktorze zostaje
     * przypisany adres klasy UART z klasy okna głównego. Pole jest wykorzystywane podczs 
     * poruszania platformy gracza.
     */
    UARTVal* gameInfo;
    /**
     * @brief Wskaźnik na zega 
     *
     * Wskażnik na zegar, w kontruktorze zostaje przypisany adres zegara z widgetu głównego
     *  aplikacji. Za jego pomocą występują timeouty które aktualizują klatki gry.
     */
    QTimer* gameTimer;
    /**
     * @brief Wskaźnik na statystyki gry
     *
     * Wskaźnik na statystyki grym podczas inicjalizacji w konstruktorze zostaje przypisany
     * adres statystyk z klasy okna głównego.
     */
    gameParameters* gameParam;
    /**
     * @brief Wskaźnik na ustawienia gry
     *
     * Wskaźnik na ustawienia gry, podczas inicjalizacji w konstruktorze zostaje przypisane adres
     * ustawienień gry z klasy okna głównego.
     */
    gameSettings* gameSettgs;
    /**
     * @brief Pole odpowiedzialne za liczenie czasu
     *
     * Pole odpowiedzialne za liczenie upływającego czasu, używane w celu prezentowania
     * punktów na wykresie.
     */
    double timerun;
public:
    /**
     * @brief Konstruktor klasy widgetu gry
     *
     * @param parent wskaźnik na widget główny aplikacji
     * @param gameWin Wskaźnik na okno główne aplikacji
     *
     *
     */
    mainGameWidget(mainWidget* parent = nullptr, gameWindow* gameWin = nullptr);

    /**
     * @brief Metoda aktualizacji widgeta
     *
     * @param ptr QPaintEvent
     *
     * Metoda odpowiedzialna za aktualizację widgeta.
     */
    void paintEvent(QPaintEvent* ptr);
    /**
     * @brief Metoda odpowiedzialny za "krok" gry
     *
     * Metoda odpowiedzialna za wywołanie wszystkich odpowiednich metod pozwalających
     * na poruszanie się piłki, platform. Wywołuje metody sprawdzające czy występuje odbicie,
     * koniec gry.
     */
    void makeGameStep();
    /**
     * @brief Metoda wyliczająca pozycję piłki 
     *
     * Metoda odpowiedzialna za wyliczenie pozycji piłki, parametry (np. prędkość), są pobierane
     * z pola informacji o obrazach.
     */
    void calculateBallPosition();
    /**
     * @brief Metoda  wyliczająca położenie płytki gracza
     *
     * Metoda odpowiedzialna za wyliczenie położenia płytki gracza, przemieszczenie płytki
     * jest obliczone na podstawie danych otrzymanych z akcelerometru (pole gameInfo).
     */
    void calculateUserPlate();
    /**
     * @brief Metoda wyliczająca położenia płytki komputera
     *
     * Metoda odpowiedzialna za wyliczenie położenie płytki komputera. Początkowo wyznaczana jest pozycja docelowa platformy
     * ,następnie uwzględniając poziom trudności wybrany przez gracza w ustawieniach następuje
     * przemieszczenie płytki z odpowiednią prędkością.
     */
    void calculateComPlatePosition();
    /**
     * @brief Metoda sprawdzająca czy nastąpiło odbicie od płytki
     *
     * Metoda odpowiedzialna za sprawdzenie czy wystąpiło odbicie od jednej z płytek.
     * Jeśli wystąpiło odbicie obliczna jest wartość kąta w jakim powinna się poruszać piłka
     * po odbiciu (pole currentAngle klasy imageParameters).
     */
    void calculateIfBouncedPlate();
    /**
     * @brief Metoda sprawdzająca czy nastąpiło odbicie od ściany
     *
    * Metoda odpowiedzialna za sprawdzenie czy wystąpiło odbicie od jednej z ścian.
     * Jeśli wystąpiło odbicie obliczna jest wartość kąta w jakim powinna się poruszać piłka
     * po odbiciu (pole currentAngle klasy imageParameters).
     */
    void calculateIfBouncedWall();
    /**
     * @brief Metoda sprawdzająca czy nastąpił koniec gry.
     *
     * Metoda odpowiedzialna za sprawdzenie czy nastąpił koniec gry, jeżeli wystąpił koniec gry
     * metoda wysyłą sygnał o końcu gry.
     */
    void calculateIfEndGame();
    /**
     * @brief
     *

     */
    void initValues();


    void resetPosition();
public slots:
    /**
     * @brief Slot wywoływany przez timer
     *
     * Slot wywoływany za pomocą timeout() pochodzących od timera. W slocie wywołana 
     * jest metoda makeGameStep().
     */
    void updateTime();
signals:
    /**
     * @brief Sygnał końca gry
     *
     * Sygnał końca gry, emitowany podczas gdy jeden z graczy przegra rozgrywkę.
     */
    void EmitEndGame();
    /**
     * @brief Sygnał zatrzymania gry
     * 
     * Sygnał zatrzymania gry, emitowany podczas gdy jeden z graczy straci życie.
     */
    void EmitPauzeGame();

};


#endif