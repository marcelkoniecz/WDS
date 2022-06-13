#include "gameStatistics.hpp"

/**
 * @brief Konstruktor widgetu statystyk
 *
 * @param[in] parent --Wskaźnik na klasę okna głównego aplikacji
 * 
 * Konstruktor kopiuje adres wskaźnika statystyk gry do pola klasy - gamePrmts 
 *  oraz za pomocą setupUi tworzy widget stworzony w qtDesignerze. Zostaje także 
 * dodany wykres wraz z ustawieniem odpowiedniego layouta oraz konfiguracjć osi.
 * Na końcu następuje połączenie sygnału przetłumaczenia z wywołaniem slotu retlasate().
*/
gameStatisticsWidget::gameStatisticsWidget(gameWindow* parent) {
    setupUi(this);
    gamePrmts = &(parent->gameParam);
    points = &(gamePrmts->accValues);
    chart = new QChart();
    QVBoxLayout* layout = new QVBoxLayout(frameChart);
    chartView = new QChartView(chart);
    layout->addWidget(chartView);
    axis = new QValueAxis();
    axis->setRange(-50, 50);
    connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));

}
/**
 * @brief Slot zmiany języka
 *
 * Gdy klasa okna głównego wyśle sygnał że należy przeprowadzić translacje uruchomiony
 * zostaje poniższy slot. Slot nie przyjmuje żadnych parametrów oraz nic nie zwraca.
 */
void gameStatisticsWidget::retranslate() {
    retranslateUi(this);
    printChart();
}

/**
 * @brief Metoda odpowiedzialna za rysowanie wykresu
 * 
 * Metoda klasy gameStatisticsWidget odpowiedzialna za rysowanie wykresu,
 * jest wywoływana za każdym razem kiedy następuje zmiana widgetu głownego na widget statystyk
 * Rysuje na wykresie dane z poprzedniej gry. Metoda nie przyjmuje argumentów i nic nie zwraca.
 */
void gameStatisticsWidget::printChart() {
    chart->setTitle(tr("Sensor acceleration"));
    chart->addSeries(points);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).back()->setRange(-10, 10);
    chart->axes(Qt::Horizontal).back()->setTitleText(tr("Time [s]"));
    chart->axes(Qt::Vertical).back()->setTitleText(tr("Acceleration Y [m/s^2]"));
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(frameChart);
    ballVelLab->setText(QString::number(gamePrmts->averageBallVel));
    bouncingLable->setText(QString::number(gamePrmts->ballBounceNumber));
    gameTimeLable->setText(gamePrmts->gameTime);
}

/**
 * @brief Slot obsługujący kliknięcie przycisku return
 *
 * Slot jest wywoływany podczas naciśnięcia przycisku return,
 * wysyła się wtedy sygnał do okna głównego aby wrócić do widgeta gry
 */
void gameStatisticsWidget::on_returnButton_clicked() {
    emit EmitChangeWidget();
    chart->removeSeries(points);
    points->clear();
}