/*
 * TicTacToe.h
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <ctime>
#include <cstdlib>

const int BOARDSIZE = 3;

class TicTacToe
{
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;

public:
	TicTacToe();
	bool isValidMove(int, int);
	void getOMove(int &, int &);
	void getXMove(int &, int &);
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe()
{ // How to call this function?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	srand(time(0));
	noOfMoves = 0;
}

void TicTacToe::displayBoard()
{ // Where to get the board data?
	cout << "   1    2    3" << endl
		 << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl
				 << "     |    |    " << endl;
	}
	cout << endl;
}

bool TicTacToe::isValidMove(int x, int y)
{
	bool isValid;

    if (board[x][y] == 0) isValid = true;
    else isValid = false;

    return isValid;
}

void TicTacToe::getOMove(int &x, int &y)
{ // What does & mean?
	int row, col;
	
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (!isValidMove(row, col));

	x = row;
	y = col;
}

void TicTacToe::getXMove(int &x, int &y)
{ // What does & mean?
	int row, col;
	do
	{
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
}

void TicTacToe::addMove(int x, int y, int player)
{ // What is this function for?
	board[x][y] = player;
}

int TicTacToe::gameStatus()
{
	// Add your code to complete the program
	// Check columns for a win
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0)
		return board[0][0];
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0)
		return board[1][0];
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0)
		return board[2][0];

	// Check diagonals for a win
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
		return board[0][2];

	// Check for rows
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0)
		return board[0][0];
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0)
		return board[0][1];
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0)
		return board[0][2];

	if (noOfMoves >= 9)
		return 2;

	return 0;
}

int TicTacToe::play()
{ // What is the counterpart of this function in the original code

	int player = 1;

	displayBoard();
	int done = 0;
	while (done == 0)
	{
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		if (player == 1) {
			getXMove(x, y);
		} else {
			getOMove(x, y);
		}

		addMove(x, y, player);
		noOfMoves++;
		displayBoard();

		done = gameStatus();
		if (done == 1)
		{
			cout << "Player X wins!" << endl;
			return 1;
		}
		else if (done == -1)
		{
			cout << "Player O wins!" << endl;
			return -1;
		}
		else if (done == 2)
		{
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

	return 0;
}

#endif /* TICTACTOE_H_ */
