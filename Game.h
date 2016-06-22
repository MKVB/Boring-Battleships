#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H

class Game
{
private:
	Board plBoard;
	int lives;
public:
	Game();
	void hit(int i, int j);
	void draw();
	void set_lives(int l);
	int get_lives();
	Board& get_board();
	bool gameOver();
	void start();
};
#endif
