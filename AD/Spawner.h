#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>

class Spawner : public QObject {
    Q_OBJECT
public:
    Spawner();

    void spawnIntermediateObstacle(qreal xParentCoordinate, qreal yParentCoordinate);

    void spawnSmallObstacle(qreal xParentCoordinate, qreal yParentCoordinate);

    void spawnLifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate);

    void showExplosion(qreal xParentCoordinate, qreal yParentCoordinate);

public slots:
    void spawnBigObstacle();

};

#endif // SPAWNER_H
