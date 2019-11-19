#include <QApplication>
#include "Game.h"

//Global to add access from other class
Game *game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMenu();
    return a.exec();
}
