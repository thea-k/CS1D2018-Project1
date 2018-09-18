#pragma once
#ifndef H-City
#define H_City

#include <string>
using namespace std;

class City
{
public:
	City();
	City(string, int);
	int getDistance() const;
	string getName() const;
	void setDistance(int);
	void setName(string);

private:
	string cityName;
	int distanceFromPreviousCity;
};

#endif // !"City.h"