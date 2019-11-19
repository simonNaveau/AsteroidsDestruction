#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //init score
    score = 0;

    //draw the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Planet N Compact", 16));
}

void Score::increase() {
    score += 10;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore() {
    return score;
}

void Score::decrease() {
    score -= 10;
    setPlainText("Score: " + QString::number(score));
}

void Score::setScore(int newScore) {
    score = newScore;
    setPlainText("Score: " + QString::number(score));
}
