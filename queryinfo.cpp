#include "queryinfo.h"


QueryInfo::QueryInfo(QWidget *parent):QAbstractItemView(parent)
{

}

int QueryInfo::Pointof(QPointF *line,int n)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(!line[i].isNull())
        {
            count++;
        }
    }
    return count;
}

void QueryInfo::selector()
{

    this->DataModel3.setQuery("select id,one,two,three from saveline1 where pose!= -1 and posc != -1 and poso != -1 and posh != -1");
    this->DataModel3.setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    this->DataModel3.setHeaderData(1, Qt::Horizontal, QObject::tr("one"));
    this->DataModel3.setHeaderData(2, Qt::Horizontal, QObject::tr("two"));
    this->DataModel3.setHeaderData(3, Qt::Horizontal, QObject::tr("three"));
    qDebug() << this->DataModel3.lastError();
}

int QueryInfo::getXfromMap(int data)
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(data == mapper[i][j])
                return i;
        }
    }
    return -1;
}

int QueryInfo::getYfromMap(int data)
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(data == mapper[i][j])
                return j;
        }
    }
    return -1;
}



bool QueryInfo::selected(QSqlDatabase db,int index,QTableView *tv)
{
    if(!db.isOpen())
        return false;
    else
    {
        ok = true;
        int i = 0,j = 0;
        QSqlQuery sql1;
        QSqlQuery sql2;
        QString as1;
        QString as2;
        QString s = QString::number(index-4, 10);
        QString t = QString::number(index+1, 10);
        as1 ="select one,two,three from saveline1 where 'id' >"+s+" and 'id' < "+t+"";
        as2 ="select one,two,three from saveline2 where 'id' >"+s+" and 'id' < "+t+"";
        sql1.prepare(as1);
        sql1.exec();
        qDebug() << sql1.lastError()<<as1;
        while(sql1.next())
        {
            switch(i)
            {

            case 0: {
                line1[0].setX(tv->columnViewportPosition(getXfromMap(sql1.value(0).toInt())));
                line1[0].setY(tv->rowViewportPosition(getYfromMap(sql1.value(0).toInt())));
                break;
            }
            case 1: {
                line1[1].setX(tv->columnViewportPosition(getXfromMap(sql1.value(1).toInt())));
                line1[1].setY(tv->rowViewportPosition(getYfromMap(sql1.value(1).toInt())));
                break;
            }
            case 2: {
                line1[2].setX(tv->columnViewportPosition(getXfromMap(sql1.value(2).toInt())));
                line1[2].setY(tv->rowViewportPosition(getYfromMap(sql1.value(2).toInt())));
                break;
            }
            }
            i++;
        }
        sql2.prepare(as2);
        sql2.exec();
        qDebug() << sql2.lastError()<<as2;
        while(sql2.next())
        {
            switch(j)
            {

            case 0: {
                line2[0].setX(tv->columnViewportPosition(getXfromMap(sql2.value(0).toInt())));
                line2[0].setY(tv->rowViewportPosition(getYfromMap(sql2.value(0).toInt())));
                break;
            }
            case 1: {
                line2[1].setX(tv->columnViewportPosition(getXfromMap(sql2.value(1).toInt())));
                line2[1].setY(tv->rowViewportPosition(getYfromMap(sql2.value(1).toInt())));
                break;
            }
            case 2: {
                line2[2].setX(tv->columnViewportPosition(getXfromMap(sql2.value(2).toInt())));
                line2[2].setY(tv->rowViewportPosition(getYfromMap(sql2.value(2).toInt())));
                break;
            }
            }
            j++;
        }
        len1 = Pointof(line1,6);
        len2 = Pointof(line2,6);

    }
    repaint();

    return true;
}



void QueryInfo::paintEvent(QPaintEvent *e)
{     // 创建QPainter一个对象
    if(!ok)
        return;
    QPainter painter(viewport());
    QPen pen;
    //painter.begin(this);
    QBrush bruch(Qt::FDiagPattern);     // 画刷
    pen.setColor(Qt::red);
    painter.setPen(pen);
    qDebug() <<"Hey Man";
    bruch.setStyle(Qt::NoBrush);        // 将画刷设置成null//fow what
    painter.setBrush(bruch);
    painter.drawPolyline(line1, len1);
    painter.drawText(10,80,"FUck ouo!");
    pen.setColor(Qt::red);
    painter.setPen(pen);
    bruch.setStyle(Qt::NoBrush);        // 将画刷设置成null//fow what
    painter.setBrush(bruch);
    painter.drawPolyline(line2, len2);
}

