#include <QFont>
#include "Health.h"

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //init score
    health = 100;

    //draw the text
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Planet N Compact", 17));
}

void Health::setHealth(int newHealth) {
    health = newHealth;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth() {
    return health;
}

void Health::setHealthPos(int x, int y) {
    setPos(x,y);
}
