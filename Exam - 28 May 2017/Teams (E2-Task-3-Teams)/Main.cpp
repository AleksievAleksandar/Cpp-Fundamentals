#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "Teams.h"

std::string getUserInput()
{
	std::string temp;
	std::getline(std::cin, temp);
	return temp;
}

std::map<std::string, int> findWinners(std::vector<Teams> &teams, std::map<std::string, int> &win)
{
	std::map<std::string, int> players;

	for (auto i : win)
	{
		for (size_t a = 0; a < teams.size(); a++)
		{
			if (i.first == teams[a].teamName)
			{
				teams[a].howManyWins = i.second;
				
				for (size_t c = 0; c < teams[a].playersNames.size(); c++)
				{
					players[teams[a].playersNames[c]] += teams[a].howManyWins;
				}

				break;
			}
		}
	}

	for (size_t i = 0; i < teams.size(); i++)
	{
		for (size_t a = 0; a < teams[i].playersNames.size(); a++)
		{
			players[teams[i].playersNames[a]] += 0;
		}
	}

	return players;
}

std::string printResult(std::map<std::string, int> const& result)
{
	std::ostringstream info;
	for (auto i : result)
	{
		info << i.second << " ";
	}
	return info.str();
}

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::vector<Teams> teams;

	std::string teamsNumStr;
	int teamsNumb = 0;
	std::getline(std::cin, teamsNumStr);
	teamsNumb = std::stoi(teamsNumStr);

	for (size_t i = 0; i < teamsNumb; i++)
	{
		std::string str = getUserInput();
		teams.push_back(Teams(str));
	}

	std::getline(std::cin, teamsNumStr);
	teamsNumb = std::stoi(teamsNumStr);
	std::map<std::string, int> winnersMap;

	for (size_t i = 0; i < teamsNumb; i++)
	{
		std::string tempStr = getUserInput();
		winnersMap[tempStr]++;
	}

	std::map<std::string, int> finalResult;
	finalResult = findWinners(teams, winnersMap);
	
	std::cout << printResult(finalResult);

	return 0;
}
