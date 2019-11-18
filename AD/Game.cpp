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

    finalScore = new QGraphicsTextItem("");
}

void Game::start() {
    // clear the screen
    title->setVisible(0);
    playButton->setVisible(0);
    exitButton->setVisible(0);
    if(finalScore->isVisible()) {
        finalScore->setVisible(0);
    }

    /**
      Create different text informations displayed on screen and managing the sound
        -> Health
        -> Score
        -> SoundBox
     **/
    health = new Health();  //create the health text
    health->setFont(QFont("Planet N Compact",16));

    score = new Score();    //create the score
    score->setFont(QFont("Planet N Compact",16));
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
    scene->addItem(health);
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

    // game title
    title = new QGraphicsTextItem("Asteroid Destruction");
    title->setDefaultTextColor(QColor(255,255,255,255));
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/fonts/planetncompact.ttf");
    title->setFont(QFont("Planet N Compact",50));
    int x = this->width()/2 - title->boundingRect().width()/2;
    int y = 100;
    title->setPos(x,y);
    scene->addItem(title);

    // play button
    playButton = new Button("Play");
    x = 50;
    y = 370;
    playButton->setPos(x,y);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // exit button
    exitButton = new Button("Exit");
    x = 50;
    y = 450;
    exitButton->setPos(x,y);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exitButton);
}

void Game::displayDefeat() {
    title = new QGraphicsTextItem("Game Over");
    title->setDefaultTextColor(QColor(255,255,255,255));
    title->setFont(QFont("Planet N Compact",50));
    int x = this->width()/2 - title->boundingRect().width()/2;
    int y = 100;
    title->setPos(x,y);
    scene->addItem(title);

    // final score
    finalScore = new QGraphicsTextItem("Score : "+QString::number(score->getScore()));
    finalScore->setDefaultTextColor(QColor(255,255,255,255));
    finalScore->setFont(QFont("Planet N Compact",30));
    x = this->width()/2 - finalScore->boundingRect().width()/2;
    y = 250;
    finalScore->setPos(x,y);
    scene->addItem(finalScore);

    // play button
    playButton = new Button("Retry");
    x = 50;
    y = 370;
    playButton->setPos(x,y);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // exit button
    exitButton = new Button("Exit");
    x = 50;
    y = 450;
    exitButton->setPos(x,y);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exitButton);
}

void Game::stopSpawner(){
    spawnTimer->stop();
}
