#ifndef REALQTHREAD_H
#define REALQTHREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QProgressBar>
#include "corekernel.h"
#include <QMutexLocker>
#define MAXCMP 8
class RealQThread : public QThread
{
    Q_OBJECT
public:
    explicit RealQThread(QObject *parent = 0)
        : QThread(parent),
          m_bStopped(false)
    {
            qDebug() << "Handle Thread : " << QThread::currentThreadId();
    }
    ~RealQThread()
        {
                quit();
                wait();
        }
    void begin();
    void stop()
    {
        QMutexLocker locker(&m_mutex);
        m_bStopped = true;
        wait();
    }
    int started;
    void set_dw(Drawabler *dw) {
        this->dw2 = dw;
    }
    QSqlDatabase db;
    QProgressBar *qpb;
    QMySQlQueryModel *DataModel;
protected:
    virtual void run() Q_DECL_OVERRIDE {
        for(int mode = 0;mode < 4; mode ++) {
            msleep(500);
            dw2->FindBest(mode);
            QMutexLocker locker(&m_mutex);
            if (m_bStopped)
                 break;
        }
        emit signalRunOver();
    }
    signals:
        void resultReady(int value);
        void signalRunOver();
    private slots:
        void getdw(Drawabler *dw);
        void giveresult(int val) {
            emit resultReady(val);

        }
private:
        bool m_bStopped;
           QMutex m_mutex;
            Drawabler *dw2;
};

#endif // REALQTHREAD_H
