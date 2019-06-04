#include "way.h"
#include "qmysqlquerymodel.h"


Way::Way(QSqlDatabase dbs,QMySQlQueryModel *dm,int startpos,int js,int jgap) { //做好查询初始化
    int cmp = 0;
    int gap = jgap;
    int start = startpos;
    db = dbs;
    for(int i = 0;i < 100;i ++) {
        map.insert(i,i % 10);
    }
}





QModelIndex Way::maptore(int point,QMySQlQueryModel *dm,int start,int js)
{
    int k  = 0;
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++)
        {
            if(k == point)
            {
                return dm->index(i+start,j+js);
            }
            k++;
        }
    }
    return dm->index(0,0);
}


bool Way::save(QSqlDatabase db,int gap,int cmp,int pos,int start,int num)
{
    if(!db.open())
        return false;
    QSqlQuery qsq;
    qsq.prepare("insert into realdata1(num,data1,data2,data3,gap,cmp,pos,start,mode) values (?,?,?,?,?,?,?,?,?)");
    qsq.addBindValue(num);
    qsq.addBindValue(pointX[0]);
    qsq.addBindValue(pointX[1]);
    qsq.addBindValue(pointX[2]);
    qsq.addBindValue(gap);
    qsq.addBindValue(cmp);
    qsq.addBindValue(pos);
    qsq.addBindValue(start);
    qsq.addBindValue(1);
    qsq.exec();
    qDebug()<<qsq.lastError();
    QSqlQuery qsq1;
    qsq1.prepare("insert into realdata2(num,data1,data2,data3,gap,cmp,pos,start,mode) values (?,?,?,?,?,?,?,?,?)");
    qsq1.addBindValue(num);
    qsq1.addBindValue(pointY[0]);
    qsq1.addBindValue(pointY[1]);
    qsq1.addBindValue(pointY[2]);
    qsq1.addBindValue(gap);
    qsq1.addBindValue(cmp);
    qsq1.addBindValue(pos);
    qsq1.addBindValue(start);
    qsq1.addBindValue(1);
    qsq1.exec();
    qDebug()<<qsq1.lastError();
    return true;
}

bool Way::is_way(int prestart,int js,QMySQlQueryModel *dm,int &sum) {
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i < 3;i ++) {
        QVariant data1 = dm->data(maptore(pointX[i],dm,prestart,js),Qt::EditRole);
        sum1 = (data1.toInt() + sum1) % 10;
        QVariant data2 = dm->data(maptore(pointY[i],dm,prestart,js),Qt::EditRole);
        sum2 += (data2.toInt() + sum2) % 10;
    }
    if(sum1 == sum2) {
        sum = sum1;
        return true;
    }
    return false;
}

int Way::ret_pos(int pos) {
    if(pos == 0) {
        return 13;
    } else if(pos == 1) {
        return 14;
    } else if(pos == 2) {
        return 15;
    } else if(pos == 3) {
        return 16;
    }
}

while(is_way(start,js,dm,sum) == true) {
    cmp++;
    start += 4 + gap;
    ok = true;
}
if(ok)
    save(db,gap,cmp,pos + 13,start,sum);
else
    qDebug() << "Error.....................";

void Way::FindWay(int js,QMySQlQueryModel *dm) {
    int sum = 0;
    bool ok = false;
    for(int pos = 0;pos < 4;pos ++) {
        queue.enqueue(pos + 13);
        int k = 0;
        while(!queue.empty()) {
            if(k >= 3) {
                break;
            }
            pointX[k++] = queue.front();
            queue.dequeue();
            for(int i = 1;i < 13;i ++) {
                for(int j = 1;j < 13;j ++) {
                    for(int k = 1;k < 13;k ++) {
                        for(int s = 1;s < 13;s ++) {
                            for(int t = 1;t < 13;t ++) {

                            }
                        }
                    }
                }
            }

        }
        queue.clear();
    }
}
