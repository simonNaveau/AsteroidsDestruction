#ifndef OBSTACLEITEM_H
#define OBSTACLEITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class ObstacleItem: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ObstacleItem(int size, double angle, double speed, qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem * parent=0);
    ~ ObstacleItem();
    QTimer* getTimer();
    void setTimer(QTimer*);
    qreal spawnX;
    qreal spawnY;

//need QObject
public slots:
    void move();
    void constraintMove();
    int obstacleSize();
private:
    QTimer * timer;
    int size;
    double angle;
    double speed;
    void checkWallCollision();
    void checkSpaceshipCollision();
};

#endif // OBSTACLEITEM_H
