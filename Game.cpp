#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	plBoard.placeShips();
	this->lives = 40;
}

void Game::hit(int i, int j)
{
	if (plBoard.getCell(i, j).get_occupied())
	{
		cout << "HIT" << endl;
		plBoard.getCell(i, j).set_attacked();
	}
	else
	{
		cout << "You've missed" << endl;
		plBoard.getCell(i, j).set_missed();
	}
	cout << endl;
}

void Game::draw()
{
	cout << endl;
	cout << endl;
	cout << "     1   2   3   4   5   6   7   8   9   10" << endl;
	cout << "   ________________________________________" << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				if (i + 1 != 10)
				{
					cout << i + 1 << " | ";
				}
				else
				{
					cout << i + 1 << "| ";
				}
			}
			if (j == 9)
			{
				if (plBoard.getCell(i, j).get_attacked())
				{
					cout << " X |" << endl;
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << " o |" << endl;
				}
				else
				{
					cout << " . |" << endl;
				}
			}
			else if (j == 0)
			{
				if (plBoard.getCell(i, j).get_attacked())
				{
					cout << " X |";
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << " o |";
				}
				else
				{
					cout << " . |";
				}
			}
			else
			{
				if (plBoard.getCell(i, j).get_attacked())
				{
					cout << " X |";
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << " o |";
				}
				else
				{
					cout << " . |";
				}
			}
		}
	}
}

Board& Game::get_board()
{
	return plBoard;
}

bool Game::gameOver()
{
	if (this->get_board().num_of_attacked() == this->get_board().num_of_occupied())
	{
		cout << endl;
		cout << "Congratulations, you have won a pointless game" << endl;
		cout << endl;
		cout <<endl;
		return true;
	}
	else if (this->lives <= 0)
	{
		cout << endl;
		cout << "You ran out of lives, looser, therefore you lose..." << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		return true;
	}
		return false;
}

void Game::set_lives(int l)
{
	this->lives = l;
}
int Game::get_lives()
{
	return lives;
}

void Game::start()
{
	cout << "Legend:" << endl;
	cout << "Dot(.) means sea, 'o' means you missed,'X' is a attacked,you've made" << endl;
	cout << "You have " << get_lives() << " lives " << endl;
	cout << "Start!" << endl;
	int t = get_lives();
	int i, j;
	draw();
	do
	{
		do
		{
			cout << endl;
			cout << "Enter coordinates" << endl;
			cin >> i >> j;
			if (i > 10 || j > 10 || i < 0 || j < 0)
			{
				cout << "Invalid coordinates! Try again" << endl;
			}
			else if (plBoard.getCell(i - 1, j - 1).get_attacked() || plBoard.getCell(i - 1, j - 1).get_missed())
			{
				cout << " You already shot there.Try with another coordinates." << endl;
			}
		} while (i > 10 || j > 10 || i < 0 || j < 0 || plBoard.getCell(i - 1, j - 1).get_attacked() || plBoard.getCell(i - 1, j - 1).get_missed());
		cout << endl;
		hit(i - 1, j - 1); // вадя едно от координатите за да може играещият например за първата клетка да въведе 1,1 а не 0,0!
		t--;
		this->set_lives(t);
		draw();
		cout << endl;
		cout << "You have " << t << " lives left" << endl;
	} while (!gameOver());

}
