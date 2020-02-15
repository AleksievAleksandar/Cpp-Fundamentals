#include <iostream>
#include <vector>

class TypeMatter
{
public:
	char type;
	int x;
	int y;
	int xSpeed;
	int ySpeed;
	int lifetime;
	bool isAlive;
	bool selfDestr;
	bool selfCheck;

	static size_t matter;
	static size_t antiMatter;
	static size_t destroyed;

	TypeMatter(char type, int x, int y, int xSpeed, int ySpeed, int lifetime):
		type(type), x(x), y(y), xSpeed(xSpeed), ySpeed(ySpeed), lifetime(lifetime)
	{
		isAlive = true;
		selfDestr = false;
		selfCheck = true;
		if (type == 'm')
		{
			matter++;
		}
		else
		{
			antiMatter++;
		}
	}

	void move()
	{
		if (this->isAlive)
		{
			this->x += this->xSpeed;
			this->y += this->ySpeed;
			this->lifetime--;
		}
		if (this->lifetime == 0 || this->x > 65535 || this->x < 0 || this->y > 65535 || this->y < 0)
		{
			this->isAlive = false;
			this->selfDestr = true;
		}
		if (this->selfCheck == true && this->isAlive == false)
		{
			selfCheck = false;
			if (this->type == 'm' && TypeMatter::matter > 0)
			{
				TypeMatter::matter--;
			}
			if (this->type == 'a' && TypeMatter::antiMatter > 0)
			{
				TypeMatter::antiMatter--;
			}
		}
	}
};

size_t TypeMatter::matter = 0;
size_t TypeMatter::antiMatter = 0;
size_t TypeMatter::destroyed = 0;

int main()
{
	size_t objects = 0;
	std::cin >> objects;

	char type;
	int x, y, xSpeed, ySpeed, lifetime;
	std::vector<TypeMatter> collection;
	for (size_t i = 0; i < objects; i++)
	{
		std::cin >> type >> x >> y >> xSpeed >> ySpeed >> lifetime;
		collection.push_back(TypeMatter(type, x, y, xSpeed, ySpeed, lifetime));
	}

	size_t steps;
	std::cin >> steps;
	
	bool findForDestr = false;
	int xTemp = 0;
	int yTemp = 0;
	for (size_t i = 0; i < steps; i++)
	{
		for (size_t a = 0; a < collection.size(); a++)
		{
			if (collection[a].isAlive)
			{
				collection[a].move();
			}		
		}
		for (size_t a = 0; a < collection.size(); a++)
		{
			for (size_t b = a+1; b < collection.size(); b++)
			{
				if (collection[a].x == collection[b].x && collection[a].y == collection[b].y)
				{
					if (collection[a].type != collection[b].type && collection[a].type != collection[b].type 
						&& collection[a].isAlive && collection[b].isAlive)
					{
						findForDestr = true;
						xTemp = collection[a].x;
						yTemp = collection[a].y;
						break;
					}				
				}
			}
			if (findForDestr)
			{
				for (size_t b = 0; b < collection.size(); b++)
				{
					if (collection[b].x == xTemp && collection[b].y == yTemp)
					{
						collection[b].isAlive = false;
						if (collection[b].type == 'm')
						{
							TypeMatter::matter--;
							TypeMatter::destroyed++;
						}
						else
						{
							TypeMatter::antiMatter--;
							TypeMatter::destroyed++;
						}
					}
				}
				findForDestr = false;
			}

		}
	}
	std::cout << TypeMatter::matter << " " << TypeMatter::antiMatter << "\n";
	std::cout << TypeMatter::destroyed;

	return 0;
}
