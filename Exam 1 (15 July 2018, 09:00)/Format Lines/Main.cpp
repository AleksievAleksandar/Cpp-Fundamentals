#include <iostream>
#include <sstream>

int main()
{
	std::string getUserInputStr;
	std::getline(std::cin, getUserInputStr);

	std::stringstream infoStream;
	
	while (getUserInputStr != "###")
	{
		infoStream << getUserInputStr << " ";
		std::getline(std::cin, getUserInputStr);
	}

	getUserInputStr.clear();
	std::getline(std::cin, getUserInputStr);
	size_t width = std::stoi(getUserInputStr);

	std::string word;
	size_t sizeWords = 0;
	std::ostringstream toPrint;
	while (!infoStream.eof())
	{
		infoStream >> word;
		sizeWords += word.size();

		if (sizeWords <= width)
		{
			toPrint << word;
		}
		else
		{
			toPrint << "\n";
		}
	}

	std::cout << toPrint.str();

	int a;
	std::cin >> a;
	return 0;
}
