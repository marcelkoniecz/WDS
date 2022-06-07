#ifndef GAMEPARAMETERS_HPP
#define GAMEPARAMETERS_HPP

#include <QList>
#include <QLineSeries>
#include <QtCharts>

class gameParameters {
public:
    bool isGameActive = false;
    bool resetPosition = true;
    bool blockButtons = false;
    QString gameTime;

    //Statystyki koncowe
    int ballBounceNumber = 0;
    int averageBallVel = 1;
    QLineSeries accValues;

};




#endif 