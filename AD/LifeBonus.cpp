#include "LifeBonus.h"
#include "Game.h"
#include <QDebug>

extern Game *game; //there

LifeBonus::LifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent)
         : ObstacleItem(0, 0, 0, xParentCoordinate, yParentCoordinate, parent), LifeChanger(lchange)  {
    animationTimer = new QTimer();
    setPixmap(QPixmap(":/images/bonus0.png"));
    animationCount = 0;
    setPos(xParentCoordinate, yParentCoordinate);
    getTimer()->stop();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animation()));
    animationTimer->start(70);
}

LifeBonus::~LifeBonus(){
    delete animationTimer;
}

void LifeBonus::animation(){
    animationCount++;
    if(animationCount>=4) animationCount = 0;
    QString image = QString(":/images/Bonus/bonus%1.png").arg(animationCount);
    setPixmap(QPixmap(image));
}
