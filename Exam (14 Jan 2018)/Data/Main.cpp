#include <iostream>
#include <vector>
#include <map>
#include <sstream>

class Table
{
public:
	std::map<std::string, std::string> fields;
};

void getUserInput(std::vector<Table> &table)
{
	std::string info;

	std::getline(std::cin, info);

	std::stringstream ss;
	
	while (info != "[queries]")
	{
		ss << info;
		std::string word;
		
		std::vector<std::string> words;
		while (ss >> word)
		{
			words.push_back(word);
		}

		Table temp;
		for (size_t i = 0; i < words.size(); i++)
		{
			size_t nextWord = i + 1;
			if (nextWord < words.size())
			{
				temp.fields[words[i]] = words[nextWord];
			}
			i++;
		}
		table.push_back(temp);
		std::getline(std::cin, info);
		ss.clear();
		ss.str(std::string(""));
	}
}

std::string getQueries(const std::string &lookFor, std::vector<Table>& table)
{
	std::string input;
	std::getline(std::cin, input);

	std::string wordOne;
	std::string wordTwo;

	std::ostringstream info;

	std::stringstream ss;
	while (input != "end")
	{
		ss << input;
		std::string word;
		bool getFirstWord = false;
		while (ss >> word)
		{
			if (!getFirstWord)
			{
				wordOne = word;
				getFirstWord = true;
			}
			else
			{
				wordTwo = word;
			}
		}

		std::string getInfo;
		bool findEntity = false;
		bool findTarget = false;
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].fields[lookFor] == wordOne)
			{
				findEntity = true;
				
				if (table[i].fields[wordTwo] != "")
				{
					getInfo += table[i].fields[wordTwo];
					getInfo += " ";		
					findTarget = true;
				}				
			}
		}
		if (!findEntity)
		{
			info << "[not found]\n";
		}
		else
		{
			if (findTarget)
			{
				info << getInfo << "\n";
			}
			else
			{
				info << "\n";
			}
		}

		std::getline(std::cin, input);
		ss.clear();
		ss.str(std::string(""));
	}
	return info.str();
}

int main()
{
	std::string lookFor;
	std::getline(std::cin, lookFor);

	std::vector<Table> tables;
	getUserInput(tables);

	std::cout << getQueries(lookFor, tables);

	int a = 0;
	return 0;
}
