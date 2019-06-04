#ifndef REALTABLEVIEW_H
#define REALTABLEVIEW_H
#include"QTableView"

class RealTableView : public QTableView
{
    Q_OBJECT
public:
    RealTableView(QWidget *parent = 0);
    ~RealTableView(){}
    QPointF line1[32][3];
    QPointF line2[32][3];
    int columncount;
    int rowcount;
    int colored;
    void magicTime(QPainter &painter,QPointF *line,QColor color);
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // REALTABLEVIEW_H
