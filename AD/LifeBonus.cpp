#include "LifeBonus.h"
#include "Game.h"
#include <QDebug>

extern Game * game; //there

LifeBonus::LifeBonus(int lchange,  qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent)
    :LifeChanger(lchange), ObstacleItem(0, 0, 0, xParentCoordinate, yParentCoordinate, parent){
    setPixmap(QPixmap(":/images/bonus.png"));
    setPos(xParentCoordinate, yParentCoordinate);
    getTimer()->stop();
}
