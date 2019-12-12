#ifndef OBSTACLEITEM_H
#define OBSTACLEITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

/*!
 * \brief The ObstacleItem class represent all the object who can collide with the spaceship and have effect on it
 */
class ObstacleItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    /*!
     * \brief ObstacleItem Constructor of the class
     * \param size The size of the Obstacle if it's an Asteroid
     * \param angle The starting rotation angle of the object
     * \param speed The starting speed of the object
     * \param xParentCoordinate X position of where you want to display the object on creation
     * \param yParentCoordinate Y position of where you want to display the object on creation
     * \param parent Container of the item
     */
    ObstacleItem(int size, double angle, double speed, qreal xParentCoordinate, qreal yParentCoordinate,
                 QGraphicsItem *parent = nullptr);

    /*!
     * Destructor of the class
     */
    ~ ObstacleItem();

    /*!
     * \brief getTimer Return the timer managing the object moves
     * \return a QTimer pointer
     */
    QTimer *getTimer();

    /*!
     * \brief setTimer Set the movement timer of the object
     */
    void setTimer(QTimer *);

    /*!
     * \brief spawnX The on spawn X coordinate of the item
     */
    qreal spawnX;

    /*!
     * \brief spawnY The on spawn Y coordinate of the item
     */
    qreal spawnY;

public slots:
    /*!
     * \brief move Make the object move in a "random" direction
     */
    void move();

    /*!
     * \brief constraintMove Make the object move in a direction with no random
     */
    void constraintMove();

    /*!
     * \brief obstacleSize Return the size of the current object
     * \return The size of the object in int
     */
    int obstacleSize();

private:
    /*!
     * \brief timer The QTimer managing the object movements
     */
    QTimer *timer;

    /*!
     * \brief size The size of the object
     */
    int size;

    /*!
     * \brief angle The current trajectory angle
     */
    double angle;

    /*!
     * \brief speed The move speed of the object
     */
    double speed;

    /*!
     * \brief checkWallCollision Check if the object is out of screen and if yes destroy it
     */
    void checkWallCollision();

    /*!
     * \brief checkSpaceshipCollision Check if the object collide with the playable item and if yes descrease his life and launch destruction animation or end the game.
     */
    void checkSpaceshipCollision();
};

#endif // OBSTACLEITEM_H
