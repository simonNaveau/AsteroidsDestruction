#include <QDebug>
#include "Spawner.h"
#include "ObstacleItem.h"
#include "Game.h"
#include "Explosion.h"
#include "LifeBonus.h"

extern Game *game; //there

Spawner::Spawner() : QObject() {

}

void Spawner::spawnIntermediateObstacle(qreal xParentCoordinate, qreal yParentCoordinate) {
    //Create explosion
    ObstacleItem *int1 = new ObstacleItem(1, 360, 2, xParentCoordinate, yParentCoordinate);
    ObstacleItem *int2 = new ObstacleItem(1, 120, 2, xParentCoordinate, yParentCoordinate);
    ObstacleItem *int3 = new ObstacleItem(1, 240, 2, xParentCoordinate, yParentCoordinate);
    game->getScene()->addItem(int1);
    game->getScene()->addItem(int2);
    game->getScene()->addItem(int3);
}

void Spawner::spawnSmallObstacle(qreal xParentCoordinate, qreal yParentCoordinate) {
    ObstacleItem *int1 = new ObstacleItem(2, 360, 2.5, xParentCoordinate, yParentCoordinate);
    ObstacleItem *int2 = new ObstacleItem(2, 120, 2.5, xParentCoordinate, yParentCoordinate);
    ObstacleItem *int3 = new ObstacleItem(2, 240, 2.5, xParentCoordinate, yParentCoordinate);
    game->getScene()->addItem(int1);
    game->getScene()->addItem(int2);
    game->getScene()->addItem(int3);
}

void Spawner::spawnLifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate) {
    LifeBonus *bonus = new LifeBonus(lchange, xParentCoordinate, yParentCoordinate);
    game->getScene()->addItem(bonus);
}

void Spawner::spawnBigObstacle() {
    ObstacleItem *obsta = new ObstacleItem(0, 0, 0, 0, 0);
    game->getScene()->addItem(obsta);
}

void Spawner::showExplosion(qreal xParentCoordinate, qreal yParentCoordinate) {
    Explosion *explo = new Explosion(xParentCoordinate, yParentCoordinate);
    game->getScene()->addItem(explo);

}
