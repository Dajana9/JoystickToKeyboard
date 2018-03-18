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
void onJoystickButtonClicked(int joyastickValue);
void onJoystickButtonReleased(int joyastickValue);
private:
    Ui::MainWindow *ui;
    JoystickControls *m_JoyManager;
    KeyBoard *m_keyboard;


};

#endif // MAINWINDOW_H
