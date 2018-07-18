#ifndef SQLCONNECTOR_H
#define SQLCONNECTOR_H

#include"QtSql"

class SQLConnector
{

public:
    SQLConnector();
    QSqlDatabase getDB();
 private:
    QSqlDatabase db;
};

#endif // SQLCONNECTOR_H
