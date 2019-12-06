#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <stdlib.h>
#include "Game.h"
#include "ObstacleItem.h"
#include "LifeBonus.h"

Game::Game() {
    setWindowTitle("Asteroid Destruction");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280, 720); //Size of the mainWindow
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/fonts/planetncompact.ttf");

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1280, 720);
    setScene(scene);

    init();

    clearDisplay();
}

void Game::start() {

    // clear the overlay
    clearDisplay();
    this->soundBox->stopMenuTheme();
    this->soundBox->startLevelTheme();
    loadingTimer->start(60);

    if (tmp == 50) {
        loadingTimer->stop();

        loadingText->setVisible(0);

        score->setVisible(1);

        health->setHealth(ship->getLife());
        health->setVisible(1);
        ship->setFocus();
        ship->setVisible(1);
        ship->setPos((width() / 2) - ship->pixmap().width() / 2,
                     (height() / 2) - ship->pixmap().height() / 2);

        levelTimer->start(levels[currentLevel - 1]->getLevelTime());
        refreshTimer->start(10);

        ship->setPixmap(QPixmap(shipPath));

        /**
          Create object spawner
            -> init ObstacleObject spawner
         **/
        //spawn enemies
        spawnTimer->start(levels[currentLevel - 1]->getAsteroSpawnFreq());

        setLevelText("Level " + QString::number(getCurrentLevel()));
        setTimeLeftText(QString::number(levelTimer->interval()));

        levelText->setVisible(1);
        timeLeftText->setVisible(1);
        health->setHealthPos(width() / 4 + 20,0);
        health->setVisible(1);
        score->setScorePos(2 * width() / 4 + 20,0);
        score->setVisible(1);
    }
}


