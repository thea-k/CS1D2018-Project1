#include <string>
#include <vector>
using namespace std;

class City
{
public:
	City()
	{
		food.items.push()
	}


private:
	string name;
	Food food;
};


class Food
{
public:

//protected:
	struct Item; // Forward Declaration

	vector<Item> items;

	struct Item
	{
		string name;
		double price;
	};

private:
};


int main()
{};