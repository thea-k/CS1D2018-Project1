#include "adminoperations.h"
#include "ui_adminoperations.h"

AdminOperations::AdminOperations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminOperations)
{
    ui->setupUi(this);
}

AdminOperations::~AdminOperations()
{
    delete ui;
}

void AdminOperations::on_loginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
