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
    connect(m_JoyManager,SIGNAL(joystickButtonClicked(int)),this,SLOT(onJoystickButtonClicked(int)));
}

MainWindow::~MainWindow()
{
    m_keyboard->uinputDestroy();
    delete ui;
}


void MainWindow::onJoystickButtonClicked(int joyastickValue){
    qDebug()<<joyastickValue;
    switch (joyastickValue) {
    case UP:
        m_keyboard->keyPress(KEY_UP);
        break;
    case DOWN:
        m_keyboard->keyPress(KEY_SPACE);
        break;
    case LEFT:
        m_keyboard->keyPress(KEY_LEFT);
        break;
    case RIGHT:
        m_keyboard->keyPress(KEY_RIGHT);
        break;
    default:
        m_keyboard->keyRelease(KEY_UP);
        m_keyboard->keyRelease(KEY_DOWN);

        break;
    }

}
