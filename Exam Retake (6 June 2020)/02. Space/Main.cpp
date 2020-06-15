#include <iostream>
#include <vector>
#include <sstream>

enum PLANET
{
	V = 'V', 
	S = 'S', 
	U = 'U', 
	N = 'N'
};

enum RESTRICTIONS
{
	HALF = 2,
	QUADRUPLE = 4
};

class Universe
{
public:
	Universe(std::vector<std::vector<char>> space, double spaceDust) :
		space(space), spaceDust(spaceDust)
	{

	}

	std::string info()
	{
		std::ostringstream info;
		info << "Space Dust Collected: " << this->spaceDust << "\n";
		for (size_t i = 0; i < this->space.size(); i++)
		{
			for (size_t a = 0; a < this->space.size(); a++)
			{
				info << this->space[i][a] << " ";
			}
			info << "\n";
		}
		return info.str();
	}

	void getCommands()
	{
		this->findMyCoordinates();

		char dirrection = 'N';
		while (dirrection != 'S')
		{
			std::cin >> dirrection;
			switch (dirrection)
			{
				case 'L':
				{						
					this->space[this->xCoordinate][this->yCoordinate] = '-';
					this->yCoordinate--;

					if (this->isInBound(this->xCoordinate, this->yCoordinate))
					{
						
						if (this->findTargetPlanet(this->xCoordinate, this->yCoordinate))
						{
							this->spaceDust += (double)this->space[this->xCoordinate][this->yCoordinate];
						}
						else
						{
							this->spaceDust /= RESTRICTIONS::HALF;
						}

						this->space[this->xCoordinate][this->yCoordinate] = 'K';
					}
					else
					{
						this->yCoordinate++;
						this->space[this->xCoordinate][this->yCoordinate] = 'K';

						this->spaceDust -= this->spaceDust * RESTRICTIONS::QUADRUPLE;
					}

					break;
				}
				case 'R':
				{
					this->space[this->xCoordinate][this->yCoordinate] = '-';
					this->yCoordinate++;

					if (this->isInBound(this->xCoordinate, this->yCoordinate))
					{

						if (this->findTargetPlanet(this->xCoordinate, this->yCoordinate))
						{
							this->spaceDust += (double)this->space[this->xCoordinate][this->yCoordinate];
						}
						else
						{
							this->spaceDust /= RESTRICTIONS::HALF;
						}

						this->space[this->xCoordinate][this->yCoordinate] = 'K';
					}
					else
					{
						this->yCoordinate--;
						this->space[this->xCoordinate][this->yCoordinate] = 'K';

						this->spaceDust -= this->spaceDust * RESTRICTIONS::QUADRUPLE;
					}
					break;
				}
				case 'U':
				{
					this->space[this->xCoordinate][this->yCoordinate] = '-';
					this->xCoordinate--;

					if (this->isInBound(this->xCoordinate, this->yCoordinate))
					{

						if (this->findTargetPlanet(this->xCoordinate, this->yCoordinate))
						{
							this->spaceDust += (double)this->space[this->xCoordinate][this->yCoordinate];
						}
						else
						{
							this->spaceDust /= RESTRICTIONS::HALF;
						}

						this->space[this->xCoordinate][this->yCoordinate] = 'K';
					}
					else
					{
						this->xCoordinate++;
						this->space[this->xCoordinate][this->yCoordinate] = 'K';

						this->spaceDust -= this->spaceDust * RESTRICTIONS::QUADRUPLE;
					}
					break;
				}
				case 'D':
				{
					this->space[this->xCoordinate][this->yCoordinate] = '-';
					this->xCoordinate++;

					if (this->isInBound(this->xCoordinate, this->yCoordinate))
					{

						if (this->findTargetPlanet(this->xCoordinate, this->yCoordinate))
						{
							this->spaceDust += (double)this->space[this->xCoordinate][this->yCoordinate];
						}
						else
						{
							this->spaceDust /= RESTRICTIONS::HALF;
						}

						this->space[this->xCoordinate][this->yCoordinate] = 'K';
					}
					else
					{
						this->xCoordinate--;
						this->space[this->xCoordinate][this->yCoordinate] = 'K';

						this->spaceDust -= this->spaceDust * RESTRICTIONS::QUADRUPLE;
					}
					break;
				}
				default:
					break;
			}
		}
	}

private:
	std::vector<std::vector<char>> space;
	int xCoordinate;
	int yCoordinate;
	double spaceDust;

private:
	void findMyCoordinates()
	{
		for (size_t i = 0; i < this->space.size(); i++)
		{
			for (size_t a = 0; a < space.size(); a++)
			{
				if (space[i][a] == 'K')
				{
					this->xCoordinate = i;
					this->yCoordinate = a;
				}
			}
		}
	}
	bool isInBound(int x, int y)
	{
		return x < this->space.size() && y < this->space.size() && x >= 0 && y >= 0;
	}
	bool findTargetPlanet(int x, int y)
	{
		return (this->space[x][y] == PLANET::N || this->space[x][y] == PLANET::S || 
			this->space[x][y] == PLANET::U || this->space[x][y] == PLANET::V);
	}
};

std::vector<std::vector<char>> createSpace()
{
	std::vector<std::vector<char>> space;
	int spaceSize;
	std::cin >> spaceSize;

	for (size_t i = 0; i < spaceSize; i++)
	{
		std::vector<char> line;
		for (size_t a = 0; a < spaceSize; a++)
		{
			char symbol;
			std::cin >> symbol;
			line.push_back(symbol);
		}
		space.push_back(line);
	}
	return space;
}

int main()
{
	std::vector<std::vector<char>> space;
	space = createSpace();

	double spaceDust;
	std::cin >> spaceDust;

	Universe universe(space, spaceDust);
	universe.getCommands();
	std::cout << universe.info();

	return 0;
}
