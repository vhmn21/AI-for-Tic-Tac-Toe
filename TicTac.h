#ifndef TicTac_h
#define TicTac_h

#include<string>
#include<iostream>

using namespace std;

class TicTac
{
public:
	int MinMax(int*, int);
	void Draw(int*);
	int Win(const int*);
	int Comp(int*);
	void DisplayBoard();
};

#endif