#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP
/**
 * @file 
 * @brief Definicja ustawień gry
 * 
 * Plik zawierający klase z ustawieniami gry
 */



/**
 * @brief Poziom trudności gry
 *
 * Wartości tego typu służą do określenia poziomu gry
 */
enum gameDifficulty {
    easy /*! Łatwy poziom gry*/,
    medium /*!Średni poziom gry*/,
    hard /*!Trudny poziom gry*/
};

/**
 * @brief Wybór języka
 *
 * Wartość tego typu służą do określenia języka gry
 */
enum applicationLanguage {
    english /*! Angielski język gry*/,
    polish /*!Polski język gry*/
};

/**
 * @brief Klasa zawierająca informacje na temat ustawień gry
 *
 * Klasa przechowująca informacje na teamt ustawień gry
 */
class gameSettings {
public:
    /**
     * @brief Pole typu enum okreslające poziom gry
     * 
     * Pole opisuje poziom gry
    */
    volatile gameDifficulty gamelvl = hard;
    /**
     * @brief Pole typu enum określające język gry
     * 
     * Pole opisujące język gry
     */
    applicationLanguage language = english;
    /**
     * @brief Pole zawierające infromacje an temat ustawień ilości żyć
     * 
     * Pole zawiera informacje na temat ustawień ilości żyć 
     */
   volatile int lifes = 1;
    /**
     * @brief Pole określajace losowe odbijanie 
     * 
     * @retval true -- Piłka będzie się odbijać z losowymi kątami 
     * @retval false -- Piłka będzie się odbijać normlanie
     * 
     */
   volatile bool rndBcnPlts = false; //Random plates bouncing
    /**
     * @brief Pole określające losowe prędkości piłki
     * 
     * @retval true -- Piłka podczas odbicia będzie zmieniała swoją prędkość w sposób losowy
     * @retval false -- Piłka podczas odbicia nie będzie zmieniała prędkości
     */
    volatile bool randomBallSpeed = false;
};


#endif 