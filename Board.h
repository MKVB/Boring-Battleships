#include "Cell.h"
#ifndef BOARD_H
#define BOARD_H

struct CellCoord
{
	int x;
	int y;
};

struct surrounding
{
	bool top, bot,left,right,centre;
};

const int x = 10;
const int y = 10;


class Board
{
private:
	Cell sea[x][y];

public:
	surrounding checksurrounding(CellCoord coord, int range);
	int num_of_occupied();
	int num_of_attacked();
	void randShip(int n);
	void placeShips();
	void Clear_board();
	Cell& getCell(int i, int j);
};

#endif 
