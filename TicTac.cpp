#include "TicTac.h"

TicTac::TicTac()
{
	start = "         ";
}

void TicTac::ExploreBestMoves(string& current_state)
{

}

void TicTac::UpdateBoard(string& current_state)
{

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
	getchar();
}
