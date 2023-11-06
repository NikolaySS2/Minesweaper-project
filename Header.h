#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

void read_square(int square[11][9]);
void set_mines(int mines[10]);
void grid(int square[11][9]);
int how_many_mines(int position, int mines[10]);
bool win_or_loss(int I, int J, int discovered_mines, int* mines, int square[11][9]);