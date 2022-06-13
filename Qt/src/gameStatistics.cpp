#include "gameStatistics.hpp"

/**
 * @brief Construct a new game Statistics Widget::game Statistics Widget object
 * 
 * @param[in] parent
 */
gameStatisticsWidget::gameStatisticsWidget(gameWindow* parent) {
    setupUi(this);
    gamePrmts = &(parent->gameParam);
    points = &(gamePrmts->accValues);
    chart = new QChart();
    layout = new QVBoxLayout(frameChart);
    chartView = new QChartView(chart);
    layout->addWidget(chartView);
    axis = new QValueAxis();
    axis->setRange(-50, 50);
    connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));

}
/**
 * @brief 
 * 
 */
void gameStatisticsWidget::retranslate() {
    retranslateUi(this);
}

/**
 * @brief 
 * 
 */
void gameStatisticsWidget::printChart() {
    chart->setTitle(tr("Sensor acceleration"));
    chart->addSeries(points);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).back()->setRange(-10, 10);
    chart->axes(Qt::Horizontal).back()->setTitleText("Time [s]");
    chart->axes(Qt::Vertical).back()->setTitleText("Acceleration Y [m/s^2]");
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(frameChart);
    ballVelLab->setText(QString::number(gamePrmts->averageBallVel));
    bouncingLable->setText(QString::number(gamePrmts->ballBounceNumber));
    gameTimeLable->setText(gamePrmts->gameTime);
}

/**
 * @brief 
 * 
 */
void gameStatisticsWidget::on_returnButton_clicked() {
    emit EmitChangeWidget();
    chart->removeSeries(points);
    points->clear();
}