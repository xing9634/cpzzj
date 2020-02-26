#include "realtableview.h"
#include"QPen"
#include"QPainter"
#include"qdebug.h"


RealTableView::RealTableView(QWidget *parent):QTableView(parent)
{

}
void RealTableView::paintEvent(QPaintEvent *e)
{
    QColor color[] = {Qt::darkMagenta,Qt::red,Qt::blue,Qt::green};
    QColor color1[] = {Qt::darkMagenta,Qt::red,Qt::blue,Qt::green};
    QPainter painter(this->viewport());
    painter.setRenderHint(QPainter::Antialiasing);
    QPen penm;
    penm.setWidth(3);
    painter.drawLine(0,this->rowViewportPosition(0),this->size().width(),this->rowViewportPosition(0));
    painter.drawLine(this->columnViewportPosition(0),0,this->columnViewportPosition(0),this->size().height());
    painter.drawLine(this->columnViewportPosition(1),0,this->columnViewportPosition(1),this->size().height());
    painter.drawLine(this->columnViewportPosition(5),0,this->columnViewportPosition(5),this->size().height());
    painter.drawLine(this->size().width(),0,this->size().width(),this->size().height());
    for(int i = 0;i<rowcount;i+=4)
    {
        painter.drawLine(0,this->rowViewportPosition(i),this->size().width(),this->rowViewportPosition(i));
    }
    for(int j = 0;j<9;j++)
     {
            magicTime(painter,line1[j],color[ (colored + j ) % 4 ]);
            magicTime(painter,line2[j],color1[ (colored + j ) % 4 ]);
     }
    QTableView::paintEvent(e);
}

void RealTableView::magicTime(QPainter &painter,QPointF *line,QColor color)
{
    if(line[0].rx()==0.0&&line[0].ry()==0.0)
        return ;
    if(this->indexAt(line[0].toPoint()).row()==-1||this->indexAt(line[0].toPoint()).column()==-1)
        return ;
    // 创建QPainter一个对象
    QPen pen;
    pen.setWidth(3);
    pen.setColor(color);
    painter.setPen(pen);
    QPainterPath qpp;
    qpp.moveTo(line[0]);
    //qDebug()<<pos<<ui->tableView->indexAt(line[pos].toPoint());
    //qDebug()<<pos<<line[pos].rx()<<line[pos].ry();
    for(int i = 0;i<3;i++)
    {
        if(line[i].rx()==0.0&&line[i].ry()==0.0)
            continue;
        if(this->indexAt(line[i].toPoint()).row()==-1||this->indexAt(line[i].toPoint()).column()==-1)
            continue;
        qpp.lineTo(line[i]);
        painter.drawEllipse(line[i],10,10);
    }
    painter.drawPath(qpp);
}
