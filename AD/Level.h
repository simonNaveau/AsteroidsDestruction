#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    // constructor
    Level();

    // methods
    void setSucessTime(int);

    void setAsteroDmg(int);

    void setAsteroSpeed(int);

    void setAsteroSpawnFreq(int);

    int getSucessTime();

    int getAsteroDmg();

    int getAsteroSpeed();

    int getAsteroSpawnFreq();

private:
    // attributes
    int successTime;
    int asteroDmg;
    int asteroSpeed;
    int asteroSpawnFreq;
};

#endif // LEVEL_H
