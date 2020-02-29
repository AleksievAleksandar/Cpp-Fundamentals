#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void readUserInput(int &distance, int &howManyNumbers, std::vector<int> &sequence, std::map<int, int> &incomes)
{
	int tempDistance;
	int tempNumbers;

	std::cin >> tempDistance >> tempNumbers;
	distance = tempDistance;
	howManyNumbers = tempNumbers;

	for (size_t i = 0; i < howManyNumbers; i++)
	{
		int temp;
		std::cin >> temp;
		sequence.push_back(temp);
		incomes[temp]++;
	}
	std::sort(sequence.begin(), sequence.end());
}

double calculateDistance(const int &distance, std::vector<int>& sequence, std::map<int, int>& incomes)
{
	std::vector<int> insideNumbers;
	size_t reachDist = 0;
	size_t left = 0;
	size_t righ = sequence.size() - 1;

	size_t leftIndx = incomes[sequence[left]];
	size_t righIndx = incomes[sequence[righ]];

	reachDist = incomes[sequence[left]] + incomes[sequence[righ]];

	if (distance > 0)
	{
		do
		{
			left++;
			reachDist += incomes[sequence[left]];
			leftIndx += incomes[sequence[left]];
			if (reachDist > distance)
			{
				break;
			}

			righ--;
			reachDist += incomes[sequence[righ]];
			righIndx += incomes[sequence[righ]];
			if (reachDist > distance)
			{
				break;
			}

			//reachDist += incomes[sequence[left]] + incomes[sequence[righ]];
			//leftIndx += incomes[sequence[left]];
			//righIndx += incomes[sequence[righ]];
		} while (reachDist < distance);
	}


	//leftIndx--;
	double result = 0;
	size_t numb = 0;
	righIndx += leftIndx;
	for (size_t i = leftIndx; i < righIndx; i++)
	{
		result += sequence[i];
		numb++;
	}
	return result / (double)numb;
}

int main()
{
	int distance;
	int howManyNumbers;
	std::vector<int> sequance;
	std::map<int, int> incomes;

	readUserInput(distance, howManyNumbers, sequance, incomes);

	std::cout << calculateDistance(distance, sequance, incomes);

	int a = 0;
	return 0;
}
