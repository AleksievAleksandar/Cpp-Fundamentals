#include <iostream>
#include <string>

std::string compression(std::string& input)
{
	std::string comp = "";

	for (size_t i = 0; i < input.size(); i++)
	{
		size_t symbCnt = 1;
		char symb = input[i];
		while (symb == input[++i])
		{
			symbCnt++;
		}

		if (symbCnt > 2)
		{
			std::string getNum = std::to_string(symbCnt); 
			comp += getNum;
			comp += symb;
		}
		else
		{
			while (symbCnt > 0)
			{
				comp += symb;
				symbCnt--;
			}	
		}
		i--;
	}
	return comp;
}

void compressionUserInput(std::string &userInput)
{
	std::string temp;
	std::cin >> temp;

	userInput = compression(temp);
}



int main()
{
	std::string work;
	compressionUserInput(work);

	std::cout << work;

	return 0;
}
