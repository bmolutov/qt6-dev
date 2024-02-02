#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition valueReady;
    QMutex mutex;
    int value = 0;

    Producer *producer = new Producer(&mutex, &valueReady, &value);
    Consumer *consumer = new Consumer(&mutex, &valueReady, &value);

    QThread producerThread;
    QThread consumerThread;
    producer->moveToThread(&producerThread);
    consumer->moveToThread(&consumerThread);

    QObject::connect(&producerThread, &QThread::started, producer, &Producer::run);
    QObject::connect(&consumerThread, &QThread::started, consumer, &Consumer::run);

    producerThread.start();
    consumerThread.start();

    return a.exec();
}
