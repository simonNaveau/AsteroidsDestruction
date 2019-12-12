#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include <QPropertyAnimation>

#include "LifeChanger.h"

/*!
 * \brief The Spaceship class is the playable object class. The player control it during the game
 */
class Spaceship : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /*!
     * \brief lifePoints The spaceship current life points
     */
    int lifePoints;

    /*!
     * \brief Spaceship Constructor of the class
     * \param startingLifePoints Life points at the creation of the instance
     * \param parent Container of the item
     */
    Spaceship(int startingLifePoints, QGraphicsItem *parent = nullptr);

    /*!
     * Destuctor of the class
     */
    ~ Spaceship();

    /*!
     * \brief keyPressEvent Method used to detect event to use the spaceship
     * \param event The event detected
     */
    void keyPressEvent(QKeyEvent *event);

    /*!
     * \brief rotateRight Method to rotate the ship to the right on himself
     */
    void rotateRight();

    /*!
     * \brief rotateLeft Method to rotate the ship to the left on himself
     */
    void rotateLeft();

    /*!
     * \brief decreaseLife Remove some ship LP
     * \param change LP to remove
     */
    void decreaseLife(int change);

    /*!
     * \brief increaseLife Add some ship LP
     * \param change LP to remove
     */
    void increaseLife(int change);

    /*!
     * \brief getLife Get the ship LP
     * \return the current life points of the ship as int
     */
    int getLife();

    /*!
     * \brief checkBonusCollision Check if the spaceship get a bonus and if yes add some life points to the him
     */
    void checkBonusCollision();

    /*!
     * \brief setLife Set the spaceship LP to a value
     * \param newLifePoints the new spaceship LP value
     */
    void setLife(int newLifePoints);

    /*!
     * \brief reset Set spaceship rotation and speed to 0
     */
    void reset();

    /*!
     * \brief launchAnimation Start a blink animation on the spaceship asset
     */
    void launchAnimation();

    /*!
     * \brief operator + Override of the plus operator, add the LifeChanger value to the actual spaceship's LP
     * \param changer The item containing the value to add
     * \return The new spaceship LP value
     */
    int operator+(LifeChanger *changer);

    /*!
     * \brief shipCenterX Position X of the current spaceship asset center
     */
    qreal shipCenterX;

    /*!
     * \brief shipCenterY Position Y of the current spaceship asset center
     */
    qreal shipCenterY;

public slots:
    /*!
     * \brief moveAutoForward Make the spaceship move in front of himself whatever the rotation
     */
    void moveAutoForward();

    /*!
     * \brief resetSpeed Set the spaceship speed to 0
     */
    void resetSpeed();

    /*!
     * @brief animate Change the opacity of the pixmapItem to make it blink
     */
    void animate();

private:
    /*!
     * \brief speed The speed of the spaceship
     */
    int speed;

    /*!
     * \brief animationState Internal state of the blinking animation
     */
    int animationState;

    /*!
     * \brief timer QTimer to make the spaceship move
     */
    QTimer *timer;

    /*!
     * \brief metronome QTimer for the blinking animation
     */
    QTimer *metronome;
};

#endif // SPACESHIP_H
