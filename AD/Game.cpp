#include <QGraphicsScene>
#include "Spaceship.h"
#include <QGraphicsView>
#include <QTimer>
#include "Game.h"
#include <QMediaPlayer>
#include <QImage>
#include "Button.h"
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QDebug>

Game::Game(QWidget *parent){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280, 720); //Size of the mainWindow
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    setScene(scene);
}

void Game::start() {
    qDebug() << "ok";
    // clear the screen
    scene->clear();

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
    ship = new Spaceship(100);
    health->setHealth(ship->getLife());
    ship->setPixmap(QPixmap(":/images/ship.png"));
    ship->setFlag(QGraphicsItem::ItemIsFocusable);  //make focusable
    ship->setFocus();
    scene->addItem(ship);   //add the ship to the scene
    ship->setPos((this->width()/2)-ship->pixmap().width()/2, (this->height()/2)-ship->pixmap().height()/2); //Set spaceship position for start

    /**
      Create object spawner
        -> init ObstacleObject spawner
     **/
    //spawn enemies
    spawner = new Spawner();
    spawnTimer = new QTimer();
    QObject::connect(spawnTimer, SIGNAL(timeout()),spawner,SLOT(spawnBigObstacle()));
    spawnTimer->start(2000);
}

void Game::displayMenu() {
    // game title text
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Asteroid Destruction"));
    title->setDefaultTextColor(QColor(255,255,255,255));
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/fonts/planetncompact.ttf");
    QFont font("Planet N Compact",50);
    title->setFont(font);
    int txPos = this->width()/2 - title->boundingRect().width()/2;
    int tyPos = 100;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    // play button
    Button* playButton = new Button(QString("Play"));
    int pxPos = 50;
    int pyPos = 370;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // exit button
    Button* exitButton = new Button(QString("Exit"));
    int exPos = 50;
    int eyPos = 450;
    exitButton->setPos(exPos,eyPos);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exitButton);
}

void Game::stopSpawner(){
    spawnTimer->stop();
}
