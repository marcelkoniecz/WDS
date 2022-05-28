#ifndef GAMEPARAMETERS_HPP
#define GAMEPARAMETERS_HPP

#include <QList>


class gameParameters {

    int isGameActice = -1;
    int ballBounceNumber = 0;
    int averageBallVel = 1;
    QList<double> accValues;

};




#endif 