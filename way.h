#ifndef WAY_H
#define WAY_H

#endif // WAY_H

#include <QtSql>
#include"qtableview.h"
#include "qmysqlquerymodel.h"

#define MAXNN 1000

class Way {
public:
    int pointX[3];
    int pointY[3];
    int cmp;
    int start;
    int gap;
    int cst_start;
    int martix[4][4];
    QQueue<int> queue;
    QMap<int,int> map;
    QSqlDatabase db;
    int ret_pos(int pos);
    void FindWay(int js,QMySQlQueryModel *dm);
    bool is_way(int prestart,int js,QMySQlQueryModel *dm,int &sum);
    bool save(QSqlDatabase db,int gap,int cmp,int pos,int start,int num);
    QModelIndex maptore(int point,QMySQlQueryModel *dm,int start,int js);
    Way(QSqlDatabase dbs,QMySQlQueryModel *dm,int startpos,int js,int jgap);
    int vis[MAXNN];
    ~Way(){}

};
