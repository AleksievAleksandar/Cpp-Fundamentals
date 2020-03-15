#pragma once
#include <sstream>
#include <vector>

class Teams
{
public:
	std::string teamName;
	std::vector<std::string> playersNames;
	size_t howManyWins = 0;

public:
	Teams(std::string &userInput);
private:
	void setFields(std::string &userInput);
};
