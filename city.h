#ifndef CITY_H
#define CITY_H
#include <QString>

class City
{
public:
    City();
    City(QString, int);
    int getDistance() const;
    QString getName() const;
    void setDistance(int);
    void setName(QString);

private:
    QString cityName;
    int distanceFromPreviousCity;
};

#endif // CITY_H
