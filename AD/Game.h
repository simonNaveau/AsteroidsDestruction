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

    // methods
    void displayMenu();
    void stopSpawner();

    public slots:
        void start();
};


#endif // GAME_H
