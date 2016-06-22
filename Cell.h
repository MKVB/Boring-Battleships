#ifndef CELL_H
#define CELL_H

class Cell
{
private:
	bool occupied, attacked, missed;
public:
	Cell();
	void set_occupied();
	void set_attacked();
	void set_missed();
	bool get_occupied();
	bool get_attacked();
	bool get_missed();
	void deleteCell();
};
#endif
