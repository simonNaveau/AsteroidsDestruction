#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

/*!
 * \brief The Explosion class manage the explosion animation on obstacles destruction by shots
 */
class Explosion : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /*!
     * \brief Explosion Constructor of the class
     * \param xParentCoordinate X position of where you want to display the explosion
     * \param yParentCoordinate Y position of where you want to display the explosion
     * \param parent Container of the item
     */
    Explosion(qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent = nullptr);

    /*!
     * Destructor of the class
     */
    ~ Explosion();

private:
    /*!
     * \brief timer QTimer to manage assets changes
     */
    QTimer *timer;

    /*!
     * \brief currentImage Id of the current assets in the explosion animation
     */
    int currentImage;

public slots:
    /*!
     * \brief nextImage Change the current assets to the next in the animation and display it.
     */
    void nextImage();
};

#endif // EXPLOSION_H
