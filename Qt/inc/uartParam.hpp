#ifndef UARTPARAM_HPP
#define UARTPARAM_HPP
#include <QString>
/**
 * @file
 * @brief Plik nagłówkowy z strukturą na temat UART 
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
    /**
     * @brief Pole predkosc pilki
     */
 //   double ballVel;
    /**
     * @brief Pole predkosc plytki gracza
     */
////    double userPlateVel;
    /**
     * @brief Pole predkosc plytki sterowanej przez komputer
     */
//    double comPlateVel;
    /**
     * @brief Pole warotsci x odczytanej z akcelerometru
     */
    double XVal;
    /**
     * @brief Pole wartosci y odczytanej z akcelerometru
     */
    double YVal;
    /**
     * @brief Pole wartosci z odczytanej z akcelerometru
     */
    double ZVal;
    
    int ballBounced = 0;
    int ballAverageSpeed = 0;
    /**
     * @brief  Pole typu bool reprezentujaca kierunek poruszania sie pilki
     *  Dla wartosci rownej 1 pilka porusza sie do gory
     *  Dla wartosci rownej 0 pilka porusza sie w dol
     */
    int ballDirection = 1; //dir = 0 bottom, dir = 1 top
   /**
    * @brief Pole typu bool reprezentujaca czy gra sie aktualnie toczy
    * @retval false Gra jest nieaktywna
    * @retval true  Gra jest aktywna
    */
    bool isGameActive = 0; //If game is started
    /**
     * @brief Pole typu bool reprezentujaca czy urzadzenie jest podlaczone
    * @retval true Urządzenei jest podłączone
     * @retval false Urzadzenie nie jest podlaczone
     */
    bool isConnected = 0;  //If device is connected
    /**
     * @brief Funkcja obliczajaca predkosc plytki urzytkownika
     *
     */
    bool resetPosition = false;
    
//  //   void calculateVel() {
//  //       if (ZVal < 8 || ZVal>10)
//             ballVel = ballVel * ZVal / 9.81;
//         userPlateVel = userPlateVel * YVal / 9.81;

//     }
};



#endif