#include <iostream>
#include <vector>
#include <sstream>

#define lightSpeed 299792

class Planet
{
public:
	std::string name;
	std::string distanceFromSun;
	std::string diameter;
	std::string mass;
	int secondsOfLight;

	std::string getInfo()
	{
		std::ostringstream info;
		info << name << " " << distanceFromSun << " " << diameter << " " << mass << std::endl;
		info << secondsOfLight << std::endl;
		return info.str();
	}

	void calculateTheSeconds()
	{
		double temp = 0.0;
		temp = std::stod(distanceFromSun);
		secondsOfLight = temp / lightSpeed;
	}

	Planet(std::string name, std::string distanceFromSun, std::string diameter, std::string mass) :
		name(name),
		distanceFromSun(distanceFromSun),
		diameter(diameter),
		mass(mass)
	{
		calculateTheSeconds();
	}
};

std::string minMassOfPlanets(std::vector<Planet> &a, size_t numberPlanets)
{
	std::string str = a[0].mass;
	for (size_t i = 1; i < numberPlanets; i++)
	{
		if (str > a[i].mass)
		{
			str = a[i].mass;
		}
	}

	return str;
}

std::string maxDiaOfPlanets(std::vector<Planet> &a, size_t numberPlanets)
{
	std::string str = a[0].diameter;
	for (size_t i = 1; i < numberPlanets; i++)
	{
		if (str < a[i].diameter)
		{
			str = a[i].diameter;
		}
	}

	return str;
}

int main()
{
	size_t numberOfPlanets = 0;
	std::cin >> numberOfPlanets;

	std::vector<Planet> planets;
	for (size_t i = 0; i < numberOfPlanets; i++)
	{
		std::string name;
		std::string distance;
		std::string dia;
		std::string mass;

		std::cin >> name >> distance >> dia >> mass;

		planets.push_back(Planet(name, distance, dia, mass));

	}

	for (size_t i = 0; i < numberOfPlanets; i++)
	{
		std::cout << planets[i].getInfo();
	}

	std::cout << minMassOfPlanets(planets, numberOfPlanets) << std::endl;
	std::cout << maxDiaOfPlanets(planets, numberOfPlanets) << std::endl;

	int a;
	std::cin >> a;
	return 0;
}
