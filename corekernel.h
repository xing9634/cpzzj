#ifndef COREKERNEL_H
#define COREKERNEL_H
#define MAXDEF 4
#include "qmysqlquerymodel.h"
#include "qmap.h"
#include "matrix.h"
#include "QRunnable"
#include <QtSql>
#include"qtableview.h"
#define Point QPointF
#define xstr QPolygon

#endif // COREKERNEL_H

class Drawabler:public QObject
{
    Q_OBJECT
public:
    QSqlDatabase *db;
    matrix mat1;
    matrix mat2;
    int MAXSIZE;
    bool make_set1(int ax,int ay,int no,int num);
    bool make_set2(int ax,int ay,int no);
    bool is_way(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy);
    bool is_way2(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy);
    bool save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start,int mode);
    ~Drawabler(){

    }
    Drawabler(int gap,QMySQlQueryModel *DataModel)
    {
        int k = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                maper[i][j] = k;
                k++;
            }
        }
        for(int i = 0;i<6;i++)
        {
            str1[i] = -1;
            str2[i] = -1;
        }
    }
    int maper[4][4];
    int str1[6];
    int str2[6];
    int gapslot;
    int re_start;
    QSqlDatabase dbslot;
    int cmpslot;
    QString kind;
    int startslot;
    pset s1;
    pset s2;
    int maptoi(int num);
    int maptoj(int num);
    void make_empty(pset *s);
    bool Find(QSqlDatabase db,int gap,int start,matrix matb,int mode);
    void make_mat(int col,matrix matb);
    void make_matfirst(int col,matrix matb);
    void Find2(QSqlDatabase db,int gap,int start);
private:
};
