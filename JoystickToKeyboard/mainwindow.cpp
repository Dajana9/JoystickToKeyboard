#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <linux/input-event-codes.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    m_JoyManager = new JoystickControls;
    m_JoyManager->start();
    m_keyboard = new KeyBoard;
    m_keyboard->uinputCreate();
    connect(m_JoyManager,SIGNAL(joystickButtonClicked(int,int)),this,SLOT(onJoystickButtonClicked(int,int)));
    connect(m_JoyManager,SIGNAL(joystickButtonRelease(int,int)),this,SLOT(onJoystickButtonReleased(int,int)));
}

MainWindow::~MainWindow()
{
    m_keyboard->uinputDestroy();
    delete ui;
}


void MainWindow::onJoystickButtonClicked(int joyastickValue, int controlerIndex){
    if(controlerIndex == 1){
        switch (joyastickValue) {
    //    case UP:
    //        m_keyboard->keyPress(KEY_UP);
    //        break;
    //    case DOWN:
    //        m_keyboard->keyPress(KEY_SPACE);
    //        break;
        case LEFT:
            m_keyboard->keyPress(KEY_LEFT);
            break;
        case RIGHT:
            m_keyboard->keyPress(KEY_RIGHT);
            break;
        case A:
            m_keyboard->keyPress(KEY_UP);
    //        break;
    //    case B:
    //        m_keyboard->keyPress(KEY_SPACE);
    //        break;
        case X:
            m_keyboard->keyPress(KEY_P);
            break;
    //    case Y:
    //        m_keyboard->keyPress(KEY_RIGHT);
    //        break;
        default:
            break;
        }
    } else {
        switch (joyastickValue) {
//        case UP:
//            m_keyboard->keyPress(KEY_UP);
//            break;
//        case DOWN:
//            m_keyboard->keyPress(KEY_SPACE);
//            break;
        case LEFT:
            m_keyboard->keyPress(KEY_A);
            break;
        case RIGHT:
            m_keyboard->keyPress(KEY_D);
            break;
        case A:
            m_keyboard->keyPress(KEY_W);
            break;
//        case B:
//            m_keyboard->keyPress(KEY_SPACE);
//            break;
        case X:
            m_keyboard->keyPress(KEY_SPACE);
            break;
//        case Y:
//            m_keyboard->keyPress(KEY_RIGHT);
//            break;
        default:
            break;
        }
    }

}

void MainWindow::onJoystickButtonReleased(int joyastickValue, int controlerIndex)
{
    if(controlerIndex == 1){
        switch (joyastickValue) {
//        case UP:
//            m_keyboard->keyRelease(KEY_UP);
//            break;
//        case DOWN:
//            m_keyboard->keyRelease(KEY_SPACE);
//            break;
        case LEFT:
            m_keyboard->keyRelease(KEY_LEFT);
            break;
        case RIGHT:
            m_keyboard->keyRelease(KEY_RIGHT);
            break;
        case A:
            m_keyboard->keyRelease(KEY_UP);
            break;
//        case B:
//            m_keyboard->keyRelease(KEY_SPACE);
//            break;
        case X:
            m_keyboard->keyRelease(KEY_P);
            break;
//        case Y:
//            m_keyboard->keyRelease(KEY_RIGHT);
//            break;
        default:
            break;
        }
    } else {
        switch (joyastickValue) {
//        case UP:
//            m_keyboard->keyRelease(KEY_UP);
//            break;
//        case DOWN:
//            m_keyboard->keyRelease(KEY_SPACE);
//            break;
        case LEFT:
            m_keyboard->keyRelease(KEY_A);
            break;
        case RIGHT:
            m_keyboard->keyRelease(KEY_D);
            break;
        case A:
            m_keyboard->keyRelease(KEY_W);
            break;
//        case B:
//            m_keyboard->keyRelease(KEY_SPACE);
//            break;
        case X:
            m_keyboard->keyRelease(KEY_SPACE);
            break;
//        case Y:
//            m_keyboard->keyRelease(KEY_RIGHT);
//            break;
        default:
            break;
        }
    }
}
