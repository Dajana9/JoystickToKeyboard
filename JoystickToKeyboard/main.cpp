#include "mainwindow.h"
#include <QApplication>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK);
    MainWindow w;
    w.show();

    return a.exec();
}
