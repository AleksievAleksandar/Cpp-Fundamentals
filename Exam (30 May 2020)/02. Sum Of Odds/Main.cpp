#include <iostream>
#include <vector>

std::vector<std::vector<int>> createMatrix()
{
	std::vector<std::vector<int>> matrix;

	int matrixSize;
	std::cin >> matrixSize;
		
	for (size_t i = 0; i < matrixSize; i++)
	{
		std::vector<int> row;
		for (size_t a = 0; a < matrixSize; a++)
		{
			int temp;
			std::cin >> temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}
	return matrix;
}

int calculateOddOfMatrix(std::vector<std::vector<int>> matrix)
{
	int leftDiag = 0;
	int rightDiag = matrix.size() - 1;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		matrix[i][leftDiag++] = 0;
		matrix[i][rightDiag--] = 0;
	}

	int sum = 0;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t a = 0; a < matrix.size(); a++)
		{
			if (matrix[i][a] % 2 != 0)
			{
				sum += matrix[i][a];
			}
		}
	}
	return sum;
}

int main()
{
	std::vector<std::vector<int>> matrix;
	matrix = createMatrix();

	std::cout << "The sum is: " << calculateOddOfMatrix(matrix);

	return 0;
}
