#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Explosion : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Explosion(qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent = nullptr);

    ~ Explosion();

private:
    QTimer *timer;
    int currentImage;

public slots:
    void nextImage();
};

#endif // EXPLOSION_H
