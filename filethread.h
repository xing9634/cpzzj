#ifndef FILETHREAD_H
#define FILETHREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QFileDialog>
#include <QSqlQuery>
#include<QDebug>
#include <QMutex>
#include<QDateTime>

class FileThread : public QThread
{
    Q_OBJECT
public:
    explicit FileThread(QObject *parent = 0)
        : QThread(parent),
          m_bStopped(false)
    {
            qDebug() << "Handle Thread : " << QThread::currentThreadId();
    }
    ~FileThread()
        {
                quit();
                wait();
        }
    QFile *file;
    QString kind;
    QString no;
    void set_kind(QString kind) {
        this->kind = kind;
    }
    void set_file(QFile *f) {
        file = f;
    }
    void set_no(QString no) {
        this->no = no;
    }
    typedef struct {
        QList<QByteArray> a;
        QList<QByteArray> b;
    }RF;
    RF readF;
    void store_file_text();
    virtual void run() Q_DECL_OVERRIDE {
        msleep(500);
        store_file_text();
        QMutexLocker locker(&m_mutex);
        if (m_bStopped)
             return ;
        emit signalRunOver();
    }
signals:
     void signalRunOver();
private:
        bool m_bStopped;
           QMutex m_mutex;
};

#endif // FILETHREAD_H
