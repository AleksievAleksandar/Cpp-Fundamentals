#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Ranges
{
public:
	int first;
	int second;
};

bool sortRange(const Ranges& a, const Ranges& b)
{
	return a.first < b.first;
}

bool founded = false;

bool binary(const std::vector<Ranges>& a, size_t beginInd, size_t endInd, int number)
{
	
	int temp = beginInd + (endInd - beginInd) / 2;

	if (temp < 0)
	{
		return false;
	}
	if (temp >= endInd)
	{
		return false;
	}

	if (number >= a[temp].first && number <= a[temp].second)
	{
		founded = true;
		return founded;
	}

	if (number < a[temp].second)
	{
		binary(a, beginInd, (beginInd + endInd) / 2, number);
	}
	if (number > a[temp].second)
	{
		binary(a, (beginInd + endInd + 1) / 2, endInd, number);
	}
	return founded;
}

int main()
{
	std::vector<Ranges> ranges;
	std::stringstream consoleStream;
	std::string inputStr;

	std::ostream::sync_with_stdio(false);
	std::istream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::getline(std::cin, inputStr);
	consoleStream << inputStr;

	while (inputStr != ".")
	{
		int number;
		bool getFirst = true;
		Ranges temp;
		while (!consoleStream.eof())
		{
			consoleStream >> number;
			if (getFirst == true)
			{
				temp.first = number;
				getFirst = false;
			}
			else
			{
				temp.second = number;
			}
		}

		ranges.push_back(temp);
		consoleStream.clear();
		std::getline(std::cin, inputStr);
		consoleStream << inputStr;
	}

	std::vector<int> numberToComp;
	std::getline(std::cin, inputStr);
	while (inputStr != ".")
	{
		int a;
		a = std::stoi(inputStr);
		numberToComp.push_back(a);
		std::getline(std::cin, inputStr);
	}

	std::sort(ranges.begin(), ranges.end(), sortRange);

	bool success = false;

	for (size_t i = 0; i < numberToComp.size(); i++)
	{
		founded = false;
		success = binary(ranges, 0, ranges.size(), numberToComp[i]);
		if (success)
		{
			std::cout << "in\n";
		}
		else
		{
			std::cout << "out\n";
		}
	}

	return 0;
}
