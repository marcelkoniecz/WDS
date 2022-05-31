#include "gameStatistics.hpp"

gameStatisticsWidget::gameStatisticsWidget(gameParameters* game) {


    setupUi(this);
    gameParam = game;
    //points = new QLineSeries();
   // for(int i=0;i<game->accValues.size();i++)
     //   qDebug()<<(gameParam->accValues.size());
   // qDebug()<<(&(game->accValues));
  // qDebug()<<gameParam->accValues->lowerSeries();
    points = &(gameParam->accValues);
    // qDebug()<<"tak";
    chart = new QChart();



}
void gameStatisticsWidget::printChart() {
    chart->setTitle("Plate acceleration");
    // chart->addSeries(points);
   // points->append(10, 5);
    //qDebug() << sizeof(points);
   /// points->append(11, 6);
   // qDebug() << sizeof(points);
    chart->addSeries(&(gameParam->accValues));
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    // qDebug() << type(points);
     //qDebug()<<"AA"<<game->accValues.type();
    QChartView* chartView = new QChartView(chart);
    QVBoxLayout* layout = new QVBoxLayout(frameChart);
    layout->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(frameChart);

}


void gameStatisticsWidget::on_returnButton_clicked() {
    emit EmitChangeWidget();
}