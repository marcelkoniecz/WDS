#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

enum gameDifficulty { easy, medium, hard };
enum applicationLanguage { english, polish };

class gameSettings {
    gameDifficulty gamelvl = easy;
    applicationLanguage language = english;
    int lifes = 1;
    bool randomBouncing = true;
    bool randomBallSpeed = false;
};


#endif 