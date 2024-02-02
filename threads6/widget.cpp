#include "widget.h"

Widget::Widget(QObject *parent)
    : QObject{parent}
{
    m_isSender =false;
}

void Widget::workStarted()
{
    qInfo() << this << "started" << sender();
}

void Widget::workFinished()
{
    qInfo() << this << "finished" << sender();
    m_isActive = false;
}

void Widget::workReady(int i)
{
    qInfo() << this << "work" << i << sender();
}

void Widget::run()
{
    if(m_isSender)
    {
        qInfo() << this << "starting work...";
        emit started();

        for (int i = 0; i < 10; ++i)
        {
            qInfo() << this << "update...";
            emit update(i);
            QThread::currentThread()->msleep(500);
        }
        qInfo() << this << "finished...";
        emit finished();
    }
    else
    {
        qInfo() << this << "waiting for signals...";
        m_isActive = true;
        while (m_isActive)
        {
            QThread::currentThread()->msleep(100);
        }
    }
    qInfo() << this << "done";
}

bool Widget::isSender() const
{
    return m_isSender;
}

void Widget::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}
