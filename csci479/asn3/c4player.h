#include <string>
#include <utility>

using namespace std;

class C4Player
{

	private:
		int Rows;
		int Columns;
		int Goal;
		string name;


//function used by checkBoard
int checkLine(int** board, int row, int col, int rdelta, int cdelta)
{
	int count = 0, curWinner = 2;
	while ((row < Rows) && (row >= 0) && (col < Columns) && (col >= 0))
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
	for (int i = 0; (i < Columns) && (full); i++)
		full = (board[Rows - 1][i] != 0);

	//check all possible combinations of chips
	for (int i = 0; (i < Columns) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, 0);
	for (int i = 0; (i < Rows) && (result == 2); i++)
		result = checkLine(board, i, 0, 0, 1);
	for (int i = 0; (i < Columns) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, -1);
	for (int i = 0; (i < Columns) && (result == 2); i++)
		result = checkLine(board, 0, i, 1, 1);
	for (int i = 0; (i < Columns) && (result == 2); i++)
		result = checkLine(board, Rows - 1, i, 1, -1);
	for (int i = 0; (i < Columns) && (result == 2); i++)
		result = checkLine(board, Rows - 1, i, 1, 1);
	if (full)
		return 0;
	else
		return result;
}

	int nOMoves(int** board)
	{
		int count = 0;
		for (int i = 0; i < Columns; i++)
		{
			bool found = false;
			for (int j = Rows - 1; (j >= 0) && (!found); j--)
			{
				if (board[j][i] != 0)
				{
					count += j + 1;
					found = true;
				}
			}
		}
		return count;
	}

	pair <int, int> minimax(int** board, int alpha, int beta, int depth)
	{
		//check for tie
		if (checkBoard(board) == 0)
			return make_pair(0,-1);
		//save current number of moves played
		int moves = nOMoves(board);
		//check if we can win on the next move
		for (int i = 0; i < Columns; i++)
			if (board[Rows - 1][i] == 0) //if we can move in the column
			{
				bool moved = false;
				for (int j = Rows - 1; (j > 0) && (!moved); j--)
				{
					if (board[j - 1][i] != 0)
					{
						int** newBoard = new int*[Rows];
						for (int k = 0; k < Rows; k++)
							newBoard[k] = new int[Columns];
						for (int k = 0; k < Rows; k++)
							for (int m = 0; m < Columns; m++)
								newBoard[k][m] = board[k][m];
						newBoard[j][i] = ((moves + 1) % 2) * 2 - 1;
						if (checkBoard(newBoard) == ((moves + 1) % 2) * 2 - 1) // and if this move is a win
							return make_pair((Rows*Columns + 1 - moves) / 2, i); // return the score of the position with this column
						moved = true;
					}
				}
			}
		if (depth == 0)
			return make_pair(0, -1); // if we have reached desired depth and nothing is a win, return draw
		int max = (Rows*Columns - 1 - moves) / 2; // if we can't win immediately, this is upper bound on the score of the position
		if (beta > max)
		{
			beta = max; // beta can be as big as the max score
			if (alpha >= beta) return make_pair(beta, -1); // prune if beta - alpha <= 0
		}
		int result_column = -1;
		int mod = -1;
                for (int i = 0; i < Columns; i++)
		{
			int col = Columns / 2 - (i + 1) / 2 * mod; //move from the centermost column, that way if the scores are tied it chooses the column closest to the middle
                        if (board[Rows - 1][col] == 0) //if we can move in the column
                        {
				int** newBoard = new int*[Rows];
				for (int k = 0; k < Rows; k++)
					newBoard[k] = new int[Columns];
				for (int k = 0; k < Rows; k++)
					for (int m = 0; m < Columns; m++)
						newBoard[k][m] = board[k][m];
                                bool moved = false;
                                for (int j = Rows - 1; (j > 0) && (!moved); j--)
                                {
                                        if (newBoard[j - 1][col] != 0)
                                        {
                                                newBoard[j][col] = ((moves + 1) % 2) * 2 - 1; // make the move
                                                int score = -1 * minimax(newBoard, -beta, -alpha, depth - 1).first; // get the score for the new position
						if (score >= beta) return make_pair(score, col); // prune since we found a better move than needed
						if (score > alpha)
						{	
							result_column = col;
							alpha = score; // increase alpha for next exploration since we only need something better than what we have
						}
						moved = true;
					}
				}
			}
			mod *= -1;
		}
		return make_pair(alpha, result_column); // return what we have as the best move
	}


	public:
		C4Player(int r = 6, int c = 7, int g = 4)
		{
			Rows = r;
			Columns = c;
			Goal = g;
			name = "Connectvin \"Magic\" Fourson";
		}

		string getName()
		{
			return name;
		}
		
		int move(int** board, int depth)
		{
			return minimax(board, -Rows*Columns, Rows*Columns, depth*2).second;
		}
};
