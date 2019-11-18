#ifndef LIFEBONUS_H
#define LIFEBONUS_H
#include "ObstacleItem.h"
#include "LifeChanger.h"

class LifeBonus: public LifeChanger, public ObstacleItem{
public:
    LifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem * parent=0);
};
#endif // LIFEBONUS_H
