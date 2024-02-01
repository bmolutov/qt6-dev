#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "constructed";
}

Counter::~Counter()
{
    qInfo() << this << "deconstructed";
}

void Counter::start()
{
    for (int i = 0; i < 10; ++i)
    {
        qInfo() << QThread::currentThread()->objectName() << " = " << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(1000));
        QThread::currentThread()->msleep(value);
        qInfo() << QThread::currentThread()->objectName() << "complete";
    }

    qInfo() << this << "completed";
    deleteLater();

    QThread::currentThread()->quit();
}
