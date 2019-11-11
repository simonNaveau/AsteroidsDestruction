#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
class Spawner:public QObject{
    Q_OBJECT
public:
    Spawner();
    void spawnIntermediateObstacle(qreal xParentCoordinate, qreal yParentCoordinate);
    void spawnSmallObstacle(qreal xParentCoordinate, qreal yParentCoordinate);

public slots:
    void spawnBigObstacle();

};

#endif // SPAWNER_H
