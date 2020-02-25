#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

void setTableDecr(std::string &s, std::map<char, char> &m)
{
	char startAlpha = 97;
	for (size_t i = 0; i < s.size(); i++)
	{
		m[s[i]] = startAlpha++;
	}
}

int main()
{
	std::string userInputStr;
	std::getline(std::cin, userInputStr);

	std::string targetWord = userInputStr;

	std::vector<std::string> lines;
	std::getline(std::cin, userInputStr);
	while (userInputStr != "[encryptions]")
	{
		lines.push_back(userInputStr);
		std::getline(std::cin, userInputStr);
	}


	std::vector<std::string> refLines;
	refLines = lines;

	std::getline(std::cin, userInputStr);
	std::map<char, char> encr;
	bool finded = false;
	std::vector<std::string> allResults;
	std::vector<std::vector<std::string>> finalResult;;
	size_t cntDubl = 0;
	size_t max = 0;
	while (userInputStr != "[end]")
	{
		setTableDecr(userInputStr, encr);

		lines = refLines;
		std::string temp;
		cntDubl = 0;
		finded = false;
		for (size_t i = 0; i < lines.size(); i++)
		{
			temp = "";
			for (size_t a = 0; a < targetWord.size(); a++)
			{
				temp += lines[i][a];
			}
			if (temp != targetWord)
			{
				for (size_t c = 0; c < temp.size(); c++)
				{
					char isNumber = temp[c];
					if (temp[c] != 32 && !isdigit(isNumber))
					{
						temp[c] = encr[temp[c]];
					}
				}
				if (temp == targetWord)
				{
					finded = true;
				}

				if (finded)
				{
					finded = false;

					for (size_t k = 0; k < lines[i].size(); k++)
					{
						char isNumber = lines[i][k];
						if (lines[i][k] != 32 && !isdigit(isNumber))
						{
							lines[i][k] = encr[lines[i][k]];
						}
					}
					allResults.push_back(lines[i]);
					cntDubl++;
				}
			}
			lines = refLines;
		}
		if (cntDubl > max)
		{
			max = cntDubl;
			cntDubl = 0;
			finalResult.clear();
			finalResult.push_back(allResults);
			allResults.clear();
			lines = refLines;
		}
		encr.clear();
		std::getline(std::cin, userInputStr);
	}

	for (auto i : finalResult)
	{
		for (auto a : i)
		{
			std::cout << a << "\n";
		}
	}

	int a;
	std::cin >> a;
	return 0;
}
