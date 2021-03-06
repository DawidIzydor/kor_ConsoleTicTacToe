// ConsoleTicTacToe.cpp: Określa punkt wejścia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>

int array[3][3];

inline void showMinuses()
{
	std::cout << "\n-------";
	/*for (int i = 0; i < 7; ++i) {
		std::cout << "-";
	}*/
}


void showTable()
{
	system("cls");

	showMinuses();

	std::cout << "\n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < 3; ++j)
		{
			if (array[i][j] == 0)
			{
				std::cout << " ";
			}
			else {
				std::cout << (array[i][j] == 1 ? "x" : "o");
			}
			std::cout << "|";
		}

		showMinuses();

		std::cout << "\n";
	}
	std::cout << "\n";
}

bool constexpr checkGame()
{
	if (array[0][0] != 0)
	{
		if (array[0][0] == array[0][1] && array[0][1] == array[0][2]) {
			return true;
		}
		if (array[0][0] == array[1][0] && array[1][0] == array[2][0])
		{
			return true;
		}
		if (array[0][0] == array[1][1] && array[1][1] == array[2][2])
		{
			return true;
		}
	}

	if (array[1][1] != 0)
	{
		if (array[1][0] == array[1][1] && array[1][1] == array[1][2])
		{
			return true;
		}
		if (array[0][1] == array[1][1] && array[1][1] == array[2][1])
		{
			return true;
		}
		if (array[0][2] == array[1][1] && array[1][1] == array[2][0])
		{
			return true;
		}
	}

	if (array[2][2] != 0)
	{
		if (array[2][0] == array[2][1] && array[2][1] == array[2][2])
		{
			return true;
		}
		if (array[0][2] == array[1][2] && array[1][2] == array[2][2])
		{
			return true;
		}
	}

	return false;

}

void getCoords(int& x, int& y)
{
	x = -1; y = -1;
	while (x < 0 || x > 2) {
		std::cout << "Give x coord: ";
		std::cin >> x;
		--x;
		if (x < 0 || x > 2)
		{
			std::cout << "Must be from 1 to 3";
		}
	}

	while (y < 0 || y > 2) {
		std::cout << "Give y coord: ";
		std::cin >> y;
		--y;
		if (y < 0 || y > 2)
		{
			std::cout << "Must be from 1 to 3";
		}
	}
}

int main()
{
	int player = 2, x = -1, y = -1, moves = 0;

	bool won = false;

	std::cout << "Player 1 : x\nPlayer 2 : o\n\n";

	do {
		showTable();

		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}

		std::cout << "Player " << player << "\n";

		do {
			std::cout << "\n";
			getCoords(x, y);
		} while (array[y][x] != 0);

		array[y][x] = player;

		++moves;

	} while ((won=checkGame())==false && moves < 9);

	showTable();

	if (!won)
	{
		std::cout << "Steal\n\n";
	}
	else {
		
		std::cout << "Player " << player << " won!\n\n";
	}

	system("PAUSE");

    return 0;
}

