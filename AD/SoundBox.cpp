#include <SoundBox.h>
#include <QMediaPlayer>


SoundBox::SoundBox() {
    shotPlayer = new QMediaPlayer;
    shotPlayer->setMedia(QUrl("qrc:/sounds/laser.mp3"));

    explosionPlayer = new QMediaPlayer;
    explosionPlayer->setMedia(QUrl("qrc:/sounds/explo.mp3"));

    hitPlayer = new QMediaPlayer;
    hitPlayer->setMedia(QUrl("qrc:/sounds/hit.mp3"));

    clickPlayer = new QMediaPlayer;
    clickPlayer->setMedia(QUrl("qrc:/sounds/click.mp3"));

    pickupPlayer = new QMediaPlayer;
    pickupPlayer->setMedia(QUrl("qrc:/sounds/pickup.mp3"));

    menuTheme = new QMediaPlayer;
    menuTheme->setMedia(QUrl("qrc:/sounds/menuTheme.mp3"));
    menuTheme->setVolume(80);

    levelTheme = new QMediaPlayer;
    levelTheme->setMedia(QUrl("qrc:/sounds/levelTheme.mp3"));
    levelTheme->setVolume(80);
}


void SoundBox::playExplosion() {
    if (explosionPlayer->state() == QMediaPlayer::PlayingState) {
        explosionPlayer->setPosition(0);
    } else {
        explosionPlayer->play();
    }
}

void SoundBox::playShot() {
    if (shotPlayer->state() == QMediaPlayer::PlayingState) {
        shotPlayer->setPosition(0);
    } else {
        shotPlayer->play();
    }
}

void SoundBox::playHit(){
    if (hitPlayer->state() == QMediaPlayer::PlayingState) {
        hitPlayer->setPosition(0);
    } else {
        hitPlayer->play();
    }
}

void SoundBox::playClick(){
    if (clickPlayer->state() == QMediaPlayer::PlayingState) {
        clickPlayer->setPosition(0);
    } else {
        clickPlayer->play();
    }
}

void SoundBox::playPickup(){
    if (pickupPlayer->state() == QMediaPlayer::PlayingState) {
        pickupPlayer->setPosition(0);
    } else {
        pickupPlayer->play();
    }
}

void SoundBox::playMenuTheme(){
    if (!(menuTheme->state() == QMediaPlayer::PlayingState)) {
        menuTheme->play();
    }
}

void SoundBox::stopMenuTheme(){
    if (menuTheme->state() == QMediaPlayer::PlayingState) {
        menuTheme->stop();
    }
}

void SoundBox::startLevelTheme(){
    if (!(levelTheme->state() == QMediaPlayer::PlayingState)) {
        levelTheme->play();
    }
}

void SoundBox::stopLevelTheme(){
    if (levelTheme->state() == QMediaPlayer::PlayingState) {
        levelTheme->stop();
    }
}
