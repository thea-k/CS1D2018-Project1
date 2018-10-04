#ifndef ADMINOPERATIONS_H
#define ADMINOPERATIONS_H

#include <QDialog>
#include <QStringListModel>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include "dbmanager.h"

namespace Ui {
class AdminOperations;
}

class AdminOperations : public QDialog
{
    Q_OBJECT

public:
    explicit AdminOperations(QWidget *parent = nullptr);
    ~AdminOperations();





private slots:
    void on_loginButton_clicked();

    void setTableView(int index);

    void on_addItemButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::AdminOperations *ui;
    QStringListModel * citiesModel;
    QSqlQueryModel * queryModel;



};

#endif // ADMINOPERATIONS_H
