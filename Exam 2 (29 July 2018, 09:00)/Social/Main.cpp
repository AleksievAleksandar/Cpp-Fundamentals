#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Person
{
public:
	std::string name;
	std::string profession;
	std::vector<Person> friends;
};

bool operator == (const Person &a, const Person &b)
{
	return a.name == b.name;
}


int main()
{
	std::string userInputStr;
	std::stringstream getNameStream;

	std::vector<Person> persons;
	std::vector<std::string> lookUp;

	std::getline(std::cin, userInputStr);
	getNameStream << userInputStr;

	//get names and professions
	while (userInputStr != "---")
	{
		std::string temp;
		bool getName = false;
		Person tempPerson;
		while (!getNameStream.eof())
		{
			getNameStream >> temp;
			if (!getName)
			{
				getName = true;
				tempPerson.name = temp;
			}
			else
			{
				tempPerson.profession = temp;
			}
		}
		persons.push_back(tempPerson);
		getNameStream.clear();

		std::getline(std::cin, userInputStr);
		getNameStream << userInputStr;
	}

	//get friendships relations
	getNameStream.str("");
	getNameStream.clear();
	userInputStr.clear();
	std::getline(std::cin, userInputStr);
	getNameStream << userInputStr;

	while (userInputStr != "---")
	{
		std::string nameOne;
		std::string nameTwo;
		bool getFirstName = false;
		std::pair<std::string, std::string> tempFriends;
		while (!getNameStream.eof())
		{
			if (!getFirstName)
			{
				getFirstName = true;
				getNameStream >> nameOne;
			}
			else
			{
				getNameStream >> nameTwo;
			}
		}

		for (size_t i = 0; i < persons.size(); i++)
		{
			if (persons[i].name == nameOne)
			{
				for (size_t a = 0; a < persons.size(); a++)
				{
					if (persons[a].name == nameTwo)
					{
						persons[i].friends.push_back(persons[a]);
						persons[a].friends.push_back(persons[i]);
					}
				}
			}
		}
		getNameStream.clear();

		std::getline(std::cin, userInputStr);
		getNameStream << userInputStr;
	}

	//get names to search
	getNameStream.str("");
	getNameStream.clear();
	userInputStr.clear();
	std::getline(std::cin, userInputStr);

	while (userInputStr != "---")
	{
		lookUp.push_back(userInputStr);
		std::getline(std::cin, userInputStr);
	}

	
	for (size_t i = 0; i < lookUp.size(); i++)
	{
		std::string prof;
		std::vector<Person> queue;
		std::vector<Person> visitedTemp;
		for (size_t a = 0; a < persons.size(); a++)
		{
			if (lookUp[i] == persons[a].name)
			{
				prof = persons[a].profession;
				visitedTemp.push_back(persons[a]);
				for (size_t c = 0; c < persons[a].friends.size(); c++)
				{
					queue.push_back(persons[a].friends[c]);
					visitedTemp.push_back(persons[a].friends[c]);
				}
				break;
			}
		}

		//already take the friends of the first person
		//start iteration of them

		std::vector<Person> futureFriends;

		for (size_t j = 0; j < queue.size(); j++)
		{
			for (size_t k = 0; k < persons.size(); k++)
			{
				if (queue[j].name == persons[k].name)
				{
					for (size_t v = 0; v < persons[k].friends.size(); v++)
					{
						if (!std::count(visitedTemp.begin(), visitedTemp.end(), persons[k].friends[v]))
						{
							futureFriends.push_back(persons[k].friends[v]);
							visitedTemp.push_back(persons[k].friends[v]);
							queue.push_back(persons[k].friends[v]);
						}
					}
					break; //new
				}
			}
		}

		bool findTargetProfession = false;
		std::vector<std::string> nameToPrint;
		for (size_t p = 0; p < futureFriends.size(); p++)
		{
			if (prof == futureFriends[p].profession)
			{
				findTargetProfession = true;
				nameToPrint.push_back(futureFriends[p].name);
			}
		}	
		if (!findTargetProfession)
		{
			std::cout << "-\n";
		}
		else
		{
			if (findTargetProfession)
			{
				std::sort(nameToPrint.begin(), nameToPrint.end());
				for (size_t x = 0; x < nameToPrint.size(); x++)
				{
					std::cout << nameToPrint[x] << " ";
				}
				std::cout << "\n";
			}			
		}
	}

	int a;
	std::cin >> a;
	return 0;
}
