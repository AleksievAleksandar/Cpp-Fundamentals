#include <iostream>
#include <sstream>
#include <vector>

class Car
{
public:
	std::string brand;
	int year = 2000;
	double price = 1000.0;

	Car(std::string brand, int year, double price) :
		brand(brand),
		year(year),
		price(price)
	{
		if (year < 1950 || year > 2019)
		{
			this->year = 2000;
		}
		if (price <= 0)
		{
			this->price = 1000;
		}
	}

	std::string printInfo()
	{
		std::ostringstream info;
		info << "Make : " << brand << std::endl;
		info << "Year : " << year << std::endl;
		info << "Price : " << price << std::endl;
		return info.str();
	}

};

class AutoHouse
{
public:
	double capital;
	double overchargeTax;
	std::vector<Car> cars;

public:
	std::string showAllCars()
	{
		std::ostringstream allCarsInfo;
		for (size_t i = 0; i < cars.size(); i++)
		{
			allCarsInfo << cars[i].printInfo();
		}
		return allCarsInfo.str();
	}

	void buyCar(std::string brand, int year, double price)
	{
		if (capital >= price)
		{
			cars.push_back(Car(brand, year, price));
			this->capital -= price;
		}
	}

	AutoHouse(double capital, double overchargeTax) :
		capital(capital),
		overchargeTax(overchargeTax)
	{
		if (capital <= 0)
		{
			this->capital = 10000;
		}
		if (overchargeTax <= 0)
		{
			this->overchargeTax = 500;
		}
	}

	std::string sellAllCars()
	{
		std::ostringstream info;
		info << "Capital before sell : " << this->capital << std::endl;;
		for (size_t i = 0; i < cars.size(); i++)
		{
			capital += cars[i].price + this->overchargeTax;
		}
		info << "Capital after sell : " << this->capital << std::endl;
		cars.clear();

		return info.str();
	}
};

void menu()
{
	int menuChoise;
	bool haveCars = false;
	bool showAll = false;
	bool sellAll = false;
	size_t carsCnt = 0;

	double capital;
	double overchargeTax;

	std::cin >> capital >> overchargeTax;
	AutoHouse autoHouse(capital, overchargeTax);

	std::cin >> menuChoise;

	while (menuChoise != 0)
	{
		if (menuChoise == 1)
		{
			showAll = true;
		}
		if (menuChoise == 2)
		{
			sellAll = true;
		}
		if (menuChoise == 3)
		{
			haveCars = true;
			carsCnt++;
		}
		std::cin >> menuChoise;
	}

	while (carsCnt != 0)
	{
		std::string brand;
		int year = 0;
		double price = 0.0;

		std::cin >> brand >> year >> price;
		autoHouse.buyCar(brand, year, price);
		carsCnt--;
	}

	if (haveCars)
	{
		if (showAll && sellAll == false)
		{
			std::cout << autoHouse.showAllCars();
		}
		if (sellAll)
		{
			std::cout << autoHouse.sellAllCars();
		}
	}

}

int main()
{

	menu();

	//int a;
	//std::cin >> a;
	return 0;
}
