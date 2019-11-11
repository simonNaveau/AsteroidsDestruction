#include <QGraphicsScene>
#include "Spaceship.h"
#include <QGraphicsView>
#include <QTimer>
#include "Game.h"
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget *parent){

    // create a scene
    scene = new QGraphicsScene();

    /**
      Create different text informations displayed on screen and managing the sound
        -> Health
        -> Score
        -> SoundBox
     **/
    health = new Health();  //create the health text
    scene->addItem(health);

    score = new Score();    //create the score
    scene->addItem(score);

    soundBox = new SoundBox();    //item managing the sound effects

    /**
      Create the playable ship
        -> Set life points
        -> Set picture
        -> Set focusable
     **/
    ship = new Spaceship(1000);
    health->setHealth(ship->getLife());
    ship->setPixmap(QPixmap(":/images/ship.png"));
    scene->addItem(ship);   //add the ship to the scene

    ship->setFlag(QGraphicsItem::ItemIsFocusable);  //make focusable
    ship->setFocus();

    /**
      Set window properties
        -> Disable Scroll bars
        -> Set background picture from resources
        -> Show and set view
        -> Set playable ship starting position
     */
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    view->show();   //show view
    view->setFixedSize(1280, 720); //Size of the mainWindow
    scene->setSceneRect(0,0,1280,720);
    ship->setPos((view->width()/2)-ship->pixmap().width()/2, (view->height()/2)-ship->pixmap().height()/2); //Set spaceship position for start

    /**
      Create object spawner
        -> init ObstacleObject spawner
     **/
    //spawn enemies
    spawner = new Spawner();
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),spawner,SLOT(spawnBigObstacle()));
    timer->start(2000);
}
