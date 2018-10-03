#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QTextCodec>
#include <algorithm>
#include "city.h"

class DbManager
{
public:
    DbManager();
    static DbManager * getInstance();
    void initDataBase();
    QVector<QString> getCities();
    QVector<TraditionalFoodItems> getMenuItems(const QString& city);
    float getDistanceInbetween(const QString & starting, const QString & ending);

    void readInTxtFile();


private:
    QSqlDatabase db_manager;
    static DbManager * controller;


};

#endif // DBMANAGER_H