void Game::displayMenu() {
    clearDisplay();
    // game title
    setTitle("Asteroid Destruction");
    title->setVisible(1);
    this->soundBox->stopLevelTheme();
    this->soundBox->playMenuTheme();

    // play button
    playButton->setVisible(1);
    playButton->resetHover();
    connect(playButton, SIGNAL(clicked()), this, SLOT(displaySelect()));

    // controls button
    controlsButton->setVisible(1);
    controlsButton->resetHover();
    connect(controlsButton, SIGNAL(clicked()), this, SLOT(displayControls()));

    // exit button
    exitButton->setVisible(1);
    exitButton->resetHover();
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::displaySelect() {
    clearDisplay();
    // game title
    setTitle("Choose your ship");
    title->setVisible(1);

    // select button
    selectButton->setVisible(1);
    selectButton->resetHover();
    connect(selectButton, SIGNAL(clicked()), this, SLOT(start()));

    // next button
    nextButton->setVisible(1);
    nextButton->resetHover();
    connect(nextButton, SIGNAL(clicked()), this, SLOT(selectNext()));

    // prev button
    prevButton->setVisible(1);
    prevButton->resetHover();
    connect(prevButton, SIGNAL(clicked()), this, SLOT(selectPrevious()));

    selectedShip->setVisible(1);
}

void Game::selectNext() {
    if (selectedNumber < 3) {
        selectedNumber++;
    } else {
        selectedNumber = 0;
    }
    shipPath = QString(":/images/Ships/ship%1.png").arg(selectedNumber);
    setSelectedShip(shipPath);
}

void Game::selectPrevious() {
    if (selectedNumber > 0) {
        selectedNumber--;
    } else {
        selectedNumber = 3;
    }
    shipPath = QString(":/images/Ships/ship%1.png").arg(selectedNumber);
    setSelectedShip(shipPath);
}

void Game::displayControls() {
    clearDisplay();

    // play button
    setSelectButton("Play");
    selectButton->setVisible(1);
    connect(selectButton, SIGNAL(clicked()), this, SLOT(start()));

    controls->setVisible(1);
}

void Game::displayDefeat() {
    stopSpawner();
    stopLevel();
    clearDisplay();

    // game title
    setTitle("Game Over");
    title->setVisible(1);

    // final score
    setFinalScore("Score : " + QString::number(score->getScore()));
    finalScore->setVisible(1);

    // retry button
    retryButton->setVisible(1);
    retryButton->resetHover();
    connect(retryButton, SIGNAL(clicked()), this, SLOT(reinit()));

    // exit button
    exitButton->setVisible(1);
    exitButton->resetHover();
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::displayLevelSucess() {
    if (int(levels.size()) == currentLevel) {
        displayVictory();
    } else {
        stopSpawner();
        stopLevel();
        ship->reset();
        ship->clearFocus();

        QList < QGraphicsItem * > items = scene->items();
        for (int i = 0, n = items.size(); i < n; ++i) {
            if ((typeid(*(items[i])) == typeid(ObstacleItem)) || (typeid(*(items[i])) == typeid(LifeBonus))) {
                scene->removeItem(items[i]);
                delete items[i];
            }
        }

        clearDisplay();

        setTitle("Level Complete");
        title->setVisible(1);

        // next button
        nextLevelButton->setVisible(1);
        connect(nextLevelButton, SIGNAL(clicked()), this, SLOT(start()));

        currentLevel += 1;
    }
}

void Game::displayVictory() {
    stopSpawner();
    stopLevel();
    ship->reset();
    ship->clearFocus();

    QList < QGraphicsItem * > items = scene->items();
    for (int i = 0, n = items.size(); i < n; ++i) {
        if ((typeid(*(items[i])) == typeid(ObstacleItem)) || (typeid(*(items[i])) == typeid(LifeBonus))) {
            scene->removeItem(items[i]);
            delete items[i];
        }
    }

    clearDisplay();

    setTitle("Victory");
    title->setVisible(1);

    // final score
    setFinalScore("Score : " + QString::number(score->getScore()));
    finalScore->setVisible(1);

    // play button
    setPlayButton("Play again");
    playButton->setVisible(1);
    connect(playButton, SIGNAL(clicked()), this, SLOT(reinit()));


    // play button
    exitButton->setVisible(1);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::stopSpawner() {
    spawnTimer->stop();
}

void Game::stopLevel() {
    levelTimer->stop();
}

//------------------------------------------------------
// PRIVATE METHODS
//------------------------------------------------------
void Game::init() {
    currentLevel = 1;

    finalScore = new QGraphicsTextItem("");
    scene->addItem(finalScore);

    levelText = new QGraphicsTextItem("");
    levelText->setZValue(100);
    scene->addItem(levelText);

    title = new QGraphicsTextItem("");
    scene->addItem(title);

    loadingText = new QGraphicsTextItem("");
    scene->addItem(loadingText);

    controls = new QGraphicsPixmapItem();
    controls->setPixmap(QPixmap(":/images/controls.png"));
    scene->addItem(controls);

    timeLeftText = new QGraphicsTextItem("");
    timeLeftText->setZValue(100);
    scene->addItem(timeLeftText);

    score = new Score();
    score->setZValue(100);
    scene->addItem(score);

    health = new Health();
    health->setZValue(100);
    scene->addItem(health);

    playButton = new Button("");
    setPlayButton("Play");
    scene->addItem(playButton);

    controlsButton = new Button("");
    setControlsButton("Controls");
    scene->addItem(controlsButton);

    exitButton = new Button("");
    setExitButton("Exit");
    scene->addItem(exitButton);

    nextLevelButton = new Button("");
    setNextLevelButton("Next level");
    scene->addItem(nextLevelButton);

    retryButton = new Button("");
    setRetryButton("Retry");
    scene->addItem(retryButton);

    selectButton = new Button("");
    setSelectButton("Select");
    scene->addItem(selectButton);

    nextButton = new Button("");
    setNextButton(">");
    scene->addItem(nextButton);

    prevButton = new Button("");
    setPrevButton("<");
    scene->addItem(prevButton);

    selectedNumber = 0;
    shipPath = QString(":/images/Ships/ship%1.png").arg(selectedNumber);

    selectedShip = new QGraphicsPixmapItem();
    setSelectedShip(shipPath);
    scene->addItem(selectedShip);

    ship = new Spaceship(1000);
    health->setHealth(ship->getLife());
    ship->setPixmap(QPixmap(shipPath));
    ship->setFlag(QGraphicsItem::ItemIsFocusable);  //make focusable
    scene->addItem(ship);

    soundBox = new SoundBox();

    spawner = new Spawner();
    spawnTimer = new QTimer();
    connect(spawnTimer, SIGNAL(timeout()), spawner, SLOT(spawnBigObstacle()));

    levelTimer = new QTimer();
    connect(levelTimer, SIGNAL(timeout()), this, SLOT(displayLevelSucess()));

    loadingTimer = new QTimer();
    connect(loadingTimer, SIGNAL(timeout()), this, SLOT(refreshLoading()));

    refreshTimer = new QTimer();
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refresh()));

    currentLevel = 1;

    fontSize1 = 300;
    fontSize2 = 300;
    fontSize3 = 300;

    tmp = 0;

    int freq = 5000;
    int levelTime = 30000;
    for (int i = 0; i < 10; i++) {
        Level *lv = new Level();

        lv->setAsteroSpawnFreq(freq);
        lv->setLevelTime(levelTime);

        levels.push_back(lv);

        freq = lv->getAsteroSpawnFreq() - 200;
        levelTime = lv->getLevelTime() + 10000;
    }
}

void Game::reinit() {
    stopSpawner();
    stopLevel();
    ship->reset();
    ship->setLife(1000);
    health->setHealth(ship->getLife());
    score->setScore(0);
    currentLevel = 1;
    start();
}

void Game::refresh() {
    long milli = levelTimer->remainingTime();
    long min = milli / 60000;
    milli = milli - 60000 * min;
    long sec = milli / 1000;
    milli = milli - 1000 * sec;
    if (sec >= 10) {
        setTimeLeftText(QString::number(min) + ":" + QString::number(sec));
    } else {
        setTimeLeftText(QString::number(min) + ":0" + QString::number(sec));
    }
}

void Game::refreshLoading() {
    tmp = tmp + 1;
    if (tmp <= 16) {
        setLoadingText("3", fontSize1);
        fontSize1 = fontSize1 - 5;
    } else if (tmp <= 33) {
        setLoadingText("2", fontSize2);
        fontSize2 = fontSize2 - 5;
    } else if (tmp <= 50) {
        setLoadingText("1", fontSize3);
        fontSize3 = fontSize3 - 5;
    }
    loadingText->setVisible(1);
    start();
}

void Game::clearDisplay() {
    controlsButton->setVisible(0);
    controls->setVisible(0);
    selectedShip->setVisible(0);
    title->setVisible(0);
    levelText->setVisible(0);
    timeLeftText->setVisible(0);
    finalScore->setVisible(0);
    playButton->setVisible(0);
    exitButton->setVisible(0);
    nextLevelButton->setVisible(0);
    retryButton->setVisible(0);
    selectButton->setVisible(0);
    nextButton->setVisible(0);
    prevButton->setVisible(0);
    score->setVisible(0);
    health->setVisible(0);
    ship->setVisible(0);
}

//------------------------------------------------------
// GETTERS AND SETTERS
//------------------------------------------------------
void Game::setLevelText(QString newLevelText) {
    levelText->setPlainText(newLevelText);
    levelText->setDefaultTextColor(QColor(255, 255, 255, 255));
    levelText->setFont(QFont("Planet N Compact", 17));
    int x = 20;
    int y = 0;
    levelText->setPos(x, y);
}

void Game::setTimeLeftText(QString newTimeLeftText) {
    timeLeftText->setPlainText("Time : " + newTimeLeftText);
    timeLeftText->setDefaultTextColor(QColor(255, 255, 255, 255));
    timeLeftText->setFont(QFont("Planet N Compact", 17));
    int x = 3 * width() / 4 + 20;
    int y = 0;
    timeLeftText->setPos(x, y);
}

void Game::setLoadingText(QString newLoadingText, int newSize) {
    loadingText->setPlainText(newLoadingText);
    loadingText->setDefaultTextColor(QColor(255, 255, 255, 255));
    loadingText->setFont(QFont("Planet N Compact", newSize));
    int x = int(width() / 2 - loadingText->boundingRect().width() / 2);
    int y = int(height() / 2 - loadingText->boundingRect().height() / 2);
    loadingText->setPos(x, y);
}

int Game::getCurrentLevel() {
    return currentLevel;
}

void Game::setCurrentLevel(int newCurrentLevel) {
    currentLevel = newCurrentLevel;
}

void Game::setTitle(QString newTitle) {
    title->setPlainText(newTitle);
    title->setDefaultTextColor(QColor(255, 255, 255, 255));
    title->setFont(QFont("Planet N Compact", 50));
    int x = int(width() / 2 - title->boundingRect().width() / 2);
    int y = 100;
    title->setPos(x, y);
}

void Game::setFinalScore(QString newFinalScore) {
    finalScore->setPlainText(newFinalScore);
    finalScore->setDefaultTextColor(QColor(255, 255, 255, 255));
    finalScore->setFont(QFont("Planet N Compact", 20));
    int x = int(width() / 2 - finalScore->boundingRect().width() / 2);
    int y = 200;
    finalScore->setPos(x, y);
}

void Game::setPlayButton(QString newPlayButtontext) {
    playButton->setText(newPlayButtontext);
    playButton->setPos(50, 370);
    playButton->resetHover();
}

void Game::setControlsButton(QString newControlsButton) {
    controlsButton->setText(newControlsButton);
    controlsButton->setPos(50, 450);
    controlsButton->resetHover();
}

void Game::setExitButton(QString newExitButtontext) {
    exitButton->setText(newExitButtontext);
    exitButton->setPos(50, 530);
    exitButton->resetHover();
}

void Game::setNextLevelButton(QString newNextLevelButtonText) {
    nextLevelButton->setText(newNextLevelButtonText);
    int x = int(width() / 2 - nextLevelButton->boundingRect().width() / 2);
    int y = 400;
    nextLevelButton->setPos(x, y);
    nextLevelButton->resetHover();
}

void Game::setRetryButton(QString newRetryButtonText) {
    retryButton->setText(newRetryButtonText);
    retryButton->setPos(50, 370);
    retryButton->resetHover();
}

void Game::setSelectButton(QString newSelectButtonText) {
    selectButton->setText(newSelectButtonText);
    int x = int(width() / 2 - selectButton->boundingRect().width() / 2);
    int y = 600;
    selectButton->setPos(x, y);
    selectButton->resetHover();
}

void Game::setNextButton(QString newNextButtonText) {
    nextButton->setText(newNextButtonText);
    int x = int(width() - nextButton->boundingRect().width() - 250);
    int y = 300;
    nextButton->setPos(x, y);
    nextButton->resetHover();
}

void Game::setPrevButton(QString newPrevButtonText) {
    prevButton->setText(newPrevButtonText);
    int x = 250;
    int y = 300;
    prevButton->setPos(x, y);
    prevButton->resetHover();
}

void Game::setSelectedShip(QString newSelectShip) {
    selectedShip->setPixmap(QPixmap(newSelectShip));
    int x = int(width() / 2 - selectedShip->boundingRect().width() / 2);
    int y = 300;
    selectedShip->setPos(x, y);
}

Spaceship *Game::getShip() {
    return ship;
}

QGraphicsScene *Game::getScene() {
    return scene;
}

Spawner *Game::getSpawner() {
    return spawner;
}

SoundBox *Game::getSoundBox() {
    return soundBox;
}

Score *Game::getScore() {
    return score;
}

Health *Game::getHealth() {
    return health;
}

