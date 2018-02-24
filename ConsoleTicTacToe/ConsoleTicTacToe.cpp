// ConsoleTicTacToe.cpp: Określa punkt wejścia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>

int array[3][3];


void showTable()
{
	// system("cls");

	for (int i = 0; i < 7; i++) {
		std::cout << "-";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		for (int j = 0; j < 3; j++)
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
		std::cout << "\n";
		for (int i = 0; i < 7; i++) {
			std::cout << "-";
		}

		std::cout << "\n";
	}
}

bool checkGame()
{
	if (array[0][0] != 0 && array[0][0] == array[0][1] && array[0][1] == array[0][2])
	{
		return true;
	}
	if (array[1][0] != 0 && array[1][0] == array[1][1] && array[1][1] == array[1][2])
	{
		return true;
	}
	if (array[2][0] != 0 && array[2][0] == array[2][1] && array[2][1] == array[2][2])
	{
		return true;
	}



	if (array[0][0] != 0 && array[0][0] == array[1][0] && array[1][0] == array[2][0])
	{
		return true;
	}
	if (array[0][1] != 0 && array[0][1] == array[1][1] && array[1][1] == array[2][1])
	{
		return true;
	}
	if (array[0][2] != 0 && array[0][2] == array[1][2] && array[1][2] == array[2][2])
	{
		return true;
	}

	if (array[0][0] != 0 && array[0][0] == array[1][1] && array[1][1] == array[2][2])
	{
		return true;
	}
	if (array[0][2] != 0 && array[0][2] == array[1][1] && array[1][1] == array[2][0])
	{
		return true;
	}

	return false;

}

int main()
{
	int player = 1, x = 0, y = 0, moves = 0;

	while (!checkGame() && moves < 9) {
		showTable();

		std::cout << "Player " << player << "\n";

		while (x < 0 || x > 2) {
			std::cout << "Give x coord: ";
			std::cin >> x;
			if (x < 0 || x > 2)
			{
				std::cout << "Must be from 0 to 2";
			}
		}

		while (y < 0 || y > 2) {
			std::cout << "Give y coord: ";
			std::cin >> y;
			if (y < 0 || y > 2)
			{
				std::cout << "Must be from 0 to 2";
			}
		}

		array[x][y] = player;

		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}

		moves++;
	}

	if (!checkGame())
	{
		std::cout << "Steal";
	}
	else {
		std::cout << "Player " << player << " won!";
	}

	system("PAUSE");

    return 0;
}

