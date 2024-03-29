#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::stringstream getUserRawInput()
{
	std::stringstream rawData;
	std::string line;

	while (std::getline(std::cin, line) && line != "###")
	{
		rawData << line << " ";
	}

	return rawData;
}

std::vector<std::string> format(std::stringstream& rawData, const int textWidth)
{
	std::vector<std::string> result;

	std::string word;
	std::string line;
	const size_t emptySpace = 1;

	while (rawData >> word)
	{
		if (word.size() >= textWidth)
		{
			//if line container is not empty we must take his content
			//and after that we must set it to empty
			if (!line.empty())
			{
				result.push_back(line);
				line.clear();
			}
			result.push_back(word);
		}
		else
		{
			if (line.size() + word.size() <= textWidth)
			{
				line += word;

				if (line.size() + emptySpace >= textWidth)
				{
					result.push_back(line);
					line.clear();
				}
				else
				{
					line += " ";
				}
			}
			else
			{
				result.push_back(line);
				line.clear();
				line += word;
				line += " ";
			}
		}
	}

	//if the container still has contents we must take it
	if (!line.empty())
	{
		result.push_back(line);
	}

	return result;
}

int main()
{
	std::stringstream rawData;
	rawData = getUserRawInput();

	int width = 0;
	std::cin >> width;

	std::vector<std::string> formatedText;
	formatedText = format(rawData, width);

	for (size_t i = 0; i < formatedText.size(); i++)
	{
		std::cout << formatedText[i] << std::endl;
	}

	return 0;
}
