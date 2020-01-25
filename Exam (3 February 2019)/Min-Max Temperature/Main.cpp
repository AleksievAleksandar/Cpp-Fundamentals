#include <iostream>
#include <map>
#include <sstream>

int main()
{
	std::string townNumberStr;
	int townNumber = 0;
	std::map<std::string, std::pair<double, double>> townTemps;

	std::getline(std::cin, townNumberStr);
	townNumber = std::stoi(townNumberStr);
	size_t townCnt = 0;

	while (townCnt != townNumber)
	{
		std::string currentTownStr;
		std::getline(std::cin, currentTownStr);

		if (!townTemps.count(currentTownStr))
		{
			townCnt++;
			townTemps[currentTownStr].first = 1000.0;
			townTemps[currentTownStr].second = -1000.0;
		}

		std::string tempOneStr;
		double tempOne = 0.0;
		std::string tempTwoStr;
		double tempTwo = 0.0;
		std::getline(std::cin, tempOneStr);
		std::getline(std::cin, tempTwoStr);
		tempOne = std::stod(tempOneStr);
		tempTwo = std::stod(tempTwoStr);

		//townTemps[currentTownStr];

		if (townTemps[currentTownStr].first > tempOne)
		{
			townTemps[currentTownStr].first = tempOne;
		}
		if (townTemps[currentTownStr].second < tempTwo)
		{
			townTemps[currentTownStr].second = tempTwo;
		}

	}

	for (auto i : townTemps)
	{
		std::cout << i.first << " " << i.second.first << " " << i.second.second << std::endl;
	}

	int a;
	std::cin >> a;
	return 0;
}
