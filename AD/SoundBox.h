#ifndef SOUNDBOX_H
#define SOUNDBOX_H

#include <QMediaPlayer>

/*!
 * \brief The SoundBox class used to run sounds
 */
class SoundBox {

public:
    /*!
     * \brief Constructor
     */
    SoundBox();

    /*!
     * \brief playExplosion Method called when an explosion occures
     */
    void playExplosion();

    /*!
     * \brief playShot Method called when the player shoots
     */
    void playShot();

    /*!
     * \brief playHit Method called when the player takes some damage
     */
    void playHit();

    /*!
     * \brief playClick Method called when the player clicks on a button
     */
    void playClick();

    /*!
     * \brief playPickup Method called when the player chooses is ship
     */
    void playPickup();

    /*!
     * \brief playMenuTheme Method called when the main menu is displayed
     */
    void playMenuTheme();

    /*!
     * \brief stopMenuTheme Method called when the player starts playing
     */
    void stopMenuTheme();

    /*!
     * \brief startLevelTheme Method called when the player is playing
     */
    void startLevelTheme();

    /*!
     * \brief startLevelTheme Method called when the player is back to the main menu
     */
    void stopLevelTheme();

private :
    /*!
     * \brief shotPlayer The sound played when the player shoots
     */
    QMediaPlayer *shotPlayer;

    /*!
     * \brief explosionPlayer The sound played when an explosion occures
     */
    QMediaPlayer *explosionPlayer;

    /*!
     * \brief hitPlayer The sound played when the player takes some damage
     */
    QMediaPlayer *hitPlayer;

    /*!
     * \brief menuTheme The sound played when the main menu is displayed
     */
    QMediaPlayer *menuTheme;

    /*!
     * \brief levelTheme The sound played when the player is playing
     */
    QMediaPlayer *levelTheme;

    /*!
     * \brief clickPlayer The sound played when the player clicks on a button
     */
    QMediaPlayer *clickPlayer;

    /*!
     * \brief pickupPlayer The sound played when the player chooses is ship
     */
    QMediaPlayer *pickupPlayer;

};

#endif // SOUNDBOX_H
