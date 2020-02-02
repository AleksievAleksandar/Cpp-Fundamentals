#include <iostream>
#include <vector>

class Glitche
{
private:
	char findedSymbol = ' ';
	int getDown = 0;
	int getDownHalf = 0;
	int increase = 1;
	size_t maxSymb = 0;
	size_t getRight = 0;
	bool visited[120][120]{};
	

	void printMatrix(std::vector<std::vector<char>>& matrix)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t a = 0; a < matrix.size(); a++)
			{
				std::cout << matrix[i][a];
			}
			std::cout << std::endl;
		}
	}


public:
	void clearGlitches(std::vector<std::vector<char>>& matrix)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t a = 0; a < matrix.size(); a++)
			{
				if (matrix[i][a] != '.' && visited[i][a] != true)
				{
					findedSymbol = matrix[i][a];
					getDown = i;
					maxSymb = 0;
					size_t row = 0;
					size_t col = 0;
					while (matrix[getDown][a] == findedSymbol)
					{
						getDown++;
						maxSymb++;
						if (getDown >= matrix.size())
						{
							break;
						}
					}
					getDownHalf = maxSymb / 2;
					row = getDownHalf + i;
					col = a;
					visited[row][col] = true;

					if (maxSymb > 1)
					{
						//up to down to right increase
						getDown = i;
						int getRight = a + 1;
						for (size_t c = 0; c <= getDownHalf; c++)
						{
							for (size_t b = a; b < getRight; b++)
							{
								matrix[getDown][b] = '.';
							}
							getDown++;
							getRight++;
						}

						//up to down to left decrease
						getDown = i;
						getRight = a - 1;
						for (size_t c = 0; c <= getDownHalf; c++)
						{
							for (int b = a - 1; b > getRight; b--)
							{
								matrix[getDown][b] = '.';
							}
							getDown++;
							getRight--;							
						}
						//this is the end of the up first half of the Glitch

						//down to down to left increase
						getDown = getDownHalf + i + 1;
						getRight = getDownHalf + a;
						for (size_t c = 0; c < getDownHalf; c++)
						{
							for (size_t b = a; b < getRight; b++)
							{
								matrix[getDown][b] = '.';
							}
							getDown++;
							getRight--;
						}

						//down to down to left decrease
						getDown = getDownHalf + i + 1;
						getRight = a - getDownHalf;
						for (size_t c = 0; c < getDownHalf - 1; c++)
						{
							for (size_t b = a - 1; b > getRight; b--)
							{
								matrix[getDown][b] = '.';
							}
							getDown++;
							getRight++;
						}

						matrix[row][col] = findedSymbol;
						std::cout << std::endl;
						//printMatrix(matrix);
					}
				}
			}

		}
		printMatrix(matrix);
	}
};

int main()
{
	size_t matrixSize;
	std::cin >> matrixSize;

	std::vector<std::vector<char>> matrix;

	for (size_t i = 0; i < matrixSize; i++)
	{
		std::vector<char> temp;

		for (size_t a = 0; a < matrixSize; a++)
		{
			char symb;
			std::cin >> symb;
			temp.push_back(symb);
		}
		matrix.push_back(temp);
	}

	Glitche glitch;
	glitch.clearGlitches(matrix);

	//int a;
	//std::cin >> a;
	return 0;
}
