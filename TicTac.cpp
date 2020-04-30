#include "TicTac.h"

void TicTac::Draw(int* b)
{
	int k = 0;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 1 || j == 2)
			{
				cout << "|";
			}
			if (b[k] == 0)
			{
				cout << "   ";
			}
			else
			{
				if (b[k] == -1)
				{
					cout << " X ";
				}
				else
				{
					cout << " O ";
				}
			}
			k++;
		}
		cout << endl;
		if (i < 2)
		{
			cout << "---+---+---" << endl;
		}
	}
	return;
}
    

int TicTac::Win(const int* board)
{
	unsigned wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	int i;
	for (i = 0; i < 8; ++i)
	{
		if (board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
		{
			return board[wins[i][2]];
		}
	}
	return 0;
}

int TicTac::MinMax(int* board, int player)
{
	int winner = Win(board);
	if (winner != 0)
	{
		return winner * player;
	}
	int move = -1;
	int score = -2;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == 0)
		{
			board[i] = player;
			int thisScore = -MinMax(board, player * -1);
			if (thisScore > score)
			{
				score = thisScore;
				move = i;
			}
			board[i] = 0;
		}
	}
	if (move == -1)
	{
		return 0;
	}
	return score;
}

int TicTac::Comp(int* board)
{
	int move = -1;
	int score = -2;
	for (int i = 0; i < 9; ++i)
	{
		if (board[i] == 0)
		{
			board[i] = 1;
			int tempScore = -MinMax(board, -1);
			board[i] = 0;
			if (tempScore > score)
			{
				score = tempScore;
				move = i;
			}
		}
	}
	return move;
}

void TicTac::DisplayBoard()
{
	cout << "\n~~~~~~~~~~~~~Tic Tac Toe~~~~~~~~~~~~~\n";
	cout << "\n\n   BOARD:\n";
	cout << " 1 | 2 | 3 " << endl;
	cout << "---+---+---" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "---+---+---" << endl;
	cout << " 7 | 8 | 9 " << endl;
	cout << "Only legal moves are the numbers you see on the board. Press enter to start!\n\n";
	int board[9] = {0};
	int moves = 0, k;
	while (moves < 9)
	{
		int mv;
		cout << "Enter Player 1's Move\n";
		cin >> mv;
		if (board[mv - 1] == 0)
		{
			board[mv - 1] = -1;
			moves++;
			cout << "\n\nBoard after your move:\n";
			Draw(board);
			if (Win(board) == 0)
			{
				k = Comp(board);
				board[k] = 1;
				cout << "\n\nBoard after computer's move:\n";
				Draw(board);
				moves++;
				if (Win(board) != 0)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "Invalid Move, Try again !! \n\n";
		}
	}
	switch (Win(board))
	{
	case 0:
		cout << "Its a draw.\n";
		return;
	case 1:
		cout << "You lose.\n";
		return;
	case -1:
		cout << "Congratulations, You have beaten the unbeatable\n";
		return;
	}
}
