#include <iostream>
#include <sstream>


int main()
{
	std::string userInputStr;
	std::cin >> userInputStr;

	std::string findNumber;
	bool findNum = false;
	std::string result;
	size_t number = 0;
	for (size_t i = 0; i < userInputStr.size(); i++)
	{
		if (isdigit(userInputStr[i]))
		{
			findNumber += userInputStr[i];
			number = std::stoi(findNumber);
			findNum = true;
		}
		else
		{
			result += userInputStr[i];

			if (findNum)
			{
				for (size_t a = 0; a < number - 1; a++)
				{
					result += userInputStr[i];
				}
				findNum = false;
				findNumber = "";
			}
		}


	}

	std::cout << result;

	return 0;
}
