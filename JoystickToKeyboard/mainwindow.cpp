#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);

    m_JoyManager = new JoystickControls;
    m_JoyManager->start();

    connect(m_JoyManager,SIGNAL(joystickButtonClicked(int)),this,SLOT(onJoystickButtonClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onJoystickButtonClicked(int joyastickValue){
    qDebug()<<joyastickValue;


}
