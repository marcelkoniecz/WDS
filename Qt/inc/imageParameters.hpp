#ifndef IMAGEPARAMETERS_HPP
#define IMAGEPARAMETERS_HPP

/**
 * 
 * @file
 * @brief 
 * 
 */

/**
 * @brief 
 * 
 */
class imageParameters {
public:
    double ballSpeed;
    double plateSpeed = 0.25;
    int remainingUserLives;
    int remainingCompLives;
    double XtargetComPlate;
    double userPlateLoc[2][2];//
    double comPlateLoc[2][2];
    double ballPos[2];  //x y
    double currentAngle;
    double newScala;
};




#endif