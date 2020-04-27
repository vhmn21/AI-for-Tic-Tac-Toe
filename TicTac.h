#ifndef TicTac_h
#define TicTac_h

#include<string>

using std::string;

class TicTac
{
private:
public:
	void ExploreBestMoves(string&);
	void DisplayBoard();
	void UpdateBoard(string&);
	int WinCheck(string&);
};

#endif