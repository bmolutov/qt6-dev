#include <QCoreApplication>
#include <QThreadPool>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget* producer = new Widget();
    Widget* consumer = new Widget();

    producer->setObjectName("producer");
    consumer->setObjectName("consumer");
    producer->setIsSender(true);

    QObject::connect(producer, &Widget::started, consumer, &Widget::workStarted, Qt::AutoConnection);
    QObject::connect(producer, &Widget::update, consumer, &Widget::workReady, Qt::AutoConnection);
    QObject::connect(producer, &Widget::finished, consumer, &Widget::workFinished, Qt::AutoConnection);

    QThreadPool::globalInstance()->start(producer);
    QThreadPool::globalInstance()->start(consumer);

    return a.exec();
}
