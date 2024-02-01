#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    for (int i = 0; i < 5; ++i)
    {
        QThread* thread = new QThread(this);
        thread->setObjectName("thread " + QString::number(i));
        qInfo() << "created:" << thread->objectName();

        connect(thread, &QThread::started, this, &Manager::started);
        connect(thread, &QThread::finished, this, &Manager::finished);

        threads.append(thread);
    }
}

void Manager::start()
{
    qInfo() << "starting...";
    foreach(QThread* thread, threads)
    {
        qInfo() << "starting:" << thread->objectName();

        Counter* c = new Counter(); // raw pointer
        c->moveToThread(thread);
        connect(thread, &QThread::started, c, &Counter::start);
        thread->start();
    }
}

void Manager::started()
{
    qInfo() << "starting" << sender();
    QThread* thread = qobject_cast<QThread*>(sender());
    if (!thread)
        return;
    qInfo() << "started:" << thread->objectName();
}

void Manager::finished()
{
    qInfo() << "finishing" << sender();
    QThread* thread = qobject_cast<QThread*>(sender());
    if (!thread)
        return;
    qInfo() << "children len" << thread->children().length();
    qInfo() << "finished:" << thread->objectName();

    threads.removeAll(thread);
    delete thread;
}
