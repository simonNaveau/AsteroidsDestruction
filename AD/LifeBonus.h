#ifndef LIFEBONUS_H
#define LIFEBONUS_H

#include "ObstacleItem.h"
#include "LifeChanger.h"

class LifeBonus :public ObstacleItem, public LifeChanger  {
    Q_OBJECT
public:
    LifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent = nullptr);
    ~ LifeBonus();
private:
    int animationCount;
    QTimer * animationTimer;

public slots:
    void animation();
};

#endif // LIFEBONUS_H
