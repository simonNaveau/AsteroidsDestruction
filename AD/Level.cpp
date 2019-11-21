#include "Level.h"

Level::Level() {
    levelTime = 0;
    asteroDmg = 0;
    asteroSpeed = 0;
    asteroSpawnFreq = 0;
}

void Level::setLevelTime(int time) {
    levelTime = time;
}

void Level::setAsteroDmg(int dmg) {
    asteroDmg = dmg;
}

void Level::setAsteroSpeed(int speed) {
    asteroSpeed = speed;
}

void Level::setAsteroSpawnFreq(int freq) {
    asteroSpawnFreq = freq;
}

int Level::getLevelTime() {
    return levelTime;
}

int Level::getAsteroDmg() {
    return asteroDmg;
}

int Level::getAsteroSpeed() {
    return asteroSpeed;
}

int Level::getAsteroSpawnFreq() {
    return asteroSpawnFreq;
}
