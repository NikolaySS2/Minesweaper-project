#include <iostream>
#include "Header.h"

int main()
{
	cout << "Pri postavqne na 1 predi nomera na poziciqta , dadenata poziciq se opredelq kato takava s bomba " << endl;
	int square[11][9];
	int mines[10];
	read_square(square);
	grid(square);
	set_mines(mines);
	cout << "START" << endl;
	int I = 0, J = 0;
	int discovered_mines = 0;
	if (win_or_loss(I, J, discovered_mines, mines, square))
	{
		cout << "You Won!" << endl;
	}
	else
	{
		cout << "You Lost!" << endl;
	}
	return 0;
}
