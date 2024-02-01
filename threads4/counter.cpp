#include "counter.h"

Counter::Counter(QMutex *mutex, int *value) : m_mutex(mutex), m_value(value) {}

void Counter::run()
{
    // wait until we can do stuff...
    m_mutex->lock(); // we will wait untill we can lock!

    // our code here...
    QThread::currentThread()->msleep(500);
    *m_value = *m_value + 1;
    qInfo() << *m_value << QThread::currentThread();

    m_mutex->unlock(); // other threads can lock
}
