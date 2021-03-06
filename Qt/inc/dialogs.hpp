#ifndef DIALOGS_HPP
#define DIALOGS_HPP

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
#include "ui_disDialog.h"
#include "ui_conDialog.h"
#include "ui_endGameDialog.h"
#include "ui_settDialog.h"
#include "gameSettings.hpp"
#include "gameWindow.hpp"

/**
 * @file
 * @brief Plik nagłówkowy zawierający okna dialogowe
 *
 * Plik zawierający okna dialogowe aplikacji
 */

class gameWindow;

/**
 * @brief Klasa reprezentująca dialog ustawień
 *
 * Klasa reprezentująca dialog ustawień, dialog ten ukazuje się podczas wykonania
 * akcji wybierania ustawień
 */
class settDialog :public QDialog, public Ui::settDialog {
    Q_OBJECT
private:
    /**
     * @brief Wskaźnik na pole ustawień gry
     *
     * W konstruktorze polu temu zostaje przypisany adres na główne usty 
     * znajdujące się w oknie głównym aplikacji
     */
    gameSettings* ptrGameSett;

public:
    /**
     * @brief Konstruktor dialogu ustawień
     */
    settDialog(gameWindow* parent = nullptr);
    /**
     * @brief Metoda ładowania parametrów ustawień
     */
    void loadParam();
public slots:
    /**
      * @brief Slot obsługujący klikniecie przycisku Save
     */
    void on_saveButton_clicked();
    /**
     * @brief Slot obsługujący kliknięcie przycisku return
     */
    void on_returnButton_clicked();
    /**
     * @brief Slot zmiany języka
     */
    void retranslate();
signals:
    /**
     * @brief Sygnał zapisanie ustawień
     *
     * Sygnał wysyłany podczas wciśnięcia przycisku zapisz, informuje on okno główne
     * że należy na nowo sprawdzić wczytaną konfiguracje aplikacji.
     */
    void EmitSettingsSaved();


};


/**
 * @brief Klasa reprezentująca dialog końca gry
 *
 * Klasa reprezentujący dialog końcowy, ukazuje się on podczas zakończenia gry.
 */
class endDialog :public QDialog, public Ui::endGameDialog {
    Q_OBJECT
private:

public:
    /**
     * @brief Konstruktor dialogu końca gry
     */
    endDialog(gameWindow* parent = nullptr);
public slots:
    /**
     * @brief Slot kliknięcia przycisku statystyk
     */
    void on_statisticsButton_clicked();
    /**
     * @brief Slot kliknięcia przycisku Restart
     */
    void on_restartButton_clicked();
    /**
     * @brief Slot kliknięcia przycisku Restart
     */
    void on_exitButton_clicked();
    /**
     * @brief Slot zmiany języka
     */
    void retranslate();
signals:
    /**
     * @brief Sygnał zamknięcia aplikacji
     *
     * Sygnał wysłany podczas wciśnięcia przycisku zamknij aplikację, po wysłaniu
     * sygnału aplikacja okienkowa się zamyka.
     */
    void EmitClosing();

    /**
     * @brief Sygnał restartu gry
     *
     * Sygnał wysłany podczas naciśnięcia przycisku reset, po wysłaniu sygnału gra
     * zaczyna się od nowa (resetuje).
     */
    void EmitRestartGame();

    /**
     * @brief Sygnał otworzenia statystyk
     *
     * Sygnał wysłany podczas naciśnięcia przycisku statystyki, po wysłaniu sygnału
     * zmieniany jest widget główny okna gry, i można zobaczyć statystyki gry.
     */
    void EmitOpenStatistics();
};

/**
 * @brief Klasa reprezentująca dialog rozłączenia
 *
 * Klasa reprezentująca dialog rozłączenia, ukazuje się po wybraniu opcji z belki głównej.
 */
class disDialog :public QDialog, public Ui::disDialog {
    Q_OBJECT
public:
    /**
     * @brief Konstruktor dialogu rozłączenia

     */
    disDialog(gameWindow* parent = nullptr);
    /**
     * @brief Metoda wyświetlająca dany stan połączenia
     */
    void StartDialog(QString connectedDev);
public slots:
    /**
     * @brief Slot rozłączania podłączonego urządzenia
     */
    void on_disconnectButton_clicked();
    /**
     * @brief Slot powrotu
     */
    void on_cancelButton_clicked();
    /**
     * @brief Slot zmiany języka
     */
    void retranslate();
signals:
    /**
     * @brief Sygnał rozłączenia urządzenia
     *
     * Sygnał wysyłany podczas wciśnięcia przycisku rozłączenia, po wysłygnału 
     * gra rozłącza się z aktualnie połączonym mikrokontrolerem.
     */
    void EmitDisconnectDevice();

};

/**
 * @brief Klasa reprezentująca dialog połączenia
 *
 * Klasa reprezentująca dialog połączenia, ukazuje się podczas wybrania opcji  "connecitvity"
 * z belki menu.
 *
 */
class conDialog :public QDialog, public Ui::conDialog {
    Q_OBJECT
        /**
         * @brief Pole reprezentujące dostępy 
         *
         * Pole reprezentujące dostępne porty do komunikacji z aplikacją, do listy są
         * zapisywane wyszukane nazwy podłączonych urządzeń do portów komputera.
         */
        QList<QSerialPortInfo> portList;
public:
    /**
     * @brief Construct a new con Dialog object
     */
    conDialog(gameWindow* parent = nullptr);
public slots:
    /**
    * @brief Slot wyszukania dostępnych urządzeń
     */
    void on_searchDeviceButton_clicked();
    /**
     * @brief Slot kliknięcia przycisku cancel
     */
    void on_cancelButton_clicked();
    /**
     * @brief  Slot połączenia z urządzenia
     */
    void on_connectButton_clicked();
    /**
     * @brief Slot zmiany języka
     */
    void retranslate();

signals:
    /**
     * @brief Sygnał wybranego urządzenia do połąnia 
     *
     * Sygnał wysyłany do okna głównego z nazwą urządzenia z którym urzytkownik
     * chce się połączyć.
     * @retval QString --nazwa urzadzenia z którym urzytkownik chce się połączyć
     */
    void EmitChoosenDev(QString);

};

#endif