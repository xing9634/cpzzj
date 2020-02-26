#include "realqthread.h"

void RealQThread::begin()
{
    run();
}

void RealQThread::getdw(Drawabler *dw) {
    dw2 = dw;
}
