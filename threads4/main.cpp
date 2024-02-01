#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("main");
    QThreadPool* pool = QThreadPool::globalInstance();

    QMutex mutex;
    int value = 0;
    qInfo() << pool->maxThreadCount() << " threads";

    for (int i = 0; i < 100; ++i)
    {
        Counter* c = new Counter(&mutex, &value);
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
