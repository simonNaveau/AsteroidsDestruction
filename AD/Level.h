#ifndef LEVEL_H
#define LEVEL_H

/*!
 * \brief The Level class used to create levels
 */
class Level {
public:
    /*!
     * \brief Constructor
     */
    Level();

    /*!
     * \brief Sets the time required to finish the level
     */
    void setLevelTime(int newTime);

    /*!
     * \brief Sets the spawning frequency of asteroids
     */
    void setAsteroSpawnFreq(int newAsteroSpawnFreq);
    /*!
     * \brief Gets the time required to finish the level
     * \return The time required to finish the level
     */
    int getLevelTime();

    /*!
     * \brief Gets the spawning frequency of asteroids
     * \return The spawning frequency of asteroids
     */
    int getAsteroSpawnFreq();

private:

    /*!
     * \brief levelTime The time required to finish the level
     */
    int levelTime;

    /*!
     * \brief asteroSpawnFreq The spawning frequency of asteroids
     */
    int asteroSpawnFreq;
};

#endif // LEVEL_H
