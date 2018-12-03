#include "mythread.h"
#include <QtCore>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run() {
    for(; i < INT_MAX; i++){
        QMutex mutex;
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();

        emit NumberChanged(i);
        this->msleep(100);
    }
}
