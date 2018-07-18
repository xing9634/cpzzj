#include "sqlconnector.h"

SQLConnector::SQLConnector()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("zhongjiang");
    db.setUserName("root");
    db.setPassword("Dp448283676");
    db.open();
}

QSqlDatabase SQLConnector::getDB()
{
    return db;
}
