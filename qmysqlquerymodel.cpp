#include "qmysqlquerymodel.h"
#include"qsqldatabase.h"
#include <QFont>
#include <QColor>
#include<QBrush>

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
    if(role == Qt::FontRole) {
        if(item.column() == 0) {
            value =  QFont( "Times", 7, QFont::Black );
        } else {
            value =  QFont( "Times", 11, QFont::Black );
        }
    }
    if(role == Qt::ForegroundRole) {
        if(item.column() == 0) {
            value = QBrush(QColor(0, 0, 255));
        }
    }
    return value;
}



