#ifndef GAMEPARAMETERS_HPP
#define GAMEPARAMETERS_HPP

#include <QList>
#include <QLineSeries>
#include <QtCharts>

class gameParameters {
public:
    int isGameActice = -1;
    int ballBounceNumber = 0;
    int averageBallVel = 1;
   // QList<int> accValues;
    QLineSeries accValues;
 //   gameParameters() { accValues = new QLineSeries; }

};




#endif 