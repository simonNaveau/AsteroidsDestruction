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

/*!
 * \brief The Game class allows to create a new game
 */
class Game : public QGraphicsView {
    Q_OBJECT
public:
    /*!
     * \brief Constructor
     */
    Game();

    /*!
     * \brief displayMenu The method
     */
    void displayMenu();

    /*!
     * \brief displayDefeat Displays the defeat screen
     */
    void displayDefeat();

    /*!
     * \brief getCurrentLevel Gets the number of the current level
     * \return The number of the current level
     */
    int getCurrentLevel();

    /*!
     * \brief stopSpawner Method used to stop the spawn of asteroids
     */
    void stopSpawner();

    /*!
     * \brief stopLevel Method used to stop the level
     */
    void stopLevel();

    /*!
     * \brief getShip Gets the player's ship
     * \return The player's ship
     */
    Spaceship *getShip();

    /*!
     * \brief getScene Gets the scene
     * \return The scene
     */
    QGraphicsScene *getScene();

    /*!
     * \brief getSpawner Gets the spawner
     * \return The spawner
     */
    Spawner *getSpawner();

    /*!
     * \brief getSoundBox Gets the sound box
     * \return The sound box
     */
    SoundBox *getSoundBox();

    /*!
     * \brief getScore Gets the score
     * \return The score
     */
    Score *getScore();

    /*!
     * \brief getHealth Gets the health
     * \return The health
     */
    Health *getHealth();

public slots:
    /*!
     * \brief start Slot used to start a level
     */
    void start();

private slots :
    /*!
     * \brief reinit Slot used to reinitialize everything after a defeat
     */
    void reinit();

    /*!
     * \brief refresh Slot used to refresh the time left
     */
    void refresh();

    /*!
     * \brief refreshLoading Slot used to refresh the loading screen
     */
    void refreshLoading();

    /*!
     * \brief displayControls Slot used to display the screen with controls
     */
    void displayControls();

    /*!
     * \brief displayVictory Slot used to display the screen when you win
     */
    void displayVictory();

    /*!
     * \brief displayLevelSucess Slot used to display the screen when you pass a level
     */
    void displayLevelSucess();

    /*!
     * \brief displaySelect Slot used to display the screen where you choose your ship
     */
    void displaySelect();

    /*!
     * \brief selectNext Slot used to change the selected ship if you click the next button
     */
    void selectNext();

    /*!
     * \brief selectPrevious Slot used to change the selected ship if you click the previous button
     */
    void selectPrevious();

private:

    /*!
     * \brief currentLevel The number of the current level
     */
    int currentLevel;

    /*!
     * \brief fontSize1 The font of the 1 on the loading screen
     */
    int fontSize1;

    /*!
     * \brief fontSize2 The font of the 2 on the loading screen
     */
    int fontSize2;

    /*!
     * \brief fontSize3 The font of the 3 on the loading screen
     */
    int fontSize3;

    /*!
     * \brief loadingTime The loading time used to change between 1 2 and 3
     */
    int loadingTime;

    /*!
     * \brief levelText Pointer on the text showing the current level
     */
    QGraphicsTextItem *levelText;

    /*!
     * \brief title Pointer on the text showing the game title
     */
    QGraphicsTextItem *title;

    /*!
     * \brief finalScore Pointer on the text showing the final score
     */
    QGraphicsTextItem *finalScore;

    /*!
     * \brief timeLeftText Pointer on the text showing the time left on the current level
     */
    QGraphicsTextItem *timeLeftText;

    /*!
     * \brief loadingText Pointer on the text showing loading timer
     */
    QGraphicsTextItem *loadingText;

    /*!
     * \brief controls Pointer on the pixmap showing controls
     */
    QGraphicsPixmapItem *controls;

    /*!
     * \brief playButton Pointer on the play button
     */
    Button *playButton;

    /*!
     * \brief controlsButton Pointer on the controls button
     */
    Button *controlsButton;

    /*!
     * \brief exitButton Pointer on the exit button
     */
    Button *exitButton;

    /*!
     * \brief nextLevelButton Pointer on the next level button
     */
    Button *nextLevelButton;

    /*!
     * \brief retryButton Pointer on the retry button
     */
    Button *retryButton;

    /*!
     * \brief selectButton Pointer on the select button
     */
    Button *selectButton;

    /*!
     * \brief nextButton Pointer on the next button
     */
    Button *nextButton;

    /*!
     * \brief prevButton Pointer on the previous button
     */
    Button *prevButton;

    /*!
     * \brief selectedNumber The number of the selected ship
     */
    int selectedNumber;

