#include "Board.h"
#include <stdlib.h>     
#include <time.h>       

CellCoord randCoord() 
{
	CellCoord randCoord;
	randCoord.x = rand() % 10;
	randCoord.y = rand() % 10;
	return randCoord;
}

int Board::num_of_attacked()
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sea[i][j].get_attacked())
			{
				count++;
			}
		}
	}
	return count;
}
surrounding Board::checksurrounding(CellCoord cc, int range) 
{
	surrounding result;
	result.bot = true;
	result.top = true;
	result.left = true;
	result.right = true;
	result.centre = true;

	if (sea[cc.x][cc.y].get_occupied())
	{
		result.centre = false;
	}
	for (int i = 0; i < range; i++)
	{
		if (sea[cc.x][cc.y + range - i].get_occupied() || cc.y + range > 9)
		{
			result.right = false;
		}
		if (sea[cc.x][cc.y - range + i].get_occupied() || cc.y - range < 0)
		{
			result.left = false;
		}
		if (sea[cc.x + range - i][cc.y].get_occupied() || cc.x + range > 9)
		{
			result.bot = false;
		}
		if (sea[cc.x - range + i][cc.y].get_occupied() || cc.x - range < 0)
		{
			result.top = false;
		}
	}
	return result;
}

int Board::num_of_occupied()
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sea[i][j].get_occupied())
			{
				count++;
			}
		}
	}
	return count;
}
void Board::randShip(int n) 
{
	CellCoord check;
	int random;
	do
	{
		do
		{
			check = randCoord();
		} while (sea[check.x][check.y].get_occupied());

	} while (!checksurrounding(check, n).bot &&
			 !checksurrounding(check, n).top && 
			 !checksurrounding(check, n).left &&
			 !checksurrounding(check, n).right);

	sea[check.x][check.y].set_occupied();

	if (checksurrounding(check, n).bot && checksurrounding(check, n).top &&
		checksurrounding(check, n).left && checksurrounding(check, n).right)
	{
		random = rand() % 4;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x + i][check.y].set_occupied();
				break;
			case 2: sea[check.x][check.y + i].set_occupied();
				break;
			case 3: sea[check.x - i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot && checksurrounding(check, n).top &&
		checksurrounding(check, n).left)
	{
		random = rand() % 3;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y].set_occupied();
				break;
			case 2: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot && checksurrounding(check, n).top && checksurrounding(check, n).right)
	{
		random = rand() % 3;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y + i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y].set_occupied();
				break;
			case 2: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}

	}
	else if (checksurrounding(check, n).left && checksurrounding(check, n).top && checksurrounding(check, n).right)
	{
		random = rand() % 3;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y + i].set_occupied();
				break;
			case 2: sea[check.x][check.y + i].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).left && checksurrounding(check, n).bot && checksurrounding(check, n).right)
	{
		random = rand() % 3;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y + i].set_occupied();
				break;
			case 2: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot && checksurrounding(check, n).top)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x - i][check.y - i].set_occupied();
				break;
			case 1: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).top && checksurrounding(check, n).left)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).top && checksurrounding(check, n).right)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y + i].set_occupied();
				break;
			case 1: sea[check.x - i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot && checksurrounding(check, n).left)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y - i].set_occupied();
				break;
			case 1: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot && checksurrounding(check, n).right)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y + i].set_occupied();
				break;
			case 1: sea[check.x + i][check.y].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).left && checksurrounding(check, n).right)
	{
		random = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			switch (random)
			{
			case 0: sea[check.x][check.y + i].set_occupied();
				break;
			case 1: sea[check.x][check.y - i].set_occupied();
				break;
			}
		}
	}
	else if (checksurrounding(check, n).bot)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[check.x + i][check.y].set_occupied();
		}
	}
	else if (checksurrounding(check, n).top)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[check.x - i][check.y].set_occupied();
		}
	}
	else if (checksurrounding(check, n).left)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[check.x][check.y - i].set_occupied();
		}
	}
	else if (checksurrounding(check, n).right)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[check.x][check.y + i].set_occupied();
		}
	}
}

void Board::placeShips()
{
	randShip(4);
	randShip(3);
	randShip(2);
	randShip(1);
	randShip(1);
	randShip(0);
	randShip(0);
}
void Board::Clear_board()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sea[i][j].deleteCell();
		}
	}
}
Cell & Board::getCell(int i, int j)
{
	return sea[i][j];
}

