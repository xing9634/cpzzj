#include "qmysqlquerymodel.h"
#include"qsqldatabase.h"

QMySQlQueryModel::QMySQlQueryModel(QObject *parent, QSqlDatabase db):QSqlTableModel (parent,db)
{

}


QVariant QMySQlQueryModel::data(const QModelIndex &item, int role) const

{
    QVariant value = QSqlTableModel::data(item, role);
    if(role ==  Qt::TextAlignmentRole )
    {
        value   =   (Qt::AlignCenter);
        return value;
    }
    return value;
}



