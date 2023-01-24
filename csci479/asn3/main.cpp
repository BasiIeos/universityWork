#include <iostream>
#include <string>
#include "c4player.h"

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;

void displayBoard(int** board)
{
	for (int i = HEIGHT - 1; i >= 0; i--)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			char c;
			if (board[i][j] == 0)
				c = '_';
			else if (board[i][j] == 1)
				c = 'O';
			else
				c = 'X';
			cout << c << ' ';
			
		}
		cout << endl;
	}
}

//function used by checkBoard
int checkLine(int** board, int row, int col, int rdelta, int cdelta)
{
	int count = 0, curWinner = 2;
	while ((row < HEIGHT) && (row >= 0) && (col < WIDTH) && (col >= 0))
	{
		if (board[row][col] == curWinner)
		{
			count++;
			if (count == 4) return curWinner;
		}
		else
		{
			count = 0;
			if (board[row][col] == 0)
				curWinner = 2;
			else
				curWinner = board[row][col];
		}
		row += rdelta;
		col += cdelta;
	}
	return 2;
}

//check if the game has ended and with which result if it has
int checkBoard(int** board)
{
	int result = 2;
	bool full = true;
	for (int i = 0; (i < WIDTH) && (full); i++)
		full = (board[HEIGHT - 1][i] != 0);

	//check all possible combinations of chips
	for (int i = 0; (i < WIDTH) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, 0);
	for (int i = 0; (i < HEIGHT) && (result == 2); i++)
		result = checkLine(board, i, 0, 0, 1);
	for (int i = 0; (i < WIDTH) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, -1);
	for (int i = 0; (i < WIDTH) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, 1);
	for (int i = 0; (i < WIDTH) && (result == 2); i++)
		result = checkLine(board, HEIGHT - 1, i, 1, -1);
	for (int i = 0; (i < WIDTH) && (result == 2); i++)
		result = checkLine(board, HEIGHT - 1, i, 1, 1);
	if (full)
		return 0;
	else
		return result;
}

int main(int argc, char* argv[])
{
	C4Player ai(HEIGHT, WIDTH, 4);
	
	int depth = 3;
	if (argc > 1)
		depth = stoi(argv[1]);
	cout << "You (O) are going to play the AI " << ai.getName() << " (X) in a game of Connect 4! Your chosen depth is " << depth << ". Good luck!\n";
	int** board = new int*[HEIGHT];
	for (int k = 0; k < HEIGHT; k++)
		board[k] = new int[WIDTH];
	// initiate the board
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			board[i][j] = 0;
	bool isPlayerAI = false;
	while (checkBoard(board) == 2)
	{
		cout << "Current board:\n";
		displayBoard(board);
		int col;
		if (!isPlayerAI)
		{
			cout << "Your move! Enter the number of column you want to drop your chip in:\n";
			cin >> col;
			col--;
			cout << col << '\n';
			cout << HEIGHT;
			while ((col <= 0) && (col > WIDTH) && (board[HEIGHT - 1][col] != 0))
		       	{
				cout << "test 2\n";
				cout << "Your move is not possible! Please try again:\n";
				cin >> col;
				col--;
			}
		}
		else
		{
			col = ai.move(board, depth);
			cout << ai.getName() << " drops his chip in column " << col + 1 << '\n';
		}
		//make the move
		bool moved = false;
		for (int i = HEIGHT; (i > 0) && (!moved); i--)
			if (board[i - 1][col] != 0)
			{
				board[i][col] = (isPlayerAI) ? (-1) : (1);
				moved = true;
			}
		if (moved == false)
			board[0][col] = (isPlayerAI) ? (-1) : (1);
		isPlayerAI = !isPlayerAI;
	}
	int result = checkBoard(board);
	if (result == 0)
		cout << "Tie! I did not... expect that. Again?\n";
	else if (result == 1)
		cout << "You won! Congratulations!! I am not at all sad. Please go easier on " << ai.getName() << " next time :(\n";
	else if (result == -1)
		cout << "You lost! " << ai.getName() << " wins again! Better luck next time :)\n";
	return 0;
}
