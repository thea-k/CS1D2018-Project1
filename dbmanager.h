#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTextCodec>
#include <algorithm>

class DbManager {
 public:
  DbManager();
  void initDataBase();
  void readInTxtFile();

 private:
  QSqlDatabase db_manager;
};

#endif  // DBMANAGER_H
