#include <QTimer>
#include "Explosion.h"

Explosion::Explosion(qreal xParentCoordinate, qreal yParentCoordinate, QGraphicsItem *parent) : QGraphicsPixmapItem(
        parent) {
    currentImage = 1;
    setPixmap(QPixmap(":/images/Explosions/expl1.png"));
    setPos(xParentCoordinate, yParentCoordinate);

    //this->show();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(nextImage()));
    timer->start(50);
}

Explosion::~Explosion() {
    delete timer;
}

void Explosion::nextImage() {
    if (currentImage > 6) {
        delete this;
        return;
    } else {
        QString directory = QString(":/images/Explosions/expl%1.png").arg(
                currentImage); //Choose a random picture in Biggest ones
        setPixmap(QPixmap(directory));
        currentImage = currentImage + 1;
        timer->stop();
        timer->start(50);
    }
}
