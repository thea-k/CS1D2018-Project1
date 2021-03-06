#include <vector>
#include <string>
#include "City.h"
using namespace std;

// Function prototype: startingCity is a default parameter
vector<City> nextClosest(vector<City> cities, int numCities, string startingCity = "");
bool contains(const vector<City> &cities, const string location);

// The algorithm to recursively find the next closest city to build a trip through Europe
// The vector of type City ("cities") is the most efficient path through Europe, and is eventually returned
// The int ("numCities") is the number of cities to visit. Once this number of is reached, the algorithm is finished
// The string ("startingCity") is a default parameter. The initial call of this algorithm should include the name of the
// city to start at
vector<City> nextClosest(vector<City> cities, int numCities, string startingCity)
{
	City potentialLocation = City();	// City variable that holds the data of the city that is potentially closest
	string currentCity = "";	// A string to tell the database what city we're currently on
	QSqlQuery query;	// The variable we're accessing the database with

	// If startingCity has a value, use that city to query the database with
	if (startingCity != "")
		currentCity = startingCity;

	// If there is not a startingCity parameter, use the last city we visited (from our vector)
	else
	{
		// Failure to pass an initial city (error check)
		if (cities.size() == 0)
			return cities;

		currentCity = cities.at(cities.size() - 1).getName();
	}

	// Reuqest data from the database based on the current city
	query.prepare("SELECT Ending, Distance from Distances WHERE Starting=(:val1)");
	query.bindValue(":val1", currentCity);
	query.exec();

	// While there are still elements in the query
	while (query.next())
	{
		// If the current city is NOT a visited city, continue, else, ignore the current query
		if (!contains(cities, query.value(0).toString()))
		{
			// If this is the first valid city, set it as our closest city
			if (potentialLocation.getName() == "NULL")
			{
				potentialLocation.setName(query.value(0).toString());
				potentialLocation.setDistance(query.value(1).toInt());
			}

			else
			{
				// If it is not the first city, check to see if the distance is shorter than our current closest
				// If it is closer, make it our closest city
				if (query.value(1).toInt() < potentialLocation.getDistance())
				{
					potentialLocation.setName(query.value(0).toString());
					potentialLocation.setDistance(query.value(1).toInt());
				}
			}
		}
	}

	// If our query returned no results, return cities (error check)
	if (potentialLocation.getName() == "NULL")
		return cities;

	// Once we've checked all the cities at a given location, add the closest city
	cities.push_back(potentialLocation);

	// If our cities vector size is equal to or greater than the number of cities we want to visit, return it
	// (Greater than is an error check)
	if (cities.size() >= numCities)
		return cities;

	// Else, continue calling the algorithm
	else
		return nextClosest(cities, numCities);
}

// Helper function for our Algorithm
// Checks to see whether or not we've visited a city before
bool contains(const vector<City> &cities, const string location)
{
	for (int i = 0; i < cities.size(); i++)
	{
		if (cities[i].getName() == location)
			return true;
	}

	return false;
}