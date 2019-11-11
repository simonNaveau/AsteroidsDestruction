#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //init score
    health = 100;

    //draw the text
    setPlainText("Health: "+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(x(), 25);
}

void Health::setHealth(int newHealth){
    health = newHealth;
    setPlainText("Health: "+QString::number(health));
}

int Health::getHealth(){
    return health;
}
