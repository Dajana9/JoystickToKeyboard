#ifndef JOYSTICKCONTROLS_H
#define JOYSTICKCONTROLS_H

#include <QThread>

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
    void joystickButtonClicked(int);
    void joystickButtonRelease(int);
private:
    void detectJoystickEvent(int controllerIndex);
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
