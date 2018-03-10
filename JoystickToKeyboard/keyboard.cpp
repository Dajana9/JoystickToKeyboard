#include "keyboard.h"
#include <linux/uinput.h>
#include <iostream>
#include <QFile>
#include <sys/types.h>
#include <linux/hdreg.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <QDebug>
#include <stdlib.h>
#include <linux/kernel.h>


KeyBoard::KeyBoard()
{
}

void KeyBoard::emitData(int m_fileData, int type, int code, int val)
{
   struct input_event ie;
   memset(&ie, 0, sizeof(struct input_event));

   ie.type = type;
   ie.code = code;
   ie.value = val;
   ie.time.tv_sec = 0;
   ie.time.tv_usec = 0;
   if(write(m_fileData, &ie, sizeof(struct input_event)) < 0)
       qDebug()<<("error: write");
}

void KeyBoard::keyPress(int key)
{
       emitData(m_fileData, EV_KEY, key, 1);
       emitData(m_fileData, EV_SYN, 0, 0);
       emitData(m_fileData, EV_KEY, key, 0);
       emitData(m_fileData, EV_SYN, 0, 0);
}
void KeyBoard::keyRelease(int key)
{
    emitData(m_fileData, EV_KEY, key, 0);
    emitData(m_fileData, EV_SYN, 0, 0);
}

void KeyBoard::uinputCreate()
{
    struct uinput_user_dev uidev;

    m_fileData = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if(m_fileData < 0)
        qDebug()<<("error: open");

    //define which keys are you gonne use
    if(ioctl(m_fileData, UI_SET_EVBIT, EV_KEY) < 0)
        qDebug()<<("error: ioctl EV_KEY");
    if(ioctl(m_fileData, UI_SET_KEYBIT, KEY_LEFT) < 0)
        qDebug()<<("error: ioctl KEY");
    if(ioctl(m_fileData, UI_SET_KEYBIT, KEY_RIGHT) < 0)
        qDebug()<<("error: ioctl KEY");
    if(ioctl(m_fileData, UI_SET_KEYBIT, KEY_SPACE) < 0)
        qDebug()<<("error: ioctl KEY");
    if(ioctl(m_fileData, UI_SET_KEYBIT, KEY_UP) < 0)
        qDebug()<<("error: ioctl KEY");

    memset(&uidev, 0, sizeof(uidev));
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "uinput-sample");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor  = 0x1;
    uidev.id.product = 0x1;
    uidev.id.version = 1;

    if(write(m_fileData, &uidev, sizeof(uidev)) < 0)
        qDebug()<<("error: write");

    if(ioctl(m_fileData, UI_DEV_CREATE) < 0)
        qDebug()<<("error: ioctl CREATE");

    sleep(1);
    qDebug()<<"SVE STVORENO";
}

void KeyBoard::uinputDestroy(){

    if(ioctl(m_fileData, UI_DEV_DESTROY) < 0)
        qDebug()<<("error: ioctl");

    close(m_fileData);
}

