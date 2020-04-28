#ifndef TicTac_h
#define TicTac_h

#include<string>
#include<iostream>

using namespace std;

class TicTac
{
private:
	string start;
public:
	TicTac();
	void ExploreBestMoves(string&);
	void DisplayBoard();
	void UpdateBoard(string&);
	int WinCheck(string&);
};

#endif