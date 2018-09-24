#include <city.h>

City::City()
{
    cityName = "NULL";
    distanceFromPreviousCity = 0;
}

City::City(QString x, int y)
{
    cityName = x;
    distanceFromPreviousCity = y;
}

QString City::getName() const
{
    return cityName;
}

int City::getDistance() const
{
    return distanceFromPreviousCity;
}

void City::setName(QString x)
{
    cityName = x;
}

void City::setDistance(int x)
{
    distanceFromPreviousCity = x;
}
