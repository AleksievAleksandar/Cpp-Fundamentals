#include <iostream>
#include <sstream>
#include <map>


class Gameplay
{
public:
	Gameplay() = default;
	std::string info()
	{
		std::ostringstream info;

		for (auto i : this->players)
		{
			info << i.first << " " << i.second << "\n";
		}

		return info.str();
	}

public:
	std::map<std::string, int> players;
};

Gameplay getUserInput()
{
	Gameplay gameplay;

	std::string line;
	std::getline(std::cin, line);

	std::istringstream iss(line);
	std::string name;
	int wins;
	int loses;
	iss >> name >> wins >> loses;
	while (name != "End")
	{
		if (gameplay.players.count(name) > 0)
		{
			std::map<std::string, int>::iterator itr;
			itr = gameplay.players.find(name);

			itr->second += (wins - loses);
		}
		else
		{
			gameplay.players[name] = wins - loses;
		}
		
		line.clear();
		name.clear();
		wins = 0;
		loses = 0;
		iss.clear();
		std::getline(std::cin, line);
		iss.str(line);
		iss >> name >> wins >> loses;
	}

	return gameplay;
}

int main()
{
	Gameplay gamers;
	gamers = getUserInput();

	std::cout << gamers.info();

	return 0;
}
