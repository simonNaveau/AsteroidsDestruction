#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/*!
 * \brief The Score class display on the screen the player score
 */
class Score : public QGraphicsTextItem {

public:
    /*!
     * \brief  Constructor of the class
     * \param parent Container of the item
     */
    Score(QGraphicsItem *parent = nullptr);

    /*!
     * \brief increase Increase the current score of 10 and refresh on screen
     */
    void increase();

    /*!
     * \brief getScore Return the actual score of the player
     * \return the actual score of the player
     */
    int getScore();

    /*!
     * \brief decrease Decrease the current score of 10 and refresh on screen
     */
    void decrease();

    /*!
     * \brief setScore Set the player score to a value
     * \param newScore The new score to display
     */
    void setScore(int newScore);

    /*!
     * \brief setScorePos Set the position on the screen of the graphicItem
     * \param x X position on the screen
     * \param y Y position on the screen
     */
    void setScorePos(int x, int y);

private:
    /*!
     * \brief score The current player game score
     */
    int score;
};

#endif // SCORE_H
