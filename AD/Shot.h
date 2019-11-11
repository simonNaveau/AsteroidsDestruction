#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class Shot: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Shot(QGraphicsItem * parent=0);
    ~ Shot();
    double shotAngle;

//need QObject
public slots:
    void move();

private:
    QMediaPlayer * explosionSound;
    QTimer * timer;
    void checkObstacleCollision();

};

#endif // SHOT_H
