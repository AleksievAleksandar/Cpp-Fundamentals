#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

bool sortCol(const std::vector<int> &first, const std::vector<int> & second)
{
	return first[0] < second[0];
}

int main()
{
	std::string separatorsStr;
	std::getline(std::cin, separatorsStr);
	std::vector<int> separators;
	std::stringstream ss;
	ss << separatorsStr;

	int temp = 0;
	while (ss >> temp)
	{
		separators.push_back(temp);
	}
	ss.clear();
	ss.str(std::string());
	temp = 0;

	std::string numbersStr;
	std::getline(std::cin, numbersStr);
	ss << numbersStr;
	std::vector<std::vector<int>> parts;

	std::vector<int> tempPart;
	bool findSeparator = false;
	while (ss >> temp)
	{
		findSeparator = false;
		for (size_t i = 0; i < separators.size(); i++)
		{
			if (separators[i] == temp)
			{
				findSeparator = true;
				break;
			}
		}
		if (findSeparator == false)
		{
			std::sort(tempPart.begin(), tempPart.end());
			tempPart.push_back(temp);
		}
		else
		{
			std::sort(tempPart.begin(), tempPart.end());
			parts.push_back(tempPart);
			tempPart.clear();
		}
	}
	if (findSeparator == false)
	{
		std::sort(tempPart.begin(), tempPart.end());
		parts.push_back(tempPart);
		tempPart.clear();
	}
	std::sort(parts.begin(), parts.end(), sortCol);

	temp = 0;
	std::string searchNumber;
	std::vector<int> search;
	std::getline(std::cin, searchNumber);
	temp = std::stoi(searchNumber);

	while (temp != 0)
	{
		search.push_back(temp);

		std::getline(std::cin, searchNumber);
		temp = std::stoi(searchNumber);
	}

	std::vector<std::vector<int>>::iterator itr = parts.begin();
	for (size_t i = 0; i < search.size(); i++)
	{
		size_t cnt = 0;
		for (std::vector<std::vector<int>>::iterator r = parts.begin(); r != parts.end(); r++)
		{
			if (std::binary_search(r->begin(), r->end(), search[i]))
			{
				cnt++;
			}
			int a = *(r->begin());
			if (*(r->begin()) > search[i])
			{
				break;
			}
		}
		std::cout << cnt << "\n";
	}

	return 0;
}
