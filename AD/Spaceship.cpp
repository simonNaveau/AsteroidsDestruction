#include "Spaceship.h"
#include "ObstacleItem.h"
#include "Shot.h"
#include "LifeBonus.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Game.h"
#include <QDebug>
#include <QtMath>
#include <QTimer>

extern Game * game; //there

Spaceship::Spaceship(int startingLifePoints, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    lifePoints = startingLifePoints;

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveAutoForward()));
    timer->start(5);
}

Spaceship::~Spaceship(){
    timer->stop();
}

/**
 * @brief Spaceship::keyPressEvent Waiting to do actions on keys pressed
 * @param event
 */
void Spaceship::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        rotateLeft();
    } else if (event->key() == Qt::Key_Right){
        rotateRight();
    } else if (event->key() == Qt::Key_Space){
        //create a bullet
        Shot * shot = new Shot();
        // /!\ A changer: Trouver la formule pour faire partir les tirs du centre du vaisseau.
        shot->setPos(x()+(pixmap().width()/2)-shot->pixmap().width()/2,y()-shot->pixmap().height());
        scene()->addItem(shot);

        //Play sound
        game->soundBox->playShot();
    } else if (event->key() == Qt::Key_Up){
        speed = 8;
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(resetSpeed()));
        timer->start(100);
    }
}

/**
  Methods to make the spaceship move
    -> rotation Right
    -> rotation Left
    -> moveForward
 */
void Spaceship::rotateRight(){
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(rotation()+10);
}

void Spaceship::rotateLeft(){
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(rotation()-10);
}

void Spaceship::moveAutoForward(){
    double angle = rotation()-90;
    double dy = speed * qSin(qDegreesToRadians(angle));
    double dx = speed * qCos(qDegreesToRadians(angle));
    if(x()+dx+pixmap().width() <= scene()->width() && x()+dx >= 0 && y()+dy+pixmap().height() <= scene()->height() && y()+dy >=0 ){
        setPos(x()+dx,y()+dy);
    }
    checkBonusCollision();
}

void Spaceship::resetSpeed(){
    speed = 1;
    delete timer;
}

/**
  Life changing methods
   -> increase life
   -> decrease life
   -> get life
 */
void Spaceship::decreaseLife(int change){
    lifePoints -= change;
    game->health->setHealth(lifePoints);
}

void Spaceship::increaseLife(int change){
    lifePoints += change;
    game->health->setHealth(lifePoints);
}

int Spaceship::getLife(){
    return lifePoints;
}

void Spaceship::checkBonusCollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(LifeBonus)){
            qgraphicsitem_cast<LifeBonus *>(colliding_items[i])->operator+(this);
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}


