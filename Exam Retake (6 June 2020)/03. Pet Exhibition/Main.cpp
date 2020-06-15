#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class PetExhibition
{
public:
	class Pet
	{
	public:
		Pet(std::string name, int age, double score):
			name(name), age(age), score(score)
		{

		}

	public:
		std::string name;
		int age;
		double score;
	};

public:
	PetExhibition() = default;
	void petsEvaluation()
	{
		for (size_t i = 0; i < this->pets.size(); i++)
		{
			if (this->pets[i].age >= 12)
			{
				this->pets[i].score += 2.5;
			}
		}
		this->removeWeak();
	}

	std::string showWinners()
	{
		std::ostringstream info;
		std::sort(this->pets.begin(), this->pets.end(), [](Pet first, Pet second) {return first.score > second.score; });

		for (size_t i = 0; i < this->pets.size(); i++)
		{
			info << pets[i].name << " ";
		}
		return info.str();
	}

public:
	std::vector<Pet> pets;

private:
	void removeWeak()
	{
		for (size_t i = 0; i < this->pets.size(); i++)
		{
			if (this->pets[i].score < 4)
			{
				pets.erase(pets.begin() + i);
				i--;
			}
		}
	}
};

PetExhibition getUserInput()
{
	PetExhibition participant;

	int howManyPets;
	std::cin >> howManyPets;
	std::cin.ignore();

	size_t cntPet = 0;
	while (cntPet != howManyPets)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);

		std::string petName;
		int petAge;
		double petScore;

		iss >> petName >> petAge >> petScore;
		PetExhibition::Pet pet(petName, petAge, petScore);

		participant.pets.push_back(pet);
		cntPet++;
	}
	return participant;
}

int main()
{
	PetExhibition participant = getUserInput();
	participant.petsEvaluation();
	std::cout << participant.showWinners();

	return 0;
}
