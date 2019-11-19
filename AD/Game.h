#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <deque>
#include "Spaceship.h"
#include "Score.h"
#include "Health.h"
#include "Spawner.h"
#include "SoundBox.h"
#include "Button.h"
#include "Level.h"

class Game : public QGraphicsView {
    Q_OBJECT
public:
    // constructor
    Game();

    // methods
    void displayMenu();

    void stopSpawner();

    void stopLevel();

    void displayDefeat();

    // getters and setters
    QGraphicsTextItem *getLevelText();

    void setLevelText(QString newLevelText);

    int getCurrentLevel();

    void setCurrentLevel(int newCurrentLevel);

    QGraphicsTextItem *getTitle();

    void setTitle(QString newTitle);

    QGraphicsTextItem *getFinalScore();

    void setFinalScore(QString newFinalScore);

    Button *getPlayButton();

    void setPlayButton(QString newPlayButtonText);

    Button *getExitButton();

    void setExitButton(QString newExitButtonText);

    Button *getNextButton();

    void setNextButton(QString newNextButtonText);

    Button *getRetryButton();

    void setRetryButton(QString newRetryButtonText);

    QTimer *getSpawnTimer();

    void setSpawnTimer(int interval);

    QTimer *getLevelTimer();

    void setLevelTimer(int interval);

    Spaceship *getShip();

    QGraphicsScene *getScene();

    Spawner *getSpawner();

    SoundBox *getSoundBox();

    Score *getScore();

    Health *getHealth();

public
    slots:
            void

    start();

    void displayVictory();

private
    slots :
            void

    reinit();

private:
    // attributes
    int currentLevel;

    QGraphicsTextItem *levelText;
    QGraphicsTextItem *title;
    QGraphicsTextItem *finalScore;

    Button *playButton;
    Button *exitButton;
    Button *nextButton;
    Button *retryButton;

    QTimer *spawnTimer;
    QTimer *levelTimer;

    Spaceship *ship;

    QGraphicsScene *scene;
    Spawner *spawner;
    SoundBox *soundBox;

    Score *score;

    Health *health;

    // methods
    void clearOverlay();

    void init();
};


#endif // GAME_H
