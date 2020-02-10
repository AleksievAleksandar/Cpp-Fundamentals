#include <iostream>
#include <sstream>
#include <vector>

class Person
{
public:
	std::string name;
	std::string profession;
	std::vector<Person> friends;
};

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

	
	std::ostringstream info;
	for (size_t i = 0; i < lookUp.size(); i++)
	{
		bool find = false;
		bool findProfession = false;
		for (size_t a = 0; a < persons.size(); a++)
		{
			if (lookUp[i] == persons[a].name)
			{
				for (size_t j = 0; j < persons.size(); j++)
				{
					find = false;
					findProfession = false;
					if (persons[a].profession == persons[j].profession && a != j)
					{
						findProfession = true;
						for (size_t k = 0; k < persons[j].friends.size(); k++)
						{
							if (persons[j].friends[k].name == persons[a].name)
							{
								find = true;
								break;
							}
						}
						if (!find)
						{
							info << persons[j].name << " ";
							find = false;
						}
					}
				}
				if (!findProfession)
				{
					info << "-\n";					
				}
				else
				{
					info << "\n";
				}
				
				break;
			}
		}
	}

	std::cout << info.str();
	int a;
	std::cin >> a;
	return 0;
}
