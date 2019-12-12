#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

/*!
 * \brief The Health class display on the screen the player remaining LP
 */
class Health : public QGraphicsTextItem {

public:
    /*!
     * \brief Health Constructor of the class
     * \param parent Container of the item
     */
    Health(QGraphicsItem *parent = nullptr);

    /*!
     * \brief setHealth Set the value to display on screen
     * \param newHealth The new value to display
     */
    void setHealth(int newHealth);

    /*!
     * \brief getHealth Get the current value displayed
     * \return The current value displayed on the screen in int
     */
    int getHealth();

    /*!
     * \brief setHealthPos Set the position on the screen of the graphicItem
     * \param x X position on the screen
     * \param y Y position on the screen
     */
    void setHealthPos(int x, int y);

    /*!
     * \brief health The current value displayed on screen
     */
    int health;
};

#endif // HEALTH_H
