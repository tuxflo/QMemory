#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
public:
    MyThread();
    static void msleep(int ms);
};

#endif // MYTHREAD_H
