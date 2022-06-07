#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

enum gameDifficulty { easy, medium, hard };
enum applicationLanguage { english, polish };

class gameSettings {
    public:
    gameDifficulty gamelvl = easy;
    applicationLanguage language = english;
    int lifes = 1;
    bool rndBcnPlts = true; //Random plates bouncing
    bool randomBallSpeed = false;
};


#endif 