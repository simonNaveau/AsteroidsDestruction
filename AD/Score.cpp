#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //init score
    score = 0;

    //draw the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Planet N Compact", 17));
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

void Score::setScorePos(int x, int y) {
    setPos(x,y);
}
