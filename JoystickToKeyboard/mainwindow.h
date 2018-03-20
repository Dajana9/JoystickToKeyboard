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
private slots:
void on_OkButton_clicked();

private:
    int getKeyValue(QString keyValue);
    void addElementsToComboBox();

    Ui::MainWindow *ui;
    JoystickControls *m_JoyManager;
    KeyBoard *m_keyboard;

    //first joystick
    int m_Up;
    int m_Down;
    int m_Left;
    int m_Right;
    int m_A;
    int m_B;
    int m_X;
    int m_Y;
    //second joystick
    int m_2Up;
    int m_2Down;
    int m_2Left;
    int m_2Right;
    int m_2A;
    int m_2B;
    int m_2X;
    int m_2Y;
};

#endif // MAINWINDOW_H
