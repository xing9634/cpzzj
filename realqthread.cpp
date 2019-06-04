#include "realqthread.h"

RealQThread::RealQThread()
{

}

void RealQThread::run()
{
    int k = 0;
    for(int gap = 0;gap<4;gap++)
    {
        for(int cmp = 3;cmp<MAXCMP;cmp++)
        {
            qpb->setValue(k);
            k++;
            //QCoreApplication::processEvents();
            Drawabler dw1(gap,DataModel);
            //dw1.Find(db,gap,cmp,start);
        }
    }
    for(int gap = 0;gap<4;gap++)
    {
        for(int cmp = 3;cmp<MAXCMP;cmp++)
        {
            qpb->setValue(k);
            k++;
            //QCoreApplication::processEvents();
            Drawabler dw1(gap,DataModel);
            //dw1.Find2(db,gap,cmp,start);
        }
    }
}

void RealQThread::begin()
{
    run();
}
