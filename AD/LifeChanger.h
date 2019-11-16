#ifndef LIFECHANGER_H
#define LIFECHANGER_H
#include "Spaceship.h"

class LifeChanger {

public:
    LifeChanger(int lifeChange);
    void operator-(Spaceship * ship);
public:
    int lifeChange;
};

#endif // LIFECHANGER_H
