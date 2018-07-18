#ifndef COREKERNEL_H
#define COREKERNEL_H
#define MAXSIZE 4
#include "mainwindow.h"
#include "qmap.h"
#include "QRunnable"
#include <QtSql>
#include"qtableview.h"
#define Point QPointF
#define xstr QPolygon

#endif // COREKERNEL_H

class Drawabler
{
public:
    QSqlDatabase *db;
    typedef struct Matrixx
    {
        int array[32][MAXSIZE];
        void Matrix() {
            for(int i = 0;i < 32;i ++)
            {
                for(int j = 0;j < MAXSIZE;j ++)
                {
                    array[i][j] = 0;
                }
            }
        }
    }matrix;
    matrix mat1;
    matrix mat2;
    int OneToOne(int num,int start,int gap,int cmp,int pos);
    int TwoToOne(int num,int start,int gap,int cmp,int pos);
    int ThreeToOne(int num,int start,int gap,int cmp,int pos);
    int OneToTwo(int num,int start,int gap,int cmp,int pos);
    int TwoToTwo(int num,int start,int gap,int cmp,int pos);
    int OneToThree(int num,int start,int gap,int cmp,int pos);
    int ThreeToTwo(int num,int start,int gap,int cmp,int pos);
    int TwoToThree(int num,int start,int gap,int cmp,int pos);
    int ThreeToThree(int num,int start,int gap,int cmp,int pos);
    int a[1000];
    bool is_way(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy);
    bool save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start);
    void Find(QSqlDatabase db,int gap,int cmp,int start);
    Drawabler(Matrixx &a,Matrixx &b,int gap,QMySQlQueryModel *DataModel)
    {
        int k = 1;
        for(int i = 0;i<MAXSIZE;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                maper[i][j] = k;
                k++;
            }
        }
        this->mat1=a;
        this->mat2=b;
        for(int i = 0;i<DataModel->rowCount();i++)
        {
            for(int j = 2;j<6;j++)
            {
                QModelIndex index = DataModel->index(i,j);
                QVariant data = DataModel->data(index,Qt::EditRole);
                mat1.array[i][j-2] = data.toInt();
                //printf("%4d",mat1.array[i][j]);
            }
            //printf("\n");
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
private:
};
