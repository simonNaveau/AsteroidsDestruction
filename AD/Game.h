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

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Spaceship * ship;
    Score * score;
    Health * health;
    Spawner * spawner;
    SoundBox * soundBox;
};


#endif // GAME_H
