#include <SoundBox.h>
#include <QMediaPlayer>


SoundBox::SoundBox(){
    shotPlayer = new QMediaPlayer;
    shotPlayer->setMedia(QUrl("qrc:/sounds/laser.mp3"));

    explosionPlayer = new QMediaPlayer;
    explosionPlayer->setMedia(QUrl("qrc:/sounds/explosion8bits.mp3"));
}


void SoundBox::playExplosion(){
    if(explosionPlayer->state()==QMediaPlayer::PlayingState){
        explosionPlayer->setPosition(0);
    } else {
        explosionPlayer->play();
    }
}

void SoundBox::playShot(){
    if(shotPlayer->state()==QMediaPlayer::PlayingState){
        shotPlayer->setPosition(0);
    } else {
        shotPlayer->play();
    }
}
