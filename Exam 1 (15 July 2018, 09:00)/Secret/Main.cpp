#include <iostream>
#include <sstream>

int main()
{
	std::string getUserInputSrt;
	std::getline(std::cin, getUserInputSrt);

	int temp = 0;
	std::string number;
	for (size_t i = 0; i < getUserInputSrt.size(); i++)
	{
		if (isdigit(getUserInputSrt[i]))
		{
			number = getUserInputSrt[i];
			temp += std::stoi(number);
		}
	}

	if (temp > 64 && temp < 91 || temp > 96 && temp < 123)
	{
		char a = temp;
		std::cout << a;
	}
	else
	{
		std::cout << temp;
	}

	//int a;
	//std::cin >> a;
	return 0;
}
