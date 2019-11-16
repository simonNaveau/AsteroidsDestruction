#include "LifeChanger.h"
#include <QDebug>
#include "Game.h"

extern Game * game; //there

LifeChanger::LifeChanger(int lifeChange){
    this->lifeChange = lifeChange;
}

void LifeChanger::operator-(Spaceship * ship){
    if(ship->getLife()-this->lifeChange >= 0){
        ship->lifePoints = ship->lifePoints-this->lifeChange;
        game->health->setHealth(ship->getLife());
    }
}

