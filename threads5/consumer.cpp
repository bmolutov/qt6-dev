#include "consumer.h"

Consumer::Consumer(QMutex *mutex, QWaitCondition *valueReady, int *value, QObject *parent)
{
    Q_UNUSED(parent);
    m_mutex = mutex;
    m_valueReady = valueReady;
    m_value = value;
}

void Consumer::run()
{
    qInfo() << "consumer is running";
    m_mutex->lock();
    qInfo() << "consumer locked the mutex";
    if (*m_value == 0)
    {
        qInfo() << "consumer is waiting on a value";
        m_valueReady->wait(m_mutex);
    }

    qInfo() << "Consuming:" << *m_value;
}
