#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>

/*!
 * \brief The Spawner class represent the object managing the spawn of every not playable items
 */
class Spawner : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief Spawner Constructor of the class
     */
    Spawner();

    /*!
     * \brief spawnIntermediateObstacle Make medium asteroids spawn on big asteroids explosion
     * \param xParentCoordinate X position of where you want to spawn the asteroid
     * \param yParentCoordinate Y position of where you want to spawn the asteroid
     */
    void spawnIntermediateObstacle(qreal xParentCoordinate, qreal yParentCoordinate);

    /*!
     * \brief spawnSmallObstacle Make small asteroids spawn on medium asteroids explosion
     * \param xParentCoordinate X position of where you want to spawn the asteroid
     * \param yParentCoordinate Y position of where you want to spawn the asteroid
     */
    void spawnSmallObstacle(qreal xParentCoordinate, qreal yParentCoordinate);

    /*!
     * \brief spawnLifeBonus Make bonus spawn randomly on big asteroids explosion
     * \param lchange The LP to change on grab
     * \param xParentCoordinate X position of where you want to spawn the bonus
     * \param yParentCoordinate Y position of where you want to spawn the bonus
     */
    void spawnLifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate);

    /*!
     * \brief showExplosion Display explosion on asteroid destruction
     * \param xParentCoordinate X position of where you want to display the explosion
     * \param yParentCoordinate Y position of where you want to display the explosion
     */
    void showExplosion(qreal xParentCoordinate, qreal yParentCoordinate);

public slots:
    /*!
     * \brief spawnBigObstacle Make big obstacles spawn periodicaly
     */
    void spawnBigObstacle();

};

#endif // SPAWNER_H
