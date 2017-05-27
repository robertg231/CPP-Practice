#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<string>

using namespace std;

//game values
const int TIE_VAL = -1;
const int NO_VAL = 0;

//player symbols
const int X_VAL = 1;
const int O_VAL = 2;

class board
{
private:
	vector<int> gameBoard;
	int size;

	//these are used to help print the board
	void addHorizontalLine(string& currBoard) const;
	void addGuide(string& currBoard) const;

public:
	void init(int newSize);
	void clear();
	void print() const;

	int checkWin() const;

	void setVal(int x, int y, int val);

	int getVal(int x, int y) const;
	int getSize() const;

};

#endif
