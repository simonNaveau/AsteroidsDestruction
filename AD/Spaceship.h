#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class Spaceship: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int lifePoints;

    Spaceship(int startingLifePoints, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void rotateRight();
    void rotateLeft();
    void moveBackward();
    void decreaseLife(int change);
    void increaseLife(int change);
    int getLife();
public slots:
    void moveAutoForward();
    void resetSpeed();
private:
    int speed;
    QTimer * timer;
};

#endif // SPACESHIP_H
