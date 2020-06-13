#include <iostream>
#include <sstream>
#include <vector>

class Coffee
{
private:
	std::string name;
	double price;
	double rating;

public:
	Coffee(std::string name, double price, double rating):
		name(name), price(price), rating(rating)
	{

	}
	std::string getName()
	{
		return this->name;
	}
	double getRating()
	{
		return this->rating;
	}
	double getPrice()
	{
		return this->price;
	}
	void changePrice(double newPrice)
	{
		this->price = newPrice;
	}
};

std::vector<Coffee> getUserInput()
{
	int howManyDrinks;
	std::cin >> howManyDrinks;

	std::vector<Coffee> drinks;

	size_t cntDrinks = 0;

	while (cntDrinks != howManyDrinks)
	{
		std::cin.ignore();
		std::string nameDrink;
		double priceDrink;
		double ratingDrink;

		std::getline(std::cin, nameDrink);
		std::cin >> priceDrink >> ratingDrink;
		Coffee coffe(nameDrink, priceDrink, ratingDrink);

		drinks.push_back(coffe);

		cntDrinks++;
	}
	return drinks;
}

void deleteDrink(std::vector<Coffee>& menu, int indx)
{
	menu.erase(menu.begin() + indx);
}

void changePrice(std::vector<Coffee> &menu)
{
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].getRating() < 4)
		{
			deleteDrink(menu, i);
			i--;
		}
	}

	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].getRating() >= 4 && menu[i].getRating() <= 5.99)
		{
			double newPrice = menu[i].getPrice();
			newPrice -= newPrice * 0.1;
			menu[i].changePrice(newPrice);
		}
	}
}

int main()
{
	std::vector<Coffee> menu;
	menu = getUserInput();
	changePrice(menu);
	
	if (menu.empty())
	{
		std::cout << "The menu is empty\n";
	}
	else
	{
		for (size_t i = 0; i < menu.size(); i++)
		{
			std::cout << menu[i].getName() << " " << menu[i].getPrice() << "\n";
		}
	}

	return 0;
}
