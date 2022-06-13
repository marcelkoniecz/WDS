#include "sideWidget.hpp"

/**
 * @brief Konstruktor panela bocznego aplikacji 
 * 
 * @param[in] parent -- wskaźnik na  klasę widgeta zawierającego grę oraz panel boczny
 * @param[in] gameWin -- wskaźnik na klasę okna głównego aplikacji
 * 
 * Konstruktor przyjmuje jako parametry wskaźniki adresy do głownego okna programu oraz 
 * widgetu zawierającego grę oraz panel boczny. 
 * Początkowo jest ustawiany adres wskaźnika na timer który będzie wyświetlany 
 * na panelu bocznym. Następnie jest ustawiany wskaźnik na klase odpowiedzialną za 
 * połączenie z mikrokontrolerem w celu sprawdzania czy połączenie jest aktywne oraz 
 * wskaźnik na wartości z paramentrami gry. Jako kolejne zostaje wywołane setupUi oraz 
 * połączenie sygnałów pochodzących od przycisków na penelu bocznym oraz sygnałów z okna
 * głównego takich jak sygnał wyzerowania sygnału, przetłumaczenia widgeta czy zablokowania 
 * przycisków
 */
SidePanelWidget::SidePanelWidget(mainWidget* parent, gameWindow* gameWin) {
  timer = parent->gameTimer;
  gamePar = &(gameWin->gameParam);
  gameUART = &(gameWin->gameInfo);
  accTime.setHMS(0, 0, 0);
  setupUi(this);
  pauzeGame->setText("Start");
  lineEdit->setReadOnly(true);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
  connect(pauzeGame, SIGNAL(clicked()), this, SLOT(writeTime()));
  connect(endGame, SIGNAL(clicked()), this, SLOT(EndGame()));
  connect(exitAplication, SIGNAL(clicked()), this, SLOT(EndProgram()));
  connect(gameWin, SIGNAL(EmitRestartGame()), this, SLOT(setTimerNull()));
  connect(gameWin, SIGNAL(EmitRetranslate()), this, SLOT(retranslatePanel()));
  connect(gameWin, SIGNAL(EmitBlockButtons()), this, SLOT(checkBlockButtons()));
}

/**
 * @brief Slot blokowania przycisków
 * 
 * Slot jest wywyoływany przez sygnał EmitBlockButtons() który jest emitowany przez okno 
 * główne aplikacji. W chwili wywołania następuje sprawdzenie ustawień czy przyciski
 * powinny zostać zablokowane, jeśli tak to przyciski zostją zablokowane.
 */
void SidePanelWidget::checkBlockButtons() {
  if (gamePar->blockButtons) {
    pauzeGame->setEnabled(false);
    endGame->setEnabled(false);
  }
  else {
    pauzeGame->setEnabled(true);
    endGame->setEnabled(true);
  }
}

/**
 * @brief Slot przetłumaczenia widgeta
 * 
 * Slot jest wywoływany przez sygnał EmitRetranslate() który jest emitowny przez okno
 * główne aplikacji. W chwili wywołania następuje przetłumaczenie widgeta panela bocznego.
 * Slot nic nie zwraca
 */
void SidePanelWidget::retranslatePanel() {
  retranslateUi(this);
}

/**
 * @brief Slot zakończenia programu
 *  
 * Slot jest wywoływany w chwili naciśnięcia przycisku endGame. Powoduje wysłanie sygnału
 * EmitClosing() odpowiedzialnego za zamknięcie aplikacji. Slot nic nie zwraca.
 */
void SidePanelWidget::EndProgram() {
  std::cout << std::endl << "Koniec programu" << std::endl;
  emit EmitClosing();
}

/**
 * @brief Slot aktualizacji czasu
 * 
 * Slot jest wywoływany przez timeout timera. Jest on odpowiedzialny za ustawianie aktualnego
 * czasu na liczniku czasu gry. Slot nic nie zwraca.
 */
void SidePanelWidget::updateTime() {
  accTime = accTime.addMSecs(10);
  QString time_text = accTime.toString("hh:mm:ss");
  gamePar->gameTime = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
}

/**
 * @brief Slot sprawdzania połączenia z urządzeniem
 * 
 * Slot jest wywoływany przez sygnał 
 * Jest on odpowiedzialny za blokowanie przycisku startu gry.
 * Slot nic nie zwraca.
 * 
 */
void SidePanelWidget::checkConnection() {
  if ((gameUART->isConnected))
    pauzeGame->setEnabled(true);
  else
    pauzeGame->setEnabled(false);
}


/**
 * @brief Slot obługi przycisku Resume
 * 
 * Slot obsługi przycisku odpowiedzialny za zatrzymywanie i wznawianie aplikcji, wraz
 * z zmianą nazwy przycisku.
 */
void SidePanelWidget::writeTime() {
  checkBlockButtons();
  if (isStarted) {
    pauzeGame->setText("Resume");
    timer->stop();

    isStarted = 0;
  }
  else {
    pauzeGame->setText("Pauze");
    timer->start(10);
    isStarted = 1;
  }
}

/**
 * @brief Slot odpowiedzialny za wyzerowanie czasu zegara
 * 
 * Slot jest wywoływany przez sygnał EmitRestartGame() emitowany przez okno główne aplikacji.
 * Ustawia on wartość timera na 00:00:00. Slot nic nie zwraca.
 * 
 */
void SidePanelWidget::setTimerNull() {
  accTime.setHMS(0, 0, 0);
  QString time_text = accTime.toString("hh:mm:ss");
  lineEdit->setText(time_text);
}

/**
 * @brief Slot końca gry
 * 
 * Slot jest wywoływany w chwili kliknięcia przycisku Exit Application. 
 * Zeruje on wartość zegara oraz wysyła sygnał EmitEndGame().
 */
void SidePanelWidget::EndGame() {
  setTimerNull();
  isStarted = 0;
  timer->stop();
  emit EmitEndGame();
  checkBlockButtons();
}

