#include <iostream>
#include <sstream>
#include "TimeCalculation.h"

void getUserInput(std::string &inputStr)
{
	std::getline(std::cin, inputStr);
}

int main()
{
	std::string userInputStrBus;
	std::string userInputStrTrain;

	getUserInput(userInputStrBus);
	getUserInput(userInputStrTrain);

	TimeCalculation cal;
	std::cout << cal.getTimes(userInputStrBus, userInputStrTrain);

	return 0;
}
