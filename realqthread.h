#ifndef REALQTHREAD_H
#define REALQTHREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QProgressBar>
#include "corekernel.h"
#define MAXCMP 8
class RealQThread : public QThread
{
    Q_OBJECT
public:
    RealQThread();
    ~RealQThread(){

    }
    void begin();
    int start;
    Drawabler *dw2;
    void stop();
    QSqlDatabase db;
    QProgressBar *qpb;
    QMySQlQueryModel *DataModel;
protected:
    void run();

};

#endif // REALQTHREAD_H
