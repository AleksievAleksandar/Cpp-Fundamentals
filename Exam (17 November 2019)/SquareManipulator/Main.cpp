#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::vector<int>> matrix;
	int rows = 0;
	int cols = 0;
	std::cin >> rows >> cols;

	for (size_t i = 0; i < rows; i++)
	{
		std::vector<int> temp;
		for (size_t i = 0; i < cols; i++)
		{
			int value = 0;
			std::cin >> value;
			temp.push_back(value);
		}
		matrix.push_back(temp);
	}

	int squareSide = 0;
	int targetSUm = 0;
	std::cin >> squareSide >> targetSUm;

	std::vector<int> result;
	for (size_t r = 0; r <= rows - squareSide; r++)
	{		
		for (size_t c = 0; c <= cols - squareSide; c++) 
		{
			int localSum = 0;
			for (size_t i = r; i < squareSide + r; i++)
			{
 				for (size_t a = c; a < squareSide + c; a++)
				{
					localSum += matrix[i][a];
				}
			}
			if (localSum >= targetSUm)
			{
				int getResult = localSum / (squareSide * squareSide);
				result.push_back(getResult);
			}
			
		}
	}
	std::sort(result.begin(),result.end());
	for (auto i : result)
	{
		std::cout << i << " ";
	}

	//int a;
	//std::cin >> a;
	return 0;
}
