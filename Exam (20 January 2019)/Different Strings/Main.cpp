#include <iostream>
#include <string>

int main()
{
	size_t lenght = 0;
	std::cin >> lenght;

	std::string firstStr;
	std::string secondStr;
	std::cin >> firstStr >> secondStr;

	size_t differences = 0;
	size_t sameCharacters = 0;
	int sumOfDigits = 0;
	char findedDiff[160];
	
	for (size_t i = 0; i < lenght; i++)
	{
		if (isalpha(firstStr[i]) && isalpha(secondStr[i]))
		{
			if (firstStr[i] == secondStr[i])
			{
				sameCharacters++;
				findedDiff[i] = firstStr[i];
			}
			else if (firstStr[i] + 32 == secondStr[i])
			{
				sameCharacters++;
				findedDiff[i] = firstStr[i];
			}
			else if (firstStr[i] - 32 == secondStr[i])
			{
				sameCharacters++;
				findedDiff[i] = secondStr[i];
			}
			else
			{
				differences++;
				findedDiff[i] = '#';
			}
		}
		else
		{
			if (firstStr[i] == secondStr[i])
			{
				sameCharacters++;
				findedDiff[i] = firstStr[i];
			}
			else
			{
				differences++;
				findedDiff[i] = '#';
			}

			if (isdigit(firstStr[i]))
			{
				char temp = firstStr[i];
				sumOfDigits += (int)temp - 48;
			}
			if (isdigit(secondStr[i]))
			{
				char temp = secondStr[i];
				sumOfDigits += (int)temp - 48;
			}
		}
	}
	findedDiff[lenght] = 0;
	std::string diff = findedDiff;

	std::cout << diff << std::endl;
	std::cout << differences << std::endl;
	std::cout << sameCharacters << std::endl;
	std::cout << sumOfDigits << std::endl;

	int a;
	std::cin >> a;
	return 0;
}
