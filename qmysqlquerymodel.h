#ifndef QMYSQLQUERYMODEL_H
#define QMYSQLQUERYMODEL_H
#include "QSqlTableModel"


class QMySQlQueryModel : public QSqlTableModel
{
public:
    QMySQlQueryModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // QMYSQLQUERYMODEL_H
