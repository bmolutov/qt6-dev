#include <QCoreApplication>
#include <QThread>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("main thread");
    qInfo() << "starting" << QThread::currentThread();

    QThread worker;
    worker.setObjectName("worker thread");

    Test test;
    test.moveToThread(&worker);
    QObject::connect(&worker, &QThread::started, &test, &Test::run);
    worker.start();

    qInfo() << "finished" << QThread::currentThread();

    return a.exec();
}
