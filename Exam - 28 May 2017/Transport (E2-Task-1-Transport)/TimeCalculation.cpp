#include "TimeCalculation.h"

std::string TimeCalculation::getTimes(std::string const& busTime, std::string const& trainTime)
{
	std::stringstream ss;
	ss << busTime;

	std::vector<int> busMinVec;
	busMinVec = calculateMinutes(ss);

	ss << trainTime;

	std::vector<int> trainTimeVec;
	trainTimeVec = calculateMinutes(ss);

	return getBestTime(busMinVec, trainTimeVec);
}

std::vector<int> TimeCalculation::calculateMinutes(std::stringstream &ss)
{
	std::vector<int> busMin;
	std::string temp;
	while (ss >> temp)
	{
		std::string hours;
		std::string minutes;
		for (size_t i = 0; i < 2; i++)
		{
			hours += temp[i];
		}
		for (size_t i = 2; i < 4; i++)
		{
			minutes += temp[i];
		}

		int min = std::stoi(hours) * 60;
		min += std::stoi(minutes);
		busMin.push_back(min);
	}
	ss.clear();
	ss.str("");
	return busMin;
}

std::string TimeCalculation::getBestTime(std::vector<int> const& busTime, std::vector<int> const& trainTime)
{
	std::vector<int> tempMin;

	for (size_t i = 0; i < busTime.size(); i++)
	{
		tempMin.push_back(std::abs(trainTime[0] - busTime[i]));
	}
	std::sort(tempMin.begin(), tempMin.end());

	return std::to_string(tempMin[0]);
}
