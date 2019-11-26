#include "LifeChanger.h"
#include <QDebug>
#include "Game.h"

extern Game *game; //there

LifeChanger::LifeChanger(int lifeChange) {
    this->lifeChange = lifeChange;
}
