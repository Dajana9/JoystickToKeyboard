#ifndef KEYBOARD_H
#define KEYBOARD_H


class KeyBoard
{
public:
    KeyBoard();
    int runMain();
    void listenToKeyboard();
    void keyPress(int key);
    void uinputCreate();
    void uinputDestroy();
    void keyRelease(int key);

private:
    void emitData(int fd, int type, int code, int val);

    int  m_fileData;
};

#endif // KEYBOARD_H
