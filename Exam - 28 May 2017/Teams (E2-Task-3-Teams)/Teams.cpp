#include "Teams.h"

Teams::Teams(std::string &userInput)
{
	setFields(userInput);
}

void Teams::setFields(std::string& userInput)
{
	std::stringstream ss;
	ss << userInput;
	std::string temp;
	bool getTeam = false;
	while (ss >> temp)
	{
		if (!getTeam)
		{
			getTeam = true;
			this->teamName = temp;
		}
		else
		{
			if (!isdigit(temp[0]))
			{
				this->playersNames.push_back(temp);
			}
		}
	}
}
