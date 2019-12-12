#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include "LifeChanger.h"
#include <QPropertyAnimation>

class Spaceship : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    int lifePoints;

    QPropertyAnimation animation;

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

    void launchAnimation();

    int operator+(LifeChanger *changer);

    qreal shipCenterX;
    qreal shipCenterY;

public slots:
    void moveAutoForward();

    void resetSpeed();

    void animate();

private:
    int speed;

    int animationState;

    QTimer *timer;

    QTimer *metronome;
};

#endif // SPACESHIP_H
