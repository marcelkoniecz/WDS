#include "gameStatistics.hpp"

gameStatisticsWidget::gameStatisticsWidget(gameWindow* parent) {


    setupUi(this);
    gamePrmts =&(parent->gameParam);
    points = &(gamePrmts->accValues);
    chart = new QChart();
    layout = new QVBoxLayout(frameChart);
    chartView = new QChartView(chart);
    layout->addWidget(chartView);
    axis = new QValueAxis();
    axis->setRange(-50,50);
    connect(parent, SIGNAL(EmitRetranslate()), this, SLOT(retranslate()));

}

void gameStatisticsWidget::retranslate(){
    retranslateUi(this);
}

void gameStatisticsWidget::printChart() {
    chart->setTitle(tr("Sensor acceleration"));
    chart->addSeries(points);
   // chart->attachAxis(axis,Qt::AlignLeft);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).back()->setRange(-50, 50);
    chart->axes(Qt::Horizontal).back()->setTitleText("Time [s]");
    chart->axes(Qt::Vertical).back()->setTitleText("Acceleration Y [m/s^2]");


    //chart->legend()->setVisible(true);
  //  chart->legend()->setAlignment(Qt::AlignBottom);


    // qDebug() << type(points);
     //qDebug()<<"AA"<<game->accValues.type();
   
    
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(frameChart);
    ballVelLab->setText(QString::number(gamePrmts->averageBallVel));
    bouncingLable->setText(QString::number(gamePrmts->ballBounceNumber));
    gameTimeLable->setText(gamePrmts->gameTime);
}


void gameStatisticsWidget::on_returnButton_clicked() {
    emit EmitChangeWidget();
    chart->removeSeries(points);
    points->clear();
    //gamePrmts->accValues
}