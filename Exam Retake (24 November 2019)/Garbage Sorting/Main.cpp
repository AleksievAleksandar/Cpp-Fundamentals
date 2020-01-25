#include <iostream>
#include <string>
#include <map>
#include <deque>

int main()
{
	std::string commandsStd;
	int commands = 0;

	std::string glass = "glass";
	std::string metal = "metal";
	std::string plastic = "plastic";

	std::string front = "front";
	std::string back = "back";

	std::getline(std::cin, commandsStd);
	commands = std::stoi(commandsStd);

	std::map<std::string, std::deque<int>> materialsMap;
	
	size_t cnt = 1;

	while (commands != 0)
	{
		std::string tempStr;
		std::getline(std::cin, tempStr);
		if (tempStr.find(glass) != std::string::npos)
		{
			if (tempStr.find(front) != std::string::npos)
			{
				materialsMap["glass"].push_front(cnt);
				cnt++;
			}
			else
			{
				materialsMap["glass"].push_back(cnt);
				cnt++;
			}
		}
		
		if (tempStr.find(metal) != std::string::npos)
		{
			if (tempStr.find(front) != std::string::npos)
			{
				materialsMap["metal"].push_front(cnt);
				cnt++;
			}
			else
			{
				materialsMap["metal"].push_back(cnt);
				cnt++;
			}
		}

		if (tempStr.find(plastic) != std::string::npos)
		{
			if (tempStr.find(front) != std::string::npos)
			{
				materialsMap["plastic"].push_front(cnt);
				cnt++;
			}
			else
			{
				materialsMap["plastic"].push_back(cnt);
				cnt++;
			}
		}
		commands--;
	}

	std::map<std::string, std::deque<int>>::iterator i;
	std::deque<int>::iterator a;

	for (i = materialsMap.begin(); i != materialsMap.end(); ++i)
	{
		std::cout << i->first << " - ";
		for (a = i->second.begin(); a != i->second.end(); ++a)
		{
			std::cout << *a << " ";
		}
		std::cout << std::endl;
	}

	//int aa;
	//std::cin >> aa;
	return 0;
}
