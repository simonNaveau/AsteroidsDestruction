#ifndef SOUNDBOX_H
#define SOUNDBOX_H
#include <QMediaPlayer>

class SoundBox{

public:
    QMediaPlayer * shotPlayer;
    QMediaPlayer * explosionPlayer;

    SoundBox();
    void playExplosion();
    void playShot();

};

#endif // SOUNDBOX_H
