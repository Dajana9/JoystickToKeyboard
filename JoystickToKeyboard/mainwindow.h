#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joystickcontrols.h"
#include "keyboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
void onJoystickButtonClicked(int joyastickValue, int controlerIndex);
void onJoystickButtonReleased(int joyastickValue, int controlerIndex);
private:
    Ui::MainWindow *ui;
    JoystickControls *m_JoyManager;
    KeyBoard *m_keyboard;


};

#endif // MAINWINDOW_H
