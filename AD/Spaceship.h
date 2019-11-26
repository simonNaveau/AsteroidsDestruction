#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include "LifeChanger.h"

class Spaceship : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    int lifePoints;

    Spaceship(int startingLifePoints, QGraphicsItem *parent = nullptr);

    ~ Spaceship();

    void keyPressEvent(QKeyEvent *event);

    void rotateRight();

    void rotateLeft();

    void moveBackward();

    void decreaseLife(int change);

    void increaseLife(int change);

    int getLife();

    void checkBonusCollision();

    void setLife(int newLifePoints);

    void reset();

    int operator+(LifeChanger *changer);

public slots:
    void moveAutoForward();

    void resetSpeed();

private:
    int speed;

    QTimer *timer;
};

#endif // SPACESHIP_H
