#include "adminoperations.h"
#include "ui_adminoperations.h"

AdminOperations::AdminOperations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminOperations)
{
    ui->setupUi(this);

    ui->tableView->setEditTriggers(QAbstractItemView::EditKeyPressed);



}

AdminOperations::~AdminOperations()
{
    delete ui;
}

void AdminOperations::on_loginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    citiesModel = new QStringListModel(this);

    QStringList citiesList;

    QVector<QString> cities = DbManager::getInstance()->getCities();

    for(QVector<QString>::iterator it = cities.begin(); it != cities.end(); it++ )
    {
        citiesList << *it;
    }

    citiesModel->setStringList(citiesList);



    ui->comboBox->setModel(citiesModel);



     connect(ui->comboBox, SIGNAL(activated(int)),this, SLOT(setTableView(int)));



}

void AdminOperations::setTableView(int index)
{
    QVector<QString> cities = DbManager::getInstance()->getCities();
    queryModel = new QSqlQueryModel(this);


    //     int index = ui->comboBox->currentIndex();
    QString selectedCity = cities.at(index);

    queryModel->setQuery("SELECT Item, Cost, PurchaseCount, PurchaseAmtTotal FROM Items WHERE City='"+selectedCity+"'");
    queryModel->setHeaderData(0, Qt::Horizontal, tr("Item"));
    queryModel->setHeaderData(1, Qt::Horizontal, tr("Cost"));
    queryModel->setHeaderData(1, Qt::Horizontal, tr("Amount of Purchase"));
    queryModel->setHeaderData(1, Qt::Horizontal, tr("Total Purchase"));

    ui->tableView->setModel(queryModel);
}

void AdminOperations::on_addItemButton_clicked()
{
    ui->newItemStackedWidget->setCurrentIndex(1);

}

void AdminOperations::on_saveButton_clicked()
{
    QVector<QString> cities = DbManager::getInstance()->getCities();

    int index = ui->comboBox->currentIndex();

    QString city = cities.at(index);

    QString item = ui->itemLineEdit->text();

    double price = (ui->priceLineEdit->text()).toDouble();

    qDebug() << "city: " << city << "item: " << item << "price: " << price;


    if(DbManager::getInstance()->itemExist(city, item))
    {
        qDebug() << "item exist";
    }
    else
    {
        qDebug() << "item DOES NOT exist";
    }

    /*
     * implement adding and updating
     */


}
