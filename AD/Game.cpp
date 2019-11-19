#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include "Game.h"

Game::Game() {

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

    clearOverlay();
}

void Game::start() {

    // clear the overlay
    clearOverlay();

    score->setVisible(1);

    health->setHealth(ship->getLife());
    health->setVisible(1);
    ship->setFocus();
    ship->setVisible(1);
    ship->setPos((width() / 2) - ship->pixmap().width() / 2,
                 (height() / 2) - ship->pixmap().height() / 2);

    levelTimer->start(10000);
    if (levelTimer->remainingTime() == 0) {
        displayVictory();
    }

    /**
      Create object spawner
        -> init ObstacleObject spawner
     **/
    //spawn enemies
    spawner = new Spawner();
    spawnTimer = new QTimer();
    connect(spawnTimer, SIGNAL(timeout()), spawner, SLOT(spawnBigObstacle()));
    spawnTimer->start(2000);

    // game title
    setLevelText("Level " + QString::number(getCurrentLevel()));
    levelText->setVisible(1);

    score->setVisible(1);
    health->setVisible(1);
}


void Game::displayMenu() {
    clearOverlay();
    // game title
    setTitle("Asteroid Destruction");
    title->setVisible(1);

    // play button
    setPlayButton("Play");
    playButton->setVisible(1);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));

    // exit button
    setExitButton("Exit");
    exitButton->setVisible(1);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::displayDefeat() {
    clearOverlay();

    // game title
    setTitle("Game Over");
    title->setVisible(1);

    // final score
    setFinalScore("Score : " + QString::number(score->getScore()));
    finalScore->setVisible(1);

    // play button
    setRetryButton("Retry");
    retryButton->setVisible(1);
    connect(retryButton, SIGNAL(clicked()), this, SLOT(reinit()));

    // exit button
    setExitButton("Exit");
    exitButton->setVisible(1);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::displayVictory() {

    stopSpawner();
    stopLevel();
    ship->clearFocus();

    clearOverlay();

    setTitle("Level Complete");
    title->setVisible(1);

    // next button
    setNextButton("Next level");
    nextButton->setVisible(1);
    connect(nextButton, SIGNAL(clicked()), this, SLOT(start()));

    currentLevel += 1;
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
    scene->addItem(levelText);

    title = new QGraphicsTextItem("");
    scene->addItem(title);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    scene->addItem(health);

    playButton = new Button("");
    scene->addItem(playButton);

    exitButton = new Button("");
    scene->addItem(exitButton);

    nextButton = new Button("");
    scene->addItem(nextButton);

    retryButton = new Button("");
    scene->addItem(retryButton);

    ship = new Spaceship(100);
    health->setHealth(ship->getLife());
    ship->setPixmap(QPixmap(":/images/ship.png"));
    ship->setFlag(QGraphicsItem::ItemIsFocusable);  //make focusable
    scene->addItem(ship);

    soundBox = new SoundBox();

    currentLevel = 1;

    levelTimer = new QTimer();
    connect(levelTimer, SIGNAL(timeout()), this, SLOT(displayVictory()));
}

void Game::reinit() {
    ship->setLife(100);
    health->setHealth(ship->getLife());
    score->setScore(0);
    currentLevel = 1;
    start();
}

void Game::clearOverlay() {
    title->setVisible(0);
    levelText->setVisible(0);
    finalScore->setVisible(0);
    playButton->setVisible(0);
    exitButton->setVisible(0);
    nextButton->setVisible(0);
    retryButton->setVisible(0);
    score->setVisible(0);
    health->setVisible(0);
    ship->setVisible(0);
}

//------------------------------------------------------
// GETTERS AND SETTERS
//------------------------------------------------------
QGraphicsTextItem *Game::getLevelText() {
    return levelText;
}

void Game::setLevelText(QString newLevelText) {
    levelText->setPlainText(newLevelText);
    levelText->setDefaultTextColor(QColor(255, 255, 255, 255));
    levelText->setFont(QFont("Planet N Compact", 16));
    int x = 0;
    int y = 50;
    levelText->setPos(x, y);
}

int Game::getCurrentLevel() {
    return currentLevel;
}

void Game::setCurrentLevel(int newCurrentLevel) {
    currentLevel = newCurrentLevel;
}

QGraphicsTextItem *Game::getTitle() {
    return title;
}

void Game::setTitle(QString newTitle) {
    title->setPlainText(newTitle);
    title->setDefaultTextColor(QColor(255, 255, 255, 255));
    title->setFont(QFont("Planet N Compact", 50));
    int x = width() / 2 - title->boundingRect().width() / 2;
    int y = 100;
    title->setPos(x, y);
}

QGraphicsTextItem *Game::getFinalScore() {
    return finalScore;
}

void Game::setFinalScore(QString newFinalScore) {
    finalScore->setPlainText(newFinalScore);
    finalScore->setDefaultTextColor(QColor(255, 255, 255, 255));
    finalScore->setFont(QFont("Planet N Compact", 20));
    int x = width() / 2 - finalScore->boundingRect().width() / 2;
    int y = 200;
    finalScore->setPos(x, y);
}

Button *Game::getPlayButton() {
    return playButton;
}

void Game::setPlayButton(QString newPlayButtontext) {
    playButton->setText(newPlayButtontext);
    playButton->setPos(50, 370);
}

Button *Game::getExitButton() {
    return exitButton;
}

void Game::setExitButton(QString newExitButtontext) {
    exitButton->setText(newExitButtontext);
    exitButton->setPos(50, 450);
}

Button *Game::getNextButton() {
    return nextButton;
}

void Game::setNextButton(QString newNextButtonText) {
    nextButton->setText(newNextButtonText);
    int x = width() / 2 - nextButton->boundingRect().width() / 2;
    int y = 400;
    nextButton->setPos(x, y);
}

Button *Game::getRetryButton()
{
    return retryButton;
}

void Game::setRetryButton(QString newRetryButtonText)
{
    retryButton->setText(newRetryButtonText);
    retryButton->setPos(50, 370);
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

