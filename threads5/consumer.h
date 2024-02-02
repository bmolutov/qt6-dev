#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QMutex *mutex, QWaitCondition *valueReady, int *value, QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QMutex *m_mutex;
    QWaitCondition *m_valueReady;
    int *m_value;
};

#endif // CONSUMER_H
