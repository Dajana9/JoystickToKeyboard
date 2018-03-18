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
            if(m_Up)
                emit joystickButtonClicked(UP);
            if(m_Down)
                emit joystickButtonClicked(DOWN);
            if(m_Left)
                emit joystickButtonClicked(LEFT);
            if(m_Right)
                emit joystickButtonClicked(RIGHT);
            if(m_A)
                emit joystickButtonClicked(A);
            if(m_B)
                emit joystickButtonClicked(B);
            if(m_X)
                emit joystickButtonClicked(X);
            if(m_Y)
                emit joystickButtonClicked(Y);
        }
        if(event.type == SDL_CONTROLLERBUTTONUP){
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_DPAD_UP)
            emit joystickButtonRelease(UP);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_DPAD_DOWN)
            emit joystickButtonRelease(DOWN);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_DPAD_LEFT)
            emit joystickButtonRelease(LEFT);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
            emit joystickButtonRelease(RIGHT);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_A)
            emit joystickButtonRelease(A);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_B)
            emit joystickButtonRelease(B);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_X)
            emit joystickButtonRelease(X);
            if (event.jbutton.button==SDL_CONTROLLER_BUTTON_Y)
            emit joystickButtonRelease(Y);

        }

    }
}

void JoystickControls::detectJoystickEvent(int controllerIndex){

    m_Up = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_UP);
    m_Down = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
    m_Left = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
    m_Right = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
    m_A = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_A);
    m_B = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_B);
    m_X = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_X);
    m_Y = SDL_GameControllerGetButton(Joystick[controllerIndex], SDL_CONTROLLER_BUTTON_Y);

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
