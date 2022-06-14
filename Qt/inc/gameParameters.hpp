#ifndef GAMEPARAMETERS_HPP
#define GAMEPARAMETERS_HPP

#include <QList>
#include <QLineSeries>
#include <QtCharts>
/**
 *  @file
 *  @brief Definicja klasy gameParameters
 *
 * Plik zawierający statystyki gry oraz aktualny stan rozgrywki
 */



 /**
  * @brief Klasa zawierająca informacje na temat statystyk gry
  *
  * Klasaprzechowująca informacje na temat statystyk gry o 
  * wskazniki na temat czy gra jest aktywna
  */
class gameParameters {
public:
  /**
   * @brief Pole zawiera informacje na temat czy gra jest aktywna
   *
   * Pole zawiera infromację czy gra jest aktywna jest to przydatn 
   * momencie gdy użytkownik naciśnie przycisk pauzy
   *@retval true Gra jest aktywna
   *@retval false Gra jest nie aktywne
   */
  bool isGameActive = false;
  /**
   * @brief Pole zawiera informacje czy należy przeprowadzić reset pozycji
   *
   * Pole zawiera informację czy należy przeprowadzić reset pozycji, jest
   * to przydatne w momencie gdy jeden z graczy stracił życie, lub końca gry
   *
   * @retval true Należy przeprowadzić reset pozycji
   * @retval flase Nie należy przeprowadzać resetu pozycji
   */

  bool resetPosition = true;
  /**
   * @brief Pole zawierające informację czy należy zablokować przyciski panelu bocznego
   *
   * Pole zawiera informację czy należy zablokować przyciski panelu bocznego
   * jest to przydatne w chwili konca gry gdy pojawia się dialog końca gry
   *
   * @retval  true Należy zablokować przyciski boczne
   * @retval flase Nie należy blokowac przycisków bocznych
   *
   */
  bool blockButtons = false;
  /**
   * @brief Pole zawierające informację czy należy zmienić prędkość piłki
   *
   * Pole zawierające informację czy użytkownik zdecydował się przyśpieszyć lub zwolnić piłkę
   *
   * @retval -1 Użytkownik zdecydował się zwolnić piłkę
   * @retval 0 Użytkownik nie ingeruje w prędkość piłki
   * @retval 1  Użytkownik przyśpiesza piłkę
   */

  volatile int setBallSpeed = 0;

  //Statystyki koncowe
  /**
   * @brief Pole zawierające aktualny czas gry w formacie QString
   *
   * Pole zawierające aktualny czas gry w formacie QString, jest ono urzywa 
   * w celu wyświetlenia statysyk końcowych
   */
  QString gameTime;
  /**
   * @brief Pole zawierające informacje na temat ilości odbić piłki przez płytki
   *
   * Pole zawierające informację na teamt ilości odbić piłki przez płytki, przydate
   * w momencie końca gry gdy zostaje wyświetlana statystyka na ten temat
   *
   */
  int ballBounceNumber = 0;
  /**
   * @brief Pole zawierajace informacje na teamt średniej prędkości piłki
   *
   * Pole zawierające informacje na temat średniej prędkości piłki, aktualizowane
   * podczas każdego odbicia piłki od platformy, przydatne w momencie końca gry
   * gdy jest wyświetlana infromacja na temat statystyk końcowych.
   */
  double averageBallVel = 1;

  /**
   * @brief Pole zawierające informacje na temat danych odczytywanych z akcelerometru
   *
   * Pole zawierające informacje na temat danych odczytanych z akcelerometru or 
   * czasu w którym odpowiednie dane zostały odczytane. Na podstawie wartości 
   * znajdujących się w tym polu jest tworzony wykres w widgecie statyst. 
   */
  QLineSeries accValues;

};




#endif 