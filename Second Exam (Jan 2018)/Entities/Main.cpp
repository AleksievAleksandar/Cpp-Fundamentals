#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

class Table
{
public:
	std::string nameCollum;
	std::vector<std::string> fields;
	std::map<std::string, int> fields_v2;
};


int main()
{
	std::string userInputStr;
	std::getline(std::cin, userInputStr);

	std::stringstream ss;
	ss << userInputStr;

	std::vector<Table> table;
	std::string getWord;
	while (ss >> getWord)
	{
		Table temp;
		temp.nameCollum = getWord;
		table.push_back(temp);
	}

	ss.clear();
	ss.str(std::string());
	getWord = "";
	userInputStr = "";

	size_t cnt = 0;
	std::getline(std::cin, userInputStr);
	
	while (userInputStr != "end")
	{
		ss << userInputStr;
		while (ss >> getWord && getWord != "end")
		{
			table[cnt].fields.push_back(getWord);
			table[cnt].fields_v2[getWord]++;
			cnt++;
		}
		std::getline(std::cin, userInputStr);
		cnt = 0;
		ss.clear();
		ss.str(std::string());
	}

	std::string searhField;
	std::getline(std::cin, searhField);

	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].nameCollum == searhField)
		{		
			std::vector<std::pair<std::string, int>> v(begin(table[i].fields_v2), end(table[i].fields_v2));
			std::sort(begin(v), end(v), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) { return a.second > b.second; });

			for (auto const &p : v)
			{
				std::cout << p.first << " " << p.second << std::endl;
				break;
			}
			break;
		}
	}
	int a;
	std::cin >> a;
	return 0;
}
