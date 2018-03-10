#include "joystickcontrols.h"
#include <SDL2/SDL.h>
#include <QDebug>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>


#define MAX_CONTROLLERS 4
SDL_GameController *Joystick[MAX_CONTROLLERS];

JoystickControls::JoystickControls(QObject *parent)
    : QThread(parent)
{

}

void JoystickControls::run()
{
    int controllerIndex = detectActiveJoystick();
    qDebug()<<controllerIndex;

    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            detectJoystickEvent(controllerIndex);
            if(Up)
                emit joystickButtonClicked(UP);
            if(Down)
                emit joystickButtonClicked(DOWN);
            if(Left)
                emit joystickButtonClicked(LEFT);
            if(Right)
                emit joystickButtonClicked(RIGHT);
        }

    }
}


void JoystickControls::detectJoystickEvent(int controllerIndex){

    Up = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_UP);
    Down = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
    Left = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
    Right = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
}

int JoystickControls::detectActiveJoystick(){
    int MaxJoysticks = SDL_NumJoysticks();
    int controllerIndex = 0;
    for(int JoystickIndex=0; JoystickIndex < MaxJoysticks; ++JoystickIndex)
    {
        if (!SDL_IsGameController(JoystickIndex))
        {
            continue;
        }
        if (controllerIndex >= MAX_CONTROLLERS)
        {
            break;
        }
        controllerIndex++;
        Joystick[controllerIndex] = SDL_GameControllerOpen(JoystickIndex);
    }
    return controllerIndex;
}
