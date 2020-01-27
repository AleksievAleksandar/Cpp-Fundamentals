#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class City
{
public:
	std::string name;
	double totalPrice;
private:
	double pricePerProduct;
	size_t quantity;

public:
	City(std::string name, double pricePerProduct, size_t quantity) :
		name(name),
		pricePerProduct(pricePerProduct),
		quantity(quantity)
	{
		this->totalPrice = this->pricePerProduct * this->quantity;
	}

	std::string printInfo()
	{
		std::ostringstream info;
		info << this->name << " " << this->totalPrice << '\n';

		return info.str();
	}
};

bool sortByName(City &first, City &secong)
{
	return first.name < secong.name;
}

int main()
{
	size_t howManyCities = 0;
	std::cin >> howManyCities;

	std::vector<City> cities;
	bool haveCity = false;

	for (size_t i = 0; i < howManyCities; i++)
	{
		std::string name;
		double productPrice = 0;
		size_t qty = 0;
		std::cin >> name >> productPrice >> qty;
		size_t cityInd = 0;

		if (!haveCity)
		{
			cities.push_back(City(name, productPrice, qty));
			haveCity = true;
		}
		else
		{
			bool cityExist = false;
			for (size_t a = 0; a < cities.size(); a++)
			{
				if (cities[a].name == name)
				{
					cityExist = true;
					cityInd = a;
				}
			}
			if (!cityExist)
			{
				cities.push_back(City(name, productPrice, qty));
			}
			else
			{
				cities[cityInd].totalPrice += (productPrice * qty);
				i--;
			}
		}
	}

	std::sort(cities.begin(), cities.end(), sortByName);
	for (size_t i = 0; i < cities.size(); i++)
	{
		std::cout << cities[i].printInfo();
	}

	int a;
	std::cin >> a;
	return 0;
}
