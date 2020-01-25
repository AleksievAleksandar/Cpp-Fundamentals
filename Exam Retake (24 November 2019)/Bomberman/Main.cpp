#include <iostream>
#include <sstream>
#include <vector>

class Bomberman
{
public:
	size_t bombPower = 0;
	size_t score = 0;
};

void getHowManyRowsAndCols(std::stringstream &getRowsCols, int &rows, int &cols)
{
	while (!getRowsCols.eof())
	{
		std::string temp;
		getRowsCols >> temp;
		if (rows == 0)
		{
			rows = std::stoi(temp);
		}
		else
		{
			cols = std::stoi(temp);
		}
	}
}


int main()
{
	std::string userInfoStr;
	int rows = 0;
	int cols = 0;
	std::stringstream getRowsCols;

	int commands = 0;

	std::getline(std::cin, userInfoStr);
	getRowsCols << userInfoStr;

	getHowManyRowsAndCols(getRowsCols, rows, cols);

	std::vector<std::vector<int>> battleField;

	//create battle field
	for (size_t i = 0; i < rows; i++)
	{
		std::vector<int> tempVector;
		std::getline(std::cin, userInfoStr);
		for (size_t a = 0; a < cols; a++)
		{
			int tempValue = 0;
			char tempChar = userInfoStr[a];
			tempValue = (int)tempChar - 48;
			tempVector.push_back(tempValue);
		}
		battleField.push_back(tempVector);
	}
	//*****

	std::getline(std::cin, userInfoStr);
	commands = std::stoi(userInfoStr);

	Bomberman man;

	int cnt = 0;
	while (cnt < commands)
	{
		std::getline(std::cin, userInfoStr);
		if (userInfoStr[0] == 'b')
		{
			size_t iTemp = (int)userInfoStr[5] - 48;
			size_t aTemp = (int)userInfoStr[7] - 48;

			if (man.bombPower == 0)
			{
				man.score = battleField[iTemp][aTemp];
				battleField[iTemp][aTemp] = 0;
				//print man.score
				std::cout << man.score << " points\n";
				man.score = 0;
			}
			else
			{
				man.score += battleField[iTemp][aTemp];
				battleField[iTemp][aTemp] = 0;

				int getRow = iTemp;
				for (size_t i = 0; i < man.bombPower; i++)
				{
					if (getRow < rows - 1)
					{
						man.score += battleField[++getRow][aTemp];
						battleField[getRow][aTemp] = 0;
					}
				}
				getRow = iTemp;
				for (size_t i = 0; i < man.bombPower; i++)
				{
					if (getRow > 0)
					{
						man.score += battleField[--getRow][aTemp];
						battleField[getRow][aTemp] = 0;
					}
				}

				int getCol = aTemp;
				for (size_t i = 0; i < man.bombPower; i++)
				{
					if (getCol < cols - 1)
					{
						man.score += battleField[iTemp][++getCol];
						battleField[iTemp][getCol] = 0;
					}
				}
				getCol = aTemp;
				for (size_t i = 0; i < man.bombPower; i++)
				{
					if (getCol > 0)
					{
						man.score += battleField[iTemp][--getCol];
						battleField[iTemp][getCol] = 0;
					}
				}
				//print man.score;
				std::cout << man.score << " points\n";
				man.score = 0;
			}

		}
		else
		{
			if (userInfoStr[6] == 'u')
			{
				man.bombPower++;
				std::cout << "Increased bomb power to " << man.bombPower << std::endl;
			}
			else
			{
				if (man.bombPower > 0)
				{
					man.bombPower--;
					std::cout << "Decreased bomb power to " << man.bombPower << std::endl;
				}
			}
		}
		cnt++;
	}

	//int a;
	//std::cin >> a;
	return 0;
}
