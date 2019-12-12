#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

/*!
 * \brief The Shot class represent a laser launch by the player
 */
class Shot : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /*!
     * \brief Shot Constructor of the class
     * \param parent Container of the item
     */
    Shot(QGraphicsItem *parent = nullptr);

    /*!
     * Destructor of the class
     */
    ~ Shot();

    /*!
     * \brief shotAngle The angle of the shot trajectory
     */
    double shotAngle;

public slots:
    /*!
    * \brief move Move the shot with an angle in a direction
    */
   void move();

private:
   /*!
    * \brief timer QTimer making the shot move
    */
    QTimer *timer;

    /*!
     * \brief checkObstacleCollision Check if the shot collide with an Asteroid and if yes destroy it
     */
    void checkObstacleCollision();

};

#endif // SHOT_H
