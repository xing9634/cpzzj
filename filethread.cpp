#include "filethread.h"

void FileThread::store_file_text()
{
    file->setFileName(kind +".txt");
    file->open(QIODevice::ReadOnly);
    QByteArray t ;
    int i  = 0;
    qDebug()<<file->isOpen();
    while(!file->atEnd() && i < 32) {
        t = file->readLine();
        QByteArray str;
        str.append(t);
        str.replace(" ","\t");
        readF.a = str.split('\t');
        qDebug()<<readF.a[0]<<readF.a[1]<<kind<<endl;
        QSqlQuery qsq;
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd");
        if(kind == "dlt_data" ) {
            qsq.prepare("insert into dlt_data(real_id,one,two,three,four,five,date,is_new) values(?,?,?,?,?,?,?,0)");
            for(int j = 0;j < 6;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(kind == "ssq_data" ) {
            qsq.prepare("insert into ssq_data(real_id,one,two,three,four,five,six,date,is_new)values(?,?,?,?,?,?,?,?,0)");
            for(int j = 0;j < 7;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(kind == "pl3_data" ) {
            qsq.prepare("insert into pl3_data(real_id,one,two,three,date,is_new) values(?,?,?,?,?,0)");
            for(int j = 0;j < 4;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(kind == "pl5_data" ) {
            qsq.prepare("insert into pl5_data(real_id,one,two,three,four,five,date,is_new) values(?,?,?,?,?,?,?,0)");
            for(int j = 0;j < 6;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(kind == "qxc_data" ) {
            qsq.prepare("insert into qxc_data(real_id,one,two,three,four,five,six,seven,date,is_new) values(?,?,?,?,?,?,?,?,?,0)");
            for(int j = 0;j < 8;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(kind == "fc3d_data" ) {
            qsq.prepare("insert into fc3d_data(real_id,one,two,three,date,is_new) values(?,?,?,?,?,0)");
            for(int j = 0;j < 4;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        }
        qsq.exec();
        qDebug()<<"ok";
        i++;
    }
    file->close();
}
