#include "Level.h"

Level::Level() {
    successTime = 0;
    asteroDmg = 0;
    asteroSpeed = 0;
    asteroSpawnFreq = 0;
}

void Level::setSucessTime(int time) {
    successTime = time;
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

int Level::getSucessTime() {
    return successTime;
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
