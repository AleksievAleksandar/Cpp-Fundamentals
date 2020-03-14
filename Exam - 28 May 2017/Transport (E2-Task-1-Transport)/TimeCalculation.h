#pragma once

#include <sstream>
#include <vector>
#include <algorithm>

class TimeCalculation
{
public:
	std::string getTimes(std::string const &busTime, std::string const &trainTime);
private:
	std::vector<int> calculateMinutes(std::stringstream &ss);
	std::string getBestTime(std::vector<int> const &busTime, std::vector<int> const &trainTime);
};
