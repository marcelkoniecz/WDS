#include "mainWidget.hpp"

/**
 * @file
 *  @brief Definicje metod  klasy mainWidget
 *
 * Definicje metod  klasy mainWidget. Klasa mainWidget jest
 * klasą pochodą QWidgeta.
 */

 /**
  * @param[in] parent -- Wskaznik na klasę okna głównego aplikacji
  *
  * Konstruktor tworzący widget główny aplikacji, alokuje: timer gry, widget gry
  * oraz widget panelu bocznego.
  */
mainWidget::mainWidget(gameWindow* parent) {
  QHBoxLayout* whZarzadzca = new QHBoxLayout;
  gameTimer = new QTimer(this);
  gameTimer->start(10);
  gameTimer->stop();
  okienko = new mainGameWidget(this, parent);
  statystyki = new SidePanelWidget(this, parent);
  okienko->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  okienko->setMinimumSize(500, 500);
  statystyki->setMinimumSize(250, 500);
  statystyki->setMaximumSize(250, 500);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  whZarzadzca->addWidget(okienko);
  whZarzadzca->addWidget(statystyki);
  setLayout(whZarzadzca);
};

void mainWidget::updateTime() {
  //qDebug()<<"tak";
}

/**
 * @mainpage Dokumentacja projektu płytki sterowanej za pomocą akcelerometru
 * 
 * @author Marcel Konieczny
 * @date 13.06.2022
 * 
 * Dokumentacja projektu aplikacji okienkowej -- gry. Aplikacja powstała w celu
 * realizacji kursu Widzualizacja danych sensorycznych.
 * 
 * @section Opis  Opis programu
 * 
 * Aplikacja okienkowa na podstawie danych z akclerometru porusza platformą
 * gracza, w celu odbijania piłki. Aby wygrać rozgrywkę piłka musi\n zostać nie trafiona
 * przez platformę sterowaną przez komputer. Jeśli gracz nie trafi piłki to przegrywa.
 * 
 */