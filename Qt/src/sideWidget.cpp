#include "sideWidget.hpp"
/**
 * @file
 *  @brief Definicje metod  klasy SidePanelWidget 
 * 
 * Definicje metod oraz slotów klasy SidePanelWidget. Klasa SidePanelWidget jest
 * klasą pochodą QWidgeta.
 */


/**
 *
 * @param[in] parent -- wskaźnik na  klasę widget'u zawierającego grę oraz panel boczny
 * @param[in] gameWin -- wskaźnik na klasę okna głównego aplikacji
 *
 * Konstruktor przyjmuje jako parametry wskaźniki adresy do głownego okna programu oz 
 * widget'u zawierającego grę oraz panel bocz. 
 * Początkowo jest ustawiany adres wskaźnika na timer który będzie wyświlany 
 * na panelu bocznym. Następnie jest ustawiany wskaźnik na klase odpowiedzialną za 
 * połączenie z mikrokontrolerem, w celu sprawdzania czy połączenie jest aktywne oraz 
 * wskaźnik na wartości z paramentrami gry. Jako kolejne zostaje wywołane setupUi oraz 
 * połączenie sygnałów pochodzących od przycisków na penelu bocznym oraz sygnałów z okna
 * głównego takich jak sygnał wyzerowania sygnału, przetłumaczenia widget'u czy zablokowania 
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
  connect(parent->okienko, SIGNAL(EmitPauzeGame()), this, SLOT(pauzeGameFun()));
  connect(gameWin, SIGNAL(EmitPauzeGame()), this, SLOT(pauzeGameFun()));
}

/**
 * Slot jest wywoływany przez sygnał EmitPauzeGame() który jest emitowany przez widget gry (
 * podczas stracenia życia przez jednego gracza) i przez okno główne ekranu (podczas wywołania
 * jednego z dialogów).
 */
void SidePanelWidget::pauzeGameFun() {
  pauzeGame->setText(tr("Resume"));
  timer->stop();
  isStarted = 0;
}
/**
 * Slot jest wywyoływany przez sygnał EmitBlockButtons() który jest emitowany przez okno 
 * główne aplikacji. W chwili wywołania następuje sprawdzenie ustawień czy przyciski
 * powinny zostać zablokowane, jeśli tak to przyciski zostają zablokowane.
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
 * Slot jest wywoływany przez sygnał EmitRetranslate() który jest emitowny przez okno
 * główne aplikacji. W chwili wywołania następuje przetłumaczenie widget'u panela bocznego.
 * Slot nic nie zwraca
 */
void SidePanelWidget::retranslatePanel() {
  retranslateUi(this);
}

/**
 * Slot jest wywoływany w chwili naciśnięcia przycisku endGame. Powoduje wysłanie sygnału
 * EmitClosing() odpowiedzialnego za zamknięcie aplikacji. Slot nic nie zwraca.
 */
void SidePanelWidget::EndProgram() {
  std::cout << std::endl << "Koniec programu" << std::endl;
  emit EmitClosing();
}

/**
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
 * Metoda jest odpowiedzialna za blokowanie przycisku startu gry.
 * Metoda nic nie zwraca.
 */
void SidePanelWidget::checkConnection() {
  if ((gameUART->isConnected))
    pauzeGame->setEnabled(true);
  else
    pauzeGame->setEnabled(false);
}


/**
 * Slot obsługi przycisku odpowiedzialny za zatrzymywanie i wznawianie aplikcji, wraz
 * z zmianą nazwy przycisku.
 */
void SidePanelWidget::writeTime() {
  checkBlockButtons();
  if (isStarted) {
    pauzeGame->setText(tr("Resume"));
    timer->stop();
    isStarted = 0;
  }
  else {
    pauzeGame->setText(tr("Pauze"));
    timer->start(10);
    isStarted = 1;
  }
}

/**
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
 * Slot jest wywoływany w chwili kliknięcia przycisku Exit application. 
 * Zeruje on wartość zegara oraz wysyła sygnał EmitEndGame().
 */
void SidePanelWidget::EndGame() {
  setTimerNull();
  isStarted = 0;
  timer->stop();
  emit EmitEndGame();
  checkBlockButtons();
}


