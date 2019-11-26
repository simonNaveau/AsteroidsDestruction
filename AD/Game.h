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

    void setNextLevelButton(QString newNextLevelButtonText);

    void setRetryButton(QString newRetryButtonText);

    void setSelectButton(QString newSelectButtonText);

    void setNextButton(QString newNextButtonText);

    void setPrevButton(QString newPrevButtonText);

    void setSelectedShip(QString newSelectShip);

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

private slots :
    void reinit();

    void refresh();

    void refreshLoading();

    void displayVictory();

    void displayLevelSucess();

    void displaySelect();

    void selectNext();

    void selectPrevious();

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
    Button *nextLevelButton;
    Button *retryButton;
    Button *selectButton;
    Button *nextButton;
    Button *prevButton;

    int selectedNumber;

    QGraphicsPixmapItem *selectedShip;
    QString shipPath;

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

    std::deque<Level *> levels;

    // methods
    void clearDisplay();

    void init();
};


#endif // GAME_H
