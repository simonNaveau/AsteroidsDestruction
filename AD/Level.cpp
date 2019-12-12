#include "Level.h"

Level::Level() {
    levelTime = 0;
    asteroSpawnFreq = 0;
}

void Level::setLevelTime(int time) {
    levelTime = time;
}

void Level::setAsteroSpawnFreq(int freq) {
    asteroSpawnFreq = freq;
}

int Level::getLevelTime() {
    return levelTime;
}

int Level::getAsteroSpawnFreq() {
    return asteroSpawnFreq;
}
