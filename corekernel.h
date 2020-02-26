#ifndef COREKERNEL_H
#define COREKERNEL_H
#define MAXDEF 4
#include "qmysqlquerymodel.h"
#include "qmap.h"
#include "matrix.h"
#include <QtSql>
#include"qtableview.h"
#define Point QPointF
#define xstr QPolygon

#endif // COREKERNEL_H
#include <QThread>
class Drawabler:public QObject
{
    Q_OBJECT
public:
    QSqlDatabase db;
    matrix mat1;
    matrix mat2;
    matrix matA[6];
    int MAXSIZE;
    int gaps;
    int times[5] = {2,4,1,2,1};
    int starts;
    int indexs;
    bool make_set1(int ax,int ay,int no,int num);
    bool make_set2(int ax,int ay,int no);
    bool is_way(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy);
    bool is_way2(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy);
    bool save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start,int mode);
    ~Drawabler(){

        delete this;

    }
    int knt = 0;
    Drawabler()
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
    int maper[5][5];
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
    bool Find(QSqlDatabase db,int gap,int start,matrix matb,int mode,int dec);
    void make_mat(int col,int mode);
    void make_matfirst(int col,int mode);
    int FindBest(int gap);
private slots:
signals:
    int givesig(int val);
    int givedec(int val0,int val);
};
