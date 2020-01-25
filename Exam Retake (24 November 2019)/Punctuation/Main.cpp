#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);

	std::map<int, int> answers;

	std::size_t symbolCnt = 0;

	int symbol[100];
	int sentences[100];
	bool visited[100];

	for (size_t i = 0; i < sentence.size(); i++)
	{
		visited[i] = false;
	}

	size_t temp = 0;
	for (size_t i = 0; i < sentence.size(); i++)
	{
		if (ispunct(sentence[i]) && sentence[i] != 124)
		{
			symbolCnt++;
		}
		if (sentence[i] == 124)
		{
			symbol[temp + 1] = symbolCnt;
			temp++;
			symbolCnt = 0;
		}
	}

	for (size_t i = 1; i <= temp; i++)
	{
		size_t localCnt = 1;
		for (size_t a = i + 1; a <= temp; a++)
		{
			if (symbol[i] == symbol[a] && visited[i] == false)
			{
				visited[a] = true;
				localCnt++;
			}
		}
		if (symbol[i] > 0 && visited[i] == false)
		{
			answers[symbol[i]] = localCnt;
		}

	}

	std::map<int, int>::iterator itr;
	for (itr = answers.begin(); itr != answers.end(); ++itr)
	{
		std::cout << itr->first << " symbol sentences: " << itr->second << std::endl;

	}

	/*for (auto const &i:answers)
	{
		std::cout << i.first << " -> " << i.second << std::endl;
	}*/

	int a;
	std::cin >> a;
	return 0;
}
