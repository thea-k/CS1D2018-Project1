#ifndef TRAVELERSMAINWINDOW_H
#define TRAVELERSMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <algorithm>

#include "dbmanager.h"
#include "adminoperations.h"
#include "trip.h"


namespace Ui {
class TravelersMainWindow;
}

class TravelersMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TravelersMainWindow(QWidget *parent = nullptr);
    ~TravelersMainWindow();

    void populateDisplay();

private slots:


    void selectedCity();

    void on_pb_NextCity_clicked();

    void on_pb_back_clicked();

   void openAdminWindow();

private:
    Ui::TravelersMainWindow *ui;
    AdminOperations * adminWindow;
    Trip * tripOperations;

};

#endif // TRAVELERSMAINWINDOW_H
