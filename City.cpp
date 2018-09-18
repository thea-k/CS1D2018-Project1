#include "City.h"

City::City()
{
	cityName = "NULL";
	distanceFromPreviousCity = 0;
}

City::City(string x, int y)
{
	cityName = x;
	distanceFromPreviousCity = y;
}

string City::getName() const
{
	return cityName;
}

int City::getDistance() const
{
	return distanceFromPreviousCity;
}

void City::setName(string x)
{
	cityName = x;
}

void City::setDistance(int x)
{
	distanceFromPreviousCity = x;
}