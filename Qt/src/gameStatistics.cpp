#include "gameStatistics.hpp"

gameStatisticsWidget::gameStatisticsWidget(){
    setupUi(this);
}

void gameStatisticsWidget::on_returnButton_clicked(){
    emit EmitChangeWidget();
}