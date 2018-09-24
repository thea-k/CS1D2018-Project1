#ifndef TRAVELERSMAINWINDOW_H
#define TRAVELERSMAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "city.h"

namespace Ui {
class TravelersMainWindow;
}

class TravelersMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TravelersMainWindow(QWidget *parent = nullptr);
    ~TravelersMainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TravelersMainWindow *ui;
};

// Function prototype: startingCity is a default parameter
QVector<City> nextClosest(QVector<City> cities, int numCities, QString startingCity = "");
bool contains(const QVector<City> &cities, const QString location);
int getDistanceTraveled(const QVector<City> &cities);  // Story 8
void getSurroundingCities(const QString baseCity);


#endif // TRAVELERSMAINWINDOW_H
