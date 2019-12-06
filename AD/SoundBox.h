#ifndef SOUNDBOX_H
#define SOUNDBOX_H

#include <QMediaPlayer>

class SoundBox {

public:
    QMediaPlayer *shotPlayer;
    QMediaPlayer *explosionPlayer;
    QMediaPlayer *hitPlayer;
    QMediaPlayer *menuTheme;
    QMediaPlayer *levelTheme;
    QMediaPlayer *clickPlayer;
    QMediaPlayer *pickupPlayer;

    SoundBox();

    void playExplosion();

    void playShot();

    void playHit();

    void playClick();

    void playPickup();

    void playMenuTheme();

    void stopMenuTheme();

    void startLevelTheme();

    void stopLevelTheme();

};

#endif // SOUNDBOX_H
