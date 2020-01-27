#include <iostream>
#include <sstream>

class DiffTool
{
private:
	std::string firtsStr;
	std::string secondStr;
	size_t diffrences = 0;
	char diffStrTemp[150]{};
	std::string diffStr;

public:
	std::string getStrings(std::string const &a, std::string const &b, size_t const &sizeOfStrings)
	{
		this->firtsStr = a;
		this->secondStr = b;

		char temp[150];

		for (size_t i = 0; i < sizeOfStrings; i++)
		{
			if (this->firtsStr[i] == this->secondStr[i])
			{
				this->diffStrTemp[i] = this->firtsStr[i];
			}
			else
			{
				if ((firtsStr[i] > 64 && firtsStr[i] < 91 || firtsStr[i] > 96 && firtsStr[i] < 123) &&
					(secondStr[i] > 64 && secondStr[i] < 91 || secondStr[i] > 96 && secondStr[i] < 123))
				{
					if (this->firtsStr[i] + 32 == this->secondStr[i])
					{
						this->diffStrTemp[i] = this->firtsStr[i];
					}
					else if (this->firtsStr[i] - 32 == this->secondStr[i])
					{
						this->diffStrTemp[i] = this->secondStr[i];
					}
					else
					{
						this->diffStrTemp[i] = '!';
						diffrences++;
					}
				}
				else
				{
					this->diffStrTemp[i] = '!';
					diffrences++;
				}
			}
		}

		diffStrTemp[sizeOfStrings] = '\0';
		this->diffStr = this->diffStrTemp;

		std::ostringstream info;
		info << diffStr << "\n";
		info << diffrences;

		return info.str();
	}

};

int main()
{
	size_t lenght = 0;

	std::string one;
	std::string two;

	std::cin >> lenght >> one >> two;

	DiffTool diff;
	std::cout << diff.getStrings(one, two, lenght);

	int a;
	std::cin >> a;
	return 0;
}
