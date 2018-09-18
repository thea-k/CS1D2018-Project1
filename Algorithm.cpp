#include <vector>
#include <string>
using namespace std;

struct City
{
	string name;
	int distance;
};

vector<City> nextClosest(vector<City> cities, int numCities, string startingCity)
{
	City tempLocation = { "NULL", 0 };	// Initialization of the city we're using to compare
	string currentCity = "";	// A string to tell the database what city we're currently on
	QSqlQuery query;	// The variable we're accessing the database with

	// If startingCity has a value, use that city to query the database with
	if (startingCity != "")
		currentCity = startingCity;

	// If there is not a startingCity parameter, use the last city we visited (from our vector)
	else
		currentCity = cities.at(cities.size() - 1).name;

	// Reuqest data from the database based on the current city
	query.prepare("SELECT Ending, Distance from Distances WHERE Starting=(:val1)");
	query.bindValue(":val1", currentCity);
	query.exec();

	// While there are still elements in the query
	while (query.next())
	{
		// If the current city is NOT a visited city, continue, else ignore the current query
		if (!contains(cities, query.value(0).toString()))
		{
			// If this is the first valid city, set it as our closest city
			if (tempLocation.name == "NULL")
			{
				tempLocation.name = query.value(0).toString();
				tempLocation.distance = query.value(1).toInt();
			}

			else
			{
				// If it is not the first city, check to see if the distance is shorter than our current closest
				// If it is closer, make it our closest city
				if (query.value(1).toInt() < tempLocation.distance)
				{
					tempLocation.name = query.value(0).toString();
					tempLocation.distance = query.value(1).toInt();
				}
			}
		}
	}

	// If our query returned nothing, return cities (error check)
	if (tempLocation.name == "NULL")
		return cities;

	// Once we've checked all the cities at a given location, add the closest city
	cities.push_back(tempLocation);

	// If our cities vector size is equal to or greater than the number of cities we want to visit, return it
	if (cities.size() >= numCities)
		return cities;

	// Else, continue calling the algorithm
	else
		return nextClosest(cities, numCities);

}


// Helper function for our Algorithm
// Checks to see whether or not we've visited a city before
bool contains(vector<City> cities, string location)
{
	for (int i = 0; i < cities.size(); i++)
	{
		if (cities[i].name == location)
			return true;
	}

	return false;
}
