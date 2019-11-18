#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Spaceship.h"
#include "Score.h"
#include "Health.h"
#include "Spawner.h"
#include "SoundBox.h"
#include <QTimer>
#include "Button.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructor
    Game(QWidget * parent=0);

    // attributes
    QGraphicsScene * scene;
    Spaceship * ship;
    Score * score;
    Health * health;
    Spawner * spawner;
    SoundBox * soundBox;
    QTimer * spawnTimer;
    QGraphicsTextItem * title;
    QGraphicsTextItem * finalScore;
    Button * playButton;
    Button * exitButton;
    QFont font;

    // methods
    void displayMenu();
    void stopSpawner();
    void displayDefeat();
    void displayVictory();

    public slots:
        void start();
};


#endif // GAME_H
