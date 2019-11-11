#include "ObstacleItem.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"
#include <QDebug>
#include <windows.h>
#include <QDebug>
#include <string>
#include <QtMath>



extern Game * game; //there

ObstacleItem::ObstacleItem(int size, double angle, double speed, qreal xParentCoordinate, qreal yParentCoordinate,  QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    this->size = size; //catch exception size != 0,1,2

    if(size == 0){ //Create a big obstacle
        int randPixMap = rand()%3;
        QString directory = QString(":/images/Obstacles/Big%1.png").arg(randPixMap); //Choose a random picture in Biggest ones
        setPixmap(QPixmap(directory));

        //Set random starting position
        switch (rand() % 4) {
            case 0: //Start on left side
                spawnX = -150;
                spawnY = rand() %(int(game->scene->height())-pixmap().height()-0+1)+0;
                break;
            case 1: //Start on right side
                spawnX = game->scene->width()+150;
                spawnY = rand() %(int(game->scene->height())-pixmap().height()-0+1)+0;
                break;
            case 2: //Start on top side
                spawnY = -150;
                spawnX = rand() %(int(game->scene->width())-pixmap().width()-0+1)+0;
                break;
            case 3: //Start on bottom side
                spawnY = game->scene->height()+150;
                spawnX = rand() %(int(game->scene->width())-pixmap().width()-0+1)+0;
                break;
        }
        setPos(spawnX, spawnY);

        //Make the item move
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(10);

    } else if(size == 1) { //Create a intermediate obstacle
        this->speed = speed;
        this->angle = angle;
        int randPixMap = rand()%3;
        QString directory = QString(":/images/Obstacles/Int%1.png").arg(randPixMap);
        setPixmap(QPixmap(directory));
        setPos(xParentCoordinate, yParentCoordinate);

        //Make the item move
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(constraintMove()));
        timer->start(10);


    } else if (size == 2) { //Create a small obstacle
        this->speed = speed;
        this->angle = angle;
        int randPixMap = rand()%3;
        QString directory = QString(":/images/Obstacles/Small%1.png").arg(randPixMap);
        setPixmap(QPixmap(directory));
        setPos(xParentCoordinate, yParentCoordinate);

        //Make the item move
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(constraintMove()));
        timer->start(10);
    }



}

ObstacleItem::~ObstacleItem(){
    delete timer;
}

void ObstacleItem::move(){

    //Make the item move
    if(int(spawnX) == -150){
        setPos(x()+1, y()+int(rand()%2)-1);
    } else if(int(spawnX) == int(game->scene->width()+150)){
        setPos(x()-1, y()+int(rand()%2)-1);
    } else if(int(spawnY) == -150){
        setPos(x()+int(rand()%2)-1, y()+1);
    } else if (int(spawnY) == int(game->scene->height()+150)){
        setPos(x()+int(rand()%2)-1, y()-1);
    }

    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(rotation()-1);

    //Check collisions
    checkWallCollision();
    checkSpaceshipCollision();

}

void ObstacleItem::constraintMove(){

    //Make the item move
    double dy = speed * qSin(qDegreesToRadians(angle));
    double dx = speed * qCos(qDegreesToRadians(angle));
    setPos(x()+dx,y()+dy);
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(rotation()-1);

    //Check collisions
    checkWallCollision();
    checkSpaceshipCollision();

}

int ObstacleItem::obstacleSize(){
    return this->size;
}

void ObstacleItem::checkWallCollision(){
    //Check if the item is out of the playground and destroy it
    if(pos().y() < -150 || pos().y() > (scene()->height())+150 || pos().x() < -150 || pos().x() > (scene()->width())+150){
        scene()->removeItem(this);
        delete this;
    }
}

void ObstacleItem::checkSpaceshipCollision(){
    //Checking collision between ObstacleItem and the Spaceship
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Spaceship)){
            if(this->size == 0){
                game->ship->decreaseLife(100);//decrease health
            } else if(this->size == 1){
                game->ship->decreaseLife(50);//decrease health
            } else {
                game->ship->decreaseLife(25);//decrease health
            }

            if(game->health->getHealth()<=0){



                //Add loosing screen here




                scene()->removeItem(this);
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i]; //Delete the spaceship  End game ERROR HERE
                delete this; //Delete the obstacle
                return;
            } else {
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
