#include "mythread.h"

MyThread::MyThread()
{
}

void MyThread::msleep(int ms)
{
    QThread::msleep(ms);
}
