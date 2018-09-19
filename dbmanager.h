#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QTextCodec>
#include <algorithm>

class DbManager
{
public:
    DbManager();
    void initDataBase();
    void readInTxtFile();

private:
    QSqlDatabase db_manager;

};

#endif // DBMANAGER_H
