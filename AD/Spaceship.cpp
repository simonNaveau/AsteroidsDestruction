#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtMath>
#include <QTimer>
#include <QGraphicsOpacityEffect>

#include "Spaceship.h"
#include "ObstacleItem.h"
#include "LifeBonus.h"
#include "Shot.h"
#include "Game.h"


extern Game *game; //Main game instance

Spaceship::Spaceship(int startingLifePoints, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    lifePoints = startingLifePoints;
    timer = new QTimer();
    metronome = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveAutoForward()));
    timer->start(5);
}

Spaceship::~Spaceship() {
    timer->stop();
}

/*!
 * @brief Spaceship::keyPressEvent Waiting to do actions on keys pressed
 * @param event
 */
void Spaceship::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left or event->key() == Qt::Key_Q) {
        rotateLeft();

    } else if (event->key() == Qt::Key_Right or event->key() == Qt::Key_D) {
        rotateRight();

    } else if (event->key() == Qt::Key_Space) {

        Shot *shot = new Shot();
        if(rotation()> 150 && rotation() < 210){
            shot->setPos(shipCenterX+(shot->pixmap().height()/2), shipCenterY);
        } else {

            shot->setPos(shipCenterX-(shot->pixmap().height()/2), shipCenterY);
        }
        shot->setZValue(-10);
        scene()->addItem(shot);
        game->getSoundBox()->playShot();

    } else if (event->key() == Qt::Key_Up or event->key() == Qt::Key_Z) {
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
void Spaceship::rotateRight() {
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    setRotation(rotation() + 10);
}

void Spaceship::rotateLeft() {
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    setRotation(rotation() - 10);
}

void Spaceship::moveAutoForward() {
    double angle = rotation() - 90;
    double dy = speed * qSin(qDegreesToRadians(angle));
    double dx = speed * qCos(qDegreesToRadians(angle));
    if (x() + dx + pixmap().width() <= scene()->width() && x() + dx >= 0 &&
        y() + dy + pixmap().height() <= scene()->height() && y() + dy >= 0) {
        setPos(x() + dx, y() + dy);
        shipCenterX = shipCenterX + dx;
        shipCenterY = shipCenterY + dy;
    }
    checkBonusCollision();
    if(!(metronome->isActive()) && opacity() != 1.0) setOpacity(1);
}

void Spaceship::resetSpeed() {
    speed = 1;
    delete timer;
}

void Spaceship::animate(){
    qreal startingOpa = opacity();
    if(animationState == 4 || animationState == 2){
        if(startingOpa > 0.1){
          setOpacity(startingOpa-0.1);
        } else {
            animationState--;
        }
    } else if(animationState == 3 || animationState == 1){
        if(startingOpa < 0.95){
          setOpacity(startingOpa+0.1);
        } else {
            animationState--;
        }
    } else if(animationState == 0){
        setOpacity(1);
        animationState = 4;
        metronome->stop();
    }
}

void Spaceship::reset() {
    speed = 0;
    setRotation(0);
}

void Spaceship::launchAnimation(){
    if(metronome != nullptr){
        metronome->stop();
        setOpacity(1);
    } else {
        metronome = new QTimer();
    }
    animationState = 4;
    connect(metronome, SIGNAL(timeout()), this, SLOT(animate()));
    metronome->start(40);
}

int Spaceship::operator+(LifeChanger *changer) {
    return this->getLife() + changer->lifeChange;
}

/**
  Life changing methods
   -> increase life
   -> decrease life
   -> get life
 */
void Spaceship::decreaseLife(int change) {
    lifePoints -= change;
    game->getHealth()->setHealth(lifePoints);
}

void Spaceship::increaseLife(int change) {
    lifePoints += change;
    game->getHealth()->setHealth(lifePoints);
}

int Spaceship::getLife() {
    return lifePoints;
}

void Spaceship::setLife(int newLifePoints) {
    lifePoints = newLifePoints;
}

void Spaceship::checkBonusCollision() {
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(LifeBonus)) {
            this->setLife(*this + qgraphicsitem_cast<LifeBonus *>(colliding_items[i]));
            game->getHealth()->setHealth(this->getLife());
            game->getSoundBox()->playPickup();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}
