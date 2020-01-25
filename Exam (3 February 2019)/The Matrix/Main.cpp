#include <iostream>
#include <vector>

int main()
{
	size_t range = 0;
	std::cin >> range;

	std::vector<std::vector<int>> matrix;

	for (size_t i = 0; i < range; i++)
	{
		std::vector<int> temp;
		int number = 0;
		for (size_t a = 0; a < range; a++)
		{
			std::cin >> number;
			temp.push_back(number);
		}
		matrix.push_back(temp);
	}

	std::vector<int> numbers;
	size_t shrink = 1;
	
	for (int i = range - 1; i > range / 2; i--)
	{
		for (size_t a = shrink; a < range - shrink; a++)
		{
			numbers.push_back(matrix[i][a]);
		}
		shrink++;
	}

	int sumOfSimpleNums = 0;
	
	for (size_t i = 0; i < numbers.size(); i++)
	{
		bool isSimple = true;
		for (size_t a = 2; a < 10; a++)
		{
			if (numbers[i] == 1 || numbers[i] == 2)
			{
				break;
			}
			if (numbers[i] % a == 0 && numbers[i] != a )
			{
				isSimple = false;	
				break;
			}
		}
		if (isSimple)
		{
			sumOfSimpleNums += numbers[i];
		}
	}

	std::cout << sumOfSimpleNums;

	int a;
	std::cin >> a;
	return 0;
}
