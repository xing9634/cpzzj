#include "sqlconnector.h"

SQLConnector::SQLConnector()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./zhongjiang.db");
    db.open();
}

QSqlDatabase SQLConnector::getDB()
{
    return db;
}
