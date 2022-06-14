#ifndef IMAGEPARAMETERS_HPP
#define IMAGEPARAMETERS_HPP

/**
 *
 * @file
 * @brief Definicja klasy imageParameters
 *
 * Plik zawierający klasę z parametrami obrazów gry.
 */

 /**
  * @brief Klasa zawierająca parametry obrazów gry
  *
  * Klasa zawierająca parametry obrazów gry, jest używana w widgecie gry w celu
  * trwania aplikacji
  */
class imageParameters {
public:
    /**
     * @brief Pole reprezentujące prędkość piłki
     *
     *  Pole reprezentujące aktualną prędkość piłki.
     */
    double ballSpeed;
    /**
     * @brief Pole reprezentujące prękość płytki komputera
     *
     * Pole przechowuje informację z jaką prędkością może poruszać się płytka
     * sterowana przez komputer.
     */
    double plateSpeed = 0.25;
    /**
     * @brief Pole reprezentujące ile żyć posiada gracz
     *
     * Pole przechowuje informacje ile żyć posiada gracz, podczas skucia (piłka wypada
     * pod platformę) odejmowane jest 1 od wartości, jeśli wartość jest równa 0 nępuje 
     * koniec gry.
     */
    int remainingUserLives;
    /**
     * @brief Pole reprezentujące ile żyć posiada komputer
     *
     * Pole przechowuje informacje ile żyć posiada komputer, podczas skucia (piłka wypada
     * pod platformę) odejmowane jest 1 od wartości, jeśli wartość jest równa 0 nępuje 
     * koniec gry.
     */
    int remainingCompLives;
    /**
     * @brief Pole reprezentujące miejsce gdzie powinna znaleźć się płytka komputera
     *
     * Pole przechowuje informację o współrzędnej x, gdzie powinna znaleźć się płytka komputer,
     * cel jaki powinna ona osiągnąć.
     */
    double XtargetComPlate;
    /**
     * @brief Pole reprezentujące współrzędne płytki gracza
     *
     * Pole przechowuje informacje o 2 współrzędnych płytki gracza
     * @retval userPlateLoc[0][0] -- Współrzędna x lewego górnego rogu płytki
     * @retval userPlateLoc[1][0] -- Współrzędna x prawego górnego rogu płytki
    * @retval userPlateLoc[0][1] -- Współrzędna y górnej krawędzi płytki
    * @retval userPlateLoc[1][1] -- Współrzędna y dolnej krawędzi płytki
     */
    double userPlateLoc[2][2];//
    /**
     * @brief Pole reprezentujące współrzędne płytki komputera
     *
     * Pole przechowuje informacje o współrzędnych płytki sterowanej przez komputer
     * @retval userPlateLoc[0][0] -- Współrzędna x lewego górnego rogu płytki
     * @retval userPlateLoc[1][0] -- Współrzędna x prawego górnego rogu płytki
    * @retval userPlateLoc[0][1] -- Współrzędna y górnej krawędzi płytki
    * @retval userPlateLoc[1][1] -- Współrzędna y dolnej krawędzi płytki
     */
    double comPlateLoc[2][2];
    /**
     * @brief Pole reprezentujące współrzędne piłki
     *
     * Pole przechowuje informację na temat współrzędnych gdzie znajduje się piłka
     * @retval ballPos[0] -- Współrzędna x lewgo górnego rogu obrazka piłki
    * @retval ballPos[1] -- Współrzędna y lewgo górnego rogu obrazka piłki
     */
    double ballPos[2];  //x y
    /**
     * @brief Pole reprezentujące aktualny kąt w którym porusza się piłka
     *
     * Pole przechowujące aktualny kąt w którym porusza się aktualnie piłka.
     */
    double currentAngle;
    /**
     * @brief Pole reprezentujące skale tła
     *
     * Pole przechowujące informację na temat skali  obrazu tła.
     */
    double newScala;
};




#endif