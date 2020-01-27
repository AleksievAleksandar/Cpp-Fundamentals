#include <iostream>
#include <sstream>

const double dailyElectricalPriceKWHour = 0.13;
const double nightElectricalPriceKWHour = 0.07;
const size_t days = 30;
const double waterCost = 1.65;
const double gasCost = 0.09;

class Family
{
private:
	double water;
	double gas;
	const int moneyForChild = 40;
	double dailyElectricalEnergy;
	double rent;
	double nightElectricalEnergy;
	double motherSalary;
	double fatherSalary;
	double totalSalary;
	double priceWater;
	double priceGas;
	double priceElect;
	double allCost;
	double remainingSalary;
	double moneyForDay;

public:
	Family(double water, double gas, double dailyElectricalEnergy, double rent, double nightElectricalEnergy, double motherSalary, double fatherSalary):
		water(water), gas(gas), dailyElectricalEnergy(dailyElectricalEnergy), rent(rent), nightElectricalEnergy(nightElectricalEnergy), motherSalary(motherSalary), fatherSalary(fatherSalary)
	{
		this->priceWater = this->water * waterCost;
		this->priceGas = this->gas * gasCost;
		this->priceElect = this->dailyElectricalEnergy * dailyElectricalPriceKWHour + this->nightElectricalEnergy * nightElectricalPriceKWHour;
		this->totalSalary = this->fatherSalary + this->motherSalary;
		this->allCost = this->priceWater + this->priceGas + this->priceElect + this->moneyForChild + this->rent;
		this->remainingSalary = this->totalSalary - this->allCost;
		this->moneyForDay = this->remainingSalary / (double)days;
	}

	std::string printInfo()
	{
		std::ostringstream info;

		if (this->remainingSalary <= 0 || this->moneyForDay <= 0)
		{
			info << "Water : " << this->priceWater << "\n";
			info << "Gas : " << this->priceGas << "\n";
			info << "Energy : " << this->priceElect << "\n";
			info << "All costs : " << this->allCost << "\n";
			info << "Remaining Salary : " << this->remainingSalary << "\n";
			info << "You should find new job !\n";
			info << "Money for one day : " << this->moneyForDay << "\n";
		}
		else
		{
			info << "Water : " << this->priceWater << "\n";
			info << "Gas : " << this->priceGas << "\n";
			info << "Energy : " << this->priceElect << "\n";
			info << "All costs : " << this->allCost << "\n";
			info << "Remaining Salary : " << this->remainingSalary << "\n";			
			info << "Money for one day : " << this->moneyForDay << "\n";
		}
		return info.str();
	}

};

int main()
{
	double water;
	double gas;
	double dailyEner;
	double rent;
	double nightEner;
	double motherSal;
	double fatherSal;

	std::cin >> water >> gas >> dailyEner >> rent >> nightEner >> motherSal >> fatherSal;
	Family family(water, gas, dailyEner, rent, nightEner, motherSal, fatherSal);

	std::cout << family.printInfo();

	int a;
	std::cin >> a;
	return 0;
}
