#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <linux/input-event-codes.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addElementsToComboBox();

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
        case UP:
            m_keyboard->keyPress(m_Up);
            break;
        case DOWN:
            m_keyboard->keyPress(m_Down);
            break;
        case LEFT:
            m_keyboard->keyPress(m_Left);
            break;
        case RIGHT:
            m_keyboard->keyPress(m_Right);
            break;
        case A:
            m_keyboard->keyPress(m_A);
            break;
        case B:
            m_keyboard->keyPress(m_B);
            break;
        case X:
            m_keyboard->keyPress(m_X);
            break;
        case Y:
            m_keyboard->keyPress(m_Y);
            break;
        default:
            break;
        }
    } else if (controlerIndex == 2) {
        switch (joyastickValue) {
        case UP:
            m_keyboard->keyPress(m_2Up);
            break;
        case DOWN:
            m_keyboard->keyPress(m_2Down);
            break;
        case LEFT:
            m_keyboard->keyPress(m_2Left);
            break;
        case RIGHT:
            m_keyboard->keyPress(m_2Right);
            break;
        case A:
            m_keyboard->keyPress(m_2A);
            break;
        case B:
            m_keyboard->keyPress(m_2B);
            break;
        case X:
            m_keyboard->keyPress(m_2X);
            break;
        case Y:
            m_keyboard->keyPress(m_2Y);
            break;
        default:
            break;
        }
    }

}

void MainWindow::onJoystickButtonReleased(int joyastickValue, int controlerIndex)
{
    if(controlerIndex == 1){
        switch (joyastickValue) {
        case UP:
            m_keyboard->keyRelease(m_Up);
            break;
        case DOWN:
            m_keyboard->keyRelease(m_Down);
            break;
        case LEFT:
            m_keyboard->keyRelease(m_Left);
            break;
        case RIGHT:
            m_keyboard->keyRelease(m_Right);
            break;
        case A:
            m_keyboard->keyRelease(m_A);
            break;
        case B:
            m_keyboard->keyRelease(m_B);
            break;
        case X:
            m_keyboard->keyRelease(m_X);
            break;
        case Y:
            m_keyboard->keyRelease(m_Y);
            break;
        default:
            break;
        }
    } else if (controlerIndex == 2) {
        switch (joyastickValue) {
        case UP:
            m_keyboard->keyRelease(m_2Up);
            break;
        case DOWN:
            m_keyboard->keyRelease(m_2Down);
            break;
        case LEFT:
            m_keyboard->keyRelease(m_2Left);
            break;
        case RIGHT:
            m_keyboard->keyRelease(m_2Right);
            break;
        case A:
            m_keyboard->keyRelease(m_2A);
            break;
        case B:
            m_keyboard->keyRelease(m_2B);
            break;
        case X:
            m_keyboard->keyRelease(m_2X);
            break;
        case Y:
            m_keyboard->keyRelease(m_2Y);
            break;
        default:
            break;
        }
    }
}



void MainWindow::on_OkButton_clicked()
{
    //First joystick
    QString leftKeyClicked = ui->LeftBox->currentText();
    m_Left = getKeyValue(leftKeyClicked);

    QString rightKeyClicked = ui->RightBox->currentText();
    m_Right = getKeyValue(rightKeyClicked);

    QString upKeyClicked = ui->UpBox->currentText();
    m_Up = getKeyValue(upKeyClicked);

    QString downKeyClicked = ui->DownBox->currentText();
    m_Down = getKeyValue(downKeyClicked);

    QString aKeyClicked = ui->ABox->currentText();
    m_A = getKeyValue(aKeyClicked);

    QString bKeyClicked = ui->BBox->currentText();
    m_B = getKeyValue(bKeyClicked);

    QString xKeyClicked = ui->XBox->currentText();
    m_X = getKeyValue(xKeyClicked);

    QString yKeyClicked = ui->YBox->currentText();
    m_Y = getKeyValue(yKeyClicked);

    //Second joystick
    QString leftKeyClicked_2 = ui->LeftBox_2->currentText();
    m_2Left = getKeyValue(leftKeyClicked_2);

    QString rightKeyClicked_2 = ui->RightBox_2->currentText();
    m_2Right = getKeyValue(rightKeyClicked_2);

    QString upKeyClicked_2 = ui->UpBox_2->currentText();
    m_2Up = getKeyValue(upKeyClicked_2);

    QString downKeyClicked_2 = ui->DownBox_2->currentText();
    m_2Down = getKeyValue(downKeyClicked_2);

    QString aKeyClicked_2 = ui->ABox_2->currentText();
    m_2A = getKeyValue(aKeyClicked_2);

    QString bKeyClicked_2 = ui->BBox_2->currentText();
    m_2B = getKeyValue(bKeyClicked_2);

    QString xKeyClicked_2 = ui->XBox_2->currentText();
    m_2X = getKeyValue(xKeyClicked_2);

    QString yKeyClicked_2 = ui->YBox_2->currentText();
    m_2Y = getKeyValue(yKeyClicked_2);
}


int MainWindow::getKeyValue(QString keyClicked)
{
   QFile file("/home/dajana/git/JoystickToKeyboard/keyboardDataBase.txt");
   if(!file.open(QIODevice::ReadOnly)) {
       qDebug()<<"Error, file not ready/open";
   }

   QTextStream in(&file);
   while(!in.atEnd()) {
       QString line = in.readLine();
       QStringList fields = line.split("=");
       if(fields.at(0)==keyClicked){
           return fields.at(1).toInt();
       }
   }
   return 0;
}

void MainWindow::addElementsToComboBox(){
    QFile file("/home/dajana/git/JoystickToKeyboard/keyboardDataBase.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Error, file not ready/open";
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("=");
        //First joystick
        ui->LeftBox->addItem(fields.at(0));
        ui->RightBox->addItem(fields.at(0));
        ui->ABox->addItem(fields.at(0));
        ui->BBox->addItem(fields.at(0));
        ui->UpBox->addItem(fields.at(0));
        ui->DownBox->addItem(fields.at(0));
        ui->XBox->addItem(fields.at(0));
        ui->YBox->addItem(fields.at(0));
        //Second joystick
        ui->LeftBox_2->addItem(fields.at(0));
        ui->RightBox_2->addItem(fields.at(0));
        ui->ABox_2->addItem(fields.at(0));
        ui->BBox_2->addItem(fields.at(0));
        ui->UpBox_2->addItem(fields.at(0));
        ui->DownBox_2->addItem(fields.at(0));
        ui->XBox_2->addItem(fields.at(0));
        ui->YBox_2->addItem(fields.at(0));
    }

}
