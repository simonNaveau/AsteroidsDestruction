#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{

public:
    Health(QGraphicsItem * parent=0);
    void setHealth(int newHealth);
    int getHealth();

public:
    int health;
};

#endif // HEALTH_H
