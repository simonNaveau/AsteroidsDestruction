#include "Shot.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "ObstacleItem.h"
#include "Game.h"
#include <QtMath>
#include <QDebug>

extern Game * game; //there

Shot::Shot(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //draw the bullet
    shotAngle = game->ship->rotation()-90;
    setPixmap(QPixmap(":/images/Shot.png"));
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(shotAngle);

    //connect
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

Shot::~Shot(){
    delete timer;
}

void Shot::move(){

    double dy = 5 * qSin(qDegreesToRadians(shotAngle));
    double dx = 5 * qCos(qDegreesToRadians(shotAngle));
    /**
      Move the shot if possible or remove it
      **/
    if(x()+dx+pixmap().width() <= scene()->width() && x()+dx >= 0 && y()+dy+pixmap().height() <= scene()->height() && y()+dy >=0 ){
        setPos(x()+dx,y()+dy);
    } else {
        scene()->removeItem(this);
        delete this;
        return;
    }

    checkObstacleCollision();
}

/**
  Check if the shot touch a ObstacleItem and remove it if yes
 */
void Shot::checkObstacleCollision(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(ObstacleItem)){

            game->score->increase(); //increase score
            game->soundBox->playExplosion(); //Play sound

            if(qgraphicsitem_cast<ObstacleItem *>(colliding_items[i])->obstacleSize()==0){
                game->spawner->spawnIntermediateObstacle(colliding_items[i]->x(), colliding_items[i]->y());
                game->spawner->showExplosion(colliding_items[i]->x(), colliding_items[i]->y());
            } else if(qgraphicsitem_cast<ObstacleItem *>(colliding_items[i])->obstacleSize()==1){
                game->spawner->spawnSmallObstacle(colliding_items[i]->x(), colliding_items[i]->y());
                game->spawner->showExplosion(colliding_items[i]->x(), colliding_items[i]->y());
            } else if(qgraphicsitem_cast<ObstacleItem *>(colliding_items[i])->obstacleSize()==2) {
                game->spawner->showExplosion(colliding_items[i]->x(), colliding_items[i]->y());
            }

            scene()->removeItem(colliding_items[i]); //remove from scene
            scene()->removeItem(this);

            delete colliding_items[i]; //delete the object
            delete this;
            return;
        }
    }
}
