#ifndef JOYSTICKCONTROLS_H
#define JOYSTICKCONTROLS_H

#include <QThread>

enum JoystickButton
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class JoystickControls : public QThread
{
     Q_OBJECT
public:
    JoystickControls(QObject *parent = nullptr);
    bool Up;
    bool Down;
    bool Left;
    bool Right;

protected:  
    void run() override;
signals:
    void joystickButtonClicked(int);
    void joystickButtonClickedUp();
private:
    void detectJoystickEvent(int controllerIndex);
    int detectActiveJoystick();


};

#endif // JOYSTICKCONTROLS_H
