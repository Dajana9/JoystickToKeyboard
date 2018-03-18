#ifndef JOYSTICKCONTROLS_H
#define JOYSTICKCONTROLS_H

#include <QThread>
#include <SDL2/SDL.h>

enum JoystickButton
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    A,
    B,
    X,
    Y
};

class JoystickControls : public QThread
{
     Q_OBJECT
public:
    JoystickControls(QObject *parent = nullptr);

protected:  
    void run() override;
signals:
    void joystickButtonClicked(int,int);
    void joystickButtonRelease(int,int);
private:
    void detectJoystickEvent(int controllerIndex);
    void sendClickedSignal(int controllerIndex);
    void sendReleasedSignal(SDL_Event event,int controllerIndex);
    int detectActiveJoystick();

    bool m_Up;
    bool m_Down;
    bool m_Left;
    bool m_Right;
    bool m_A;
    bool m_B;
    bool m_X;
    bool m_Y;



};

#endif // JOYSTICKCONTROLS_H
