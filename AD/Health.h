#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem {

public:
    Health(QGraphicsItem *parent = nullptr);

    void setHealth(int newHealth);

    int getHealth();

    void setHealthPos(int x, int y);

public:
    int health;
};

#endif // HEALTH_H
