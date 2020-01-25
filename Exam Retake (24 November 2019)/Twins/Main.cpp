#include <iostream>
#include <sstream>
#include <vector>

class Twins
{
public:
	std::string name;
	std::vector<std::string> clients;
	std::vector<int> minutes;

	int totalMinuts = 0;

	int getTotalMinutes()
	{
		int temp = 0;
		for (size_t i = 0; i < minutes.size(); i++)
		{
			temp += minutes[i];
		}
		totalMinuts = temp;
		return temp;
	}

	Twins(std::string name) :
		name(name)
	{

	}
};

int main()
{
	std::string getNumberStr;
	int getNumber = 0;
	int workMinutes = 0;

	Twins Pepi("Pepi");
	Twins Mimi("Mimi");

	std::getline(std::cin, getNumberStr);
	getNumber = std::stoi(getNumberStr);

	std::string userInput;
	std::stringstream info;

	for (size_t i = 0; i <= getNumber; i++)
	{
		std::getline(std::cin, userInput);
		info << userInput;
		std::string tempStr = "";
		std::string getSecondName = "";
		int tempMinutes = 0;

		while (!info.eof())
		{
			//if (!isdigit(tempStr[0]))
			//{
			info >> tempStr;
			if (!isdigit(tempStr[0]))
			{
				getSecondName = tempStr;
			}
			else
			{
				tempMinutes = std::stoi(tempStr);
			}
			//}		

		}

		if (userInput[0] == 'P')
		{
			Pepi.clients.push_back(getSecondName);
			Pepi.minutes.push_back(tempMinutes);
			info.clear();
		}
		if (userInput[0] == 'M')
		{
			Mimi.clients.push_back(getSecondName);
			Mimi.minutes.push_back(tempMinutes);

			info.clear();
		}

		if (isdigit(userInput[0]))
		{
			workMinutes = std::stoi(userInput);
		}
	}

	std::ostringstream result;

	size_t cntPepi = 0;
	size_t cntMimi = 0;

	int sumPepi = Pepi.getTotalMinutes();
	int sumMimi = Mimi.getTotalMinutes();

	size_t tempCntPepi = 0;
	size_t tempCntMimi = 0;
	size_t count = 0;

	while (count < 20)
	{
		count++;
		if (cntPepi != Pepi.clients.size() && tempCntPepi < workMinutes)
		{
			if (Pepi.minutes[cntPepi] != 0 && cntPepi < Pepi.clients.size())
			{
				result << Pepi.name << " processing " << Pepi.clients[cntPepi] << std::endl;
				Pepi.minutes[cntPepi]--;
				tempCntPepi++;
			}
			else
			{
				cntPepi++;
				if (cntPepi < Pepi.clients.size())
				{
					result << Pepi.name << " processing " << Pepi.clients[cntPepi] << std::endl;
					Pepi.minutes[cntPepi]--;
					tempCntPepi++;
				}
			}
		}
		else
		{
			if (tempCntPepi < workMinutes)
			{
				result << Pepi.name << " Idle" << std::endl;
				sumPepi++;
				tempCntPepi++;
			}
		}


		if (cntMimi != Mimi.clients.size() && tempCntMimi < workMinutes)
		{

			if (Mimi.minutes[cntMimi] != 0 && cntMimi < Mimi.clients.size())
			{
				result << Mimi.name << " processing " << Mimi.clients[cntMimi] << std::endl;
				Mimi.minutes[cntMimi]--;
				tempCntMimi++;
			}
			else
			{
				cntMimi++;
				if (cntMimi < Mimi.clients.size())
				{
					result << Mimi.name << " processing " << Mimi.clients[cntMimi] << std::endl;
					Mimi.minutes[cntMimi]--;
					tempCntMimi++;
				}
			}
		}
		else
		{
			if (tempCntMimi < workMinutes)
			{
				result << Mimi.name << " Idle" << std::endl;
				sumMimi++;
				tempCntMimi++;
			}
		}

		if (tempCntPepi == workMinutes && tempCntMimi == workMinutes)
		{
			std::cout << result.str();
			break;
		}
	}

	int a;
	std::cin >> a;
	return 0;
}
