#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Market
{
public:
	Market() = default;
	std::string getInfo()
	{
		this->calculateTotalPrice();
		std::ostringstream info;
		info << "The total sum is: " << this->total << " lv.\n";

		for (size_t i = 0; i < this->products.size(); i++)
		{
			info << this->products[i].name << " " << this->products[i].totalPrice << "\n";
		}

		return info.str();
	}
	void sortProducts()
	{
		std::sort(this->products.begin(), this->products.end(), 
			[&](const Market::Product &a, const Market::Product &b) 
			{return a.totalPrice > b.totalPrice; });
	}

public:
	class Product
	{
	public:
		Product(std::string name, double price, int quantity):
			name(name), price(price), quantity(quantity)
		{
			this->totalPrice = this->quantity * (double)this->price;
		}
	public:
		std::string name;
		double price;
		int quantity;
		double totalPrice;
	};

	std::vector<Product> products;
	double total;

private:
	void calculateTotalPrice()
	{
		this->total = 0;
		for (size_t i = 0; i < this->products.size(); i++)
		{
			this->total += this->products[i].totalPrice;
		}
	}
};

void getUserInput(Market &market)
{
	int howManyProducts;
	std::cin >> howManyProducts;
	size_t cntItems = 0;
	
	while (cntItems != howManyProducts)
	{
		std::string word;
		double pricePerProduct;
		int quantityPerProduct;

		std::cin >> word >> pricePerProduct >> quantityPerProduct;

		Market::Product currentProduct(word, pricePerProduct, quantityPerProduct);
		market.products.push_back(currentProduct);

		cntItems++;
	}
}

int main()
{
	Market market;

	getUserInput(market);
	market.sortProducts();

	std::cout << market.getInfo();

	return 0;
}
