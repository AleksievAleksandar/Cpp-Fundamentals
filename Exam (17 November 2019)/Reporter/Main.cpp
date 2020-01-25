#include <iostream>
#include <set>
#include <sstream>

int main()
{
	std::set<std::string> str;
	std::set<std::string>::iterator itr;

	std::stringstream infoStream;
	std::string temp;
	std::string output;
	int turns = 0;

	std::string getInputStr;
	std::getline(std::cin, getInputStr);
	turns = std::stoi(getInputStr);

	for (size_t i = 0; i < turns; i++)
	{
		std::getline(std::cin, getInputStr);
		infoStream << getInputStr;
		//infoStream << " ";
		//char previusDot = 57;

		while (!infoStream.eof())
		{
			infoStream >> temp;
			if (!str.count(temp))
			{

				output += temp + " ";
				//previusDot = temp[0];
				str.insert(temp);
				if (temp[0] == 46)
				{
					str.clear();
				}
			}
			//str.insert(temp);
		}
		infoStream.clear();
	}
	//output.resize(output.size() - 1);
	std::cout << output;

	//int a;
	//std::cin >> a;
	return 0;
}
