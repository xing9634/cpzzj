#ifndef QUERYINFO_H
#define QUERYINFO_H

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>
#include <QMouseEvent>
#include <QtSql>
#include "QTableView"
#include "QPainter"

class QueryInfo:public QAbstractItemView
{
    Q_OBJECT
public:
    bool ok;
    QPointF line1[6],line2[6];
    int len1,len2;
    QTableView *qc;
    QueryInfo(QWidget *parent=0);
    ~QueryInfo(){}
    int Pointof(QPointF *line,int n);
    QSqlQueryModel DataModel3;
    bool selected(QSqlDatabase db,int index,QTableView *tv);
    int getXfromMap(int data);
    int getYfromMap(int data);
    int mapper[4][5];
    QModelIndex indexAt(const QPoint &point) const{}
    void scrollTo(const QModelIndex &index,ScrollHint hint=EnsureVisible){}
    QRect visualRect(const QModelIndex &index)const{}

    void selector();

protected:
    void paintEvent(QPaintEvent *e);
    int horizontalOffset() const{}
    bool isIndexHidden(const QModelIndex &index)const{}
    QModelIndex moveCursor(CursorAction cursorAction,Qt::KeyboardModifiers modifiers){}
    void setSelection(const QRect &rect,QItemSelectionModel::SelectionFlags flags){

    }
    int verticalOffset() const{}
    QRegion visualRegionForSelection(const QItemSelection &selection) const{}
};

#endif // QUERYINFO_H
