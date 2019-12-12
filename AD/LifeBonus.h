#ifndef LIFEBONUS_H
#define LIFEBONUS_H

#include "ObstacleItem.h"
#include "LifeChanger.h"

/*!
 * \brief The LifeBonus class represent the bonus drop by big obstacle on destruction who can be rammed by the player. It's an ObstacleItem and a LifeChanger.
 */
class LifeBonus : public ObstacleItem, public LifeChanger {
    Q_OBJECT
public:
    /*!
     * \brief LifeBonus Constructor of the class
     * \param lchange The value to add or remove and grab by the player
     * \param xParentCoordinate X position of where you want to display the bonus
     * \param yParentCoordinate Y position of where you want to display the bonus
     * \param parent Container of the item
     */
    LifeBonus(int lchange, qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent = nullptr);

    /*!
     * Destructor of the class
     */
    ~ LifeBonus();

private:
    /*!
     * \brief animationCount The id of the current assets in the animation
     */
    int animationCount;

    /*!
     * \brief animationTimer QTimer to manage the animation progress
     */
    QTimer *animationTimer;

public slots:
    /*!
     * \brief animation Change assets to the next in the animation
     */
    void animation();
};

#endif // LIFEBONUS_H
