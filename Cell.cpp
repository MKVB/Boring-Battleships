#include "Cell.h"

Cell::Cell()
{
	this->occupied = false;
	this->attacked = false;
	this->missed = false;
}

void Cell::set_occupied()
{
	this->occupied = true;
}

void Cell::set_attacked()
{
	this->attacked = true;
}

void Cell::deleteCell()
{
	this->occupied = false;
}

void Cell::set_missed()
{
	this->missed = true;
}

bool Cell::get_occupied()
{
	return occupied;
}

bool Cell::get_attacked()
{
	return attacked;
}

bool Cell::get_missed()
{
	return missed;
}
