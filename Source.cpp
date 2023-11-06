#include <iostream>
#include "Header.h"


void read_square(int square[11][9])
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			square[i][j] = i * 10 + j;
		}

	}
}

void set_mines(int mines[10])
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		do
		{
			mines[i] = rand() % 90 + 11;
		} while (mines[i] % 10 == 0);

		for (int j = 0; j < i; j++)
		{
			if (mines[j] == mines[i])
			{
				i--;
				break;
			}
		}
	}
}

void grid(int square[11][9])
{
	system("cls");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			cout << setw(3) << square[i][j] << " |";
		}
		cout << " " << square[i][9] << endl << "____|____|____|____|____|____|____|____|____" << endl;
	}
}

int how_many_mines(int position, int mines[10])
{
	int number_of_mines = 0;
	if (position % 10 == 1)
	{
		for (int i = position - 10; i <= position + 10; i += 10)
		{
			for (int j = i; j <= i + 1; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (mines[k] == j)
					{
						number_of_mines++;
					}
				}
			}
		}
	}
	else if (position % 10 == 9)
	{
		for (int i = position - 11; i <= position + 9; i += 10)
		{
			for (int j = i; j <= i + 1; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (mines[k] == j)
					{
						number_of_mines++;
					}
				}
			}
		}
	}
	else
	{
		for (int i = position - 11; i <= position + 9; i += 10)
		{
			for (int j = i; j <= i + 2; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (mines[k] == j)
					{
						number_of_mines++;
					}
				}
			}
		}
	}
	return number_of_mines;
}

bool win_or_loss(int I, int J, int discovered_mines, int* mines, int square[11][9])
{
	while (discovered_mines < 10)
	{
		int position;
		cin >> position;
		I = position / 10;
		J = position % 10;
		for (int k = 0; k < 10; k++)
		{
			if (mines[k] == position)
			{
				square[I][J] = -1;
				grid(square);
				return false;
			}
		}
		if (position > 10 && position <= 100)
		{
			square[I][J] = how_many_mines(position, mines);
		}
		if (position > 100)
		{
			I = I % 10;
			for (int i = 0; i <= 9; i++)
			{
				if (I * 10 + J == mines[i])
				{
					square[I][J] = -1;
					discovered_mines++;
					break;
				}
				if (i == 9)
				{
					cout << position % 100 << " is not a mine" << endl;
					return false;
				}
			}
		}
		grid(square);
	}
}

