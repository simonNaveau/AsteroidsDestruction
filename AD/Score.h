#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {

public:
    Score(QGraphicsItem *parent = nullptr);

    void increase();

    int getScore();

    void decrease();

    void setScore(int newScore);

    void setScorePos(int x, int y);

private:
    int score;
};

#endif // SCORE_H