    /*!
     * \brief selectedShip Pointer on the pixmap of the selected ship
     */
    QGraphicsPixmapItem *selectedShip;

    /*!
     * \brief shipPath The path of the pixmap of the selected ship
     */
    QString shipPath;

    /*!
     * \brief spawnTimer Pointer on the spawning timer
     */
    QTimer *spawnTimer;

    /*!
     * \brief levelTimer Pointer on the level timer
     */
    QTimer *levelTimer;

    /*!
     * \brief refreshTimer Pointer on the refresh timer
     */
    QTimer *refreshTimer;

    /*!
     * \brief loadingTimer Pointer on the loading timer
     */
    QTimer *loadingTimer;

    /*!
     * \brief ship Pointer on the player's ship
     */
    Spaceship *ship;

    /*!
     * \brief scene Pointer on the scene
     */
    QGraphicsScene *scene;

    /*!
     * \brief spawner Pointer on the spawner
     */
    Spawner *spawner;

    /*!
     * \brief soundBox Pointer on the sound box
     */
    SoundBox *soundBox;

    /*!
     * \brief score Pointer on the score
     */
    Score *score;

    /*!
     * \brief health Pointer on the health
     */
    Health *health;

    /*!
     * \brief levels The list of levels
     */
    std::deque<Level *> levels;

    /*!
     * \brief clearDisplay The method used to clear everything a part from the background
     */
    void clearDisplay();

    /*!
     * \brief init The method used to create buttons, texts and other objects (soundbox, score, health)
     */
    void init();

    /*!
     * \brief setCurrentLevel Method used to set the index of the current level
     * \param newCurrentLevel The new index of the current level
     */
    void setCurrentLevel(int newCurrentLevel);

    /*!
     * \brief setLevelText Method used to set the text of the current level
     * \param newLevelText The new text of the current level
     */
    void setLevelText(QString newLevelText);

    /*!
     * \brief setTimeLeftText Method used to set the text of the time left on the current level
     * \param newTimeLeftText The new text of the time left on the current level
     */
    void setTimeLeftText(QString newTimeLeftText);

    /*!
     * \brief setLoadingText Method used to set the text of the loading screen and put it on the scene
     * \param newLoadingText The new text of the loading screen
     * \param newSize The new size of the text on the loading screen
     */
    void setLoadingText(QString newLoadingText, int newSize);

    /*!
     * \brief setTitle Method used to set the text of the game title
     * \param newTitle The new title of the game
     */
    void setTitle(QString newTitle);

    /*!
     * \brief setFinalScore Method used to set the text of the final score
     * \param newFinalScore The new text of the final score
     */
    void setFinalScore(QString newFinalScore);

    /*!
     * \brief setPlayButton Method used to set the text of the play button and to put it on the scene
     * \param newPlayButtonText The new text of the play button
     */
    void setPlayButton(QString newPlayButtonText);

    /*!
     * \brief setControlsButton Method used to set the text of the controls button and to put it on the scene
     * \param newControlsButton The new text of the controls button
     */
    void setControlsButton(QString newControlsButton);

    /*!
     * \brief setExitButton Method used to set the text of the exit button and to put it on the scene
     * \param newExitButtonText The new text of the exit button
     */
    void setExitButton(QString newExitButtonText);

    /*!
     * \brief setNextLevelButton Method used to set the text of the next level button and to put it on the scene
     * \param newNextLevelButtonText The new text of the next level button
     */
    void setNextLevelButton(QString newNextLevelButtonText);

    /*!
     * \brief setRetryButton Method used to set the text of the retry button and to put it on the scene
     * \param newRetryButtonText The new text of the retry button
     */
    void setRetryButton(QString newRetryButtonText);

    /*!
     * \brief setSelectButton Method used to set the text of the select button and to put it on the scene
     * \param newSelectButtonText The new text of the select button
     */
    void setSelectButton(QString newSelectButtonText);

    /*!
     * \brief setNextButton Method used to set the text of the next ship button and to put it on the scene
     * \param newNextButtonText The new text of the next ship button
     */
    void setNextButton(QString newNextButtonText);

    /*!
     * \brief setPrevButton Method used to set the text of the previous ship button and to put it on the scene
     * \param newPrevButtonText The new text of the previous ship button
     */
    void setPrevButton(QString newPrevButtonText);

    /*!
     * \brief setSelectedShip Method used to set the new path of the selected ship and update it on the scene
     * \param newSelectShip The new path of the selected ship
     */
    void setSelectedShip(QString newSelectShip);
};

#endif // GAME_H
