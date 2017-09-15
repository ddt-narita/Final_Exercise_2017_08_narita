#include "Cell.h"



narita::Cell::Cell()
{
	row = -1;
	col = -1;
	//text = "‘I‘ğ’†";
}

narita::Cell::Cell(int row, int col)
{
	this->row = row;
	this->col = col;
}

narita::Cell ^ narita::Cell::operator=(const narita::Cell ^ cell)
{
	narita::Cell^ temp = gcnew Cell(cell->row, cell->col);
	
	return temp;
}
