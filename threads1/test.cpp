#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::run()
{
    qInfo() << "running" << QThread::currentThread();
    m_timer.singleShot(3000, this, &Test::timeout);
    qInfo() << "finished" << QThread::currentThread();
}

void Test::timeout()
{
    qInfo() << "timeout" << QThread::currentThread();
}
