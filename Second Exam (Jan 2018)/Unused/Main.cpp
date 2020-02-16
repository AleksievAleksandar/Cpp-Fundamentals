#include <iostream>
#include <string>

int main()
{
	std::string userInputStr;
	std::string result;

	std::cin >> userInputStr;

	for (char i = 97; i < 123; i++)
	{
		bool find = false;
		for (size_t a = 0; a < userInputStr.size(); a++)
		{
			if (userInputStr[a] == i)
			{
				find = true;
				break;
			}
		}
		if (!find)
		{
			std::cout << i;
		}
	}

	return 0;
}
