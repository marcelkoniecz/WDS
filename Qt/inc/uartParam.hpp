#ifndef UARTPARAM_HPP
#define UARTPARAM_HPP
#include <QString>
/**
 * @file
 * @brief Definicja klasy UARTVal
 *
 * Plik nagłówkowy z  strukturą odpowiedzialną za zapisywanie do niej danych otrzymanych
 * poprzez połączenie UART
 */

 /**
  * @brief Klasa zawierajaca informacje na temat gry
  */
class UARTVal {
public:
  /**
   * @brief  Pole nazwy podlaczonego urzadzenia
   */
  QString devName;

  double XVal = 0;
  /**
   * @brief Pole wartosci y odczytanej z akcelerometru
   */
  double YVal = 0;
  /**
   * @brief Pole wartosci z odczytanej z akcelerometru
   */
  double ZVal = 0;

  /**
   * @brief Pole typu bool reprezentujaca czy urzadzenie jest podlaczone
   * @retval true Urządzenie jest podłączone
   * @retval false Urzadzenie nie jest podlaczone
   */
  bool isConnected = 0;  //If device is connected

};



#endif