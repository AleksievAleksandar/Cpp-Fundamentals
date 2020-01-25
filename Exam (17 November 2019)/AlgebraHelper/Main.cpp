#include <iostream>
#include <map>
#include <sstream>
#include <functional>

int main()
{
	std::string tasksStr;
	int tasks = 0;
	std::getline(std::cin, tasksStr);
	tasks = std::stoi(tasksStr);

	std::multimap<int, std::string, std::greater<int>> result;
	std::multimap<int, std::string>::iterator itr;

	std::stringstream getTasks;
	for (size_t i = 0; i < tasks; i++)
	{
		std::getline(std::cin, tasksStr);
		getTasks << tasksStr;
		std::string operationType;
		std::string number;

		int left = 0;
		bool leftInt = true;
		int right = 0;
		bool rightInt = true;

		while (!getTasks.eof())
		{
			getTasks >> number;

			if (isdigit(number[0]))
			{
				if (leftInt)
				{
					leftInt = false;
					left = std::stoi(number);
				}
				if (rightInt)
				{
					right = std::stoi(number);
				}
			}
			else
			{
				operationType = number;
			}
		}
		if (operationType == "+")
		{
			result.insert({ left + right, tasksStr });
		}
		if (operationType == "-")
		{
			result.insert({ left - right, tasksStr });
		}
		if (operationType == "*")
		{
			result.insert({ left * right, tasksStr });
		}
		if (operationType == "/")
		{
			result.insert({ left / right, tasksStr });
		}
		if (operationType == "%")
		{
			result.insert({ left % right, tasksStr });
		}
		getTasks.clear();
	}

	for (itr = result.begin(); itr != result.end(); ++itr)
	{
		std::cout << itr->second << std::endl;
	}

	//int a;
	//std::cin >> a;
	return 0;
}
