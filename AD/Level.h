#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    // constructor
    Level();

    // methods
    void setLevelTime(int newTime);

    void setAsteroDmg(int newAsteroDmg); // not used

    void setAsteroSpeed(int newAsteroSpeed); // not used

    void setAsteroSpawnFreq(int newAsteroSpawnFreq);

    int getLevelTime();

    int getAsteroDmg(); // not used

    int getAsteroSpeed(); // not used

    int getAsteroSpawnFreq();

private:
    // attributes
    int levelTime;
    int asteroDmg; // not used
    int asteroSpeed; // not used
    int asteroSpawnFreq;
};

#endif // LEVEL_H
