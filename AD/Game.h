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
    void setLevelText(QString newLevelText);

    void setTimeLeftText(QString newTimeLeftText);

    void setLoadingText(QString newLoadingText, int newSize);

    int getCurrentLevel();

    void setCurrentLevel(int newCurrentLevel);

    void setTitle(QString newTitle);

    void setFinalScore(QString newFinalScore);

    void setPlayButton(QString newPlayButtonText);

    void setExitButton(QString newExitButtonText);

    void setNextButton(QString newNextButtonText);

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

public slots:
    void start();

    void displayLevelSucess();

private slots :
    void reinit();

    void refresh();

    void refreshLoading();

    void displayVictory();

private:
    // attributes
    int currentLevel;

    int fontSize1;
    int fontSize2;
    int fontSize3;

    int tmp;

    QGraphicsTextItem *levelText;
    QGraphicsTextItem *title;
    QGraphicsTextItem *finalScore;
    QGraphicsTextItem *timeLeftText;
    QGraphicsTextItem *loadingText;

    Button *playButton;
    Button *exitButton;
    Button *nextButton;
    Button *retryButton;

    QTimer *spawnTimer;
    QTimer *levelTimer;
    QTimer *refreshTimer;
    QTimer *loadingTimer;

    Spaceship *ship;

    QGraphicsScene *scene;
    Spawner *spawner;
    SoundBox *soundBox;

    Score *score;

    Health *health;

    std::deque < Level * > levels;

    // methods
    void clearDisplay();

    void init();
};


#endif // GAME_H
