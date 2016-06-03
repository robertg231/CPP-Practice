#ifndef AI_H
#define AI_H

#include"board.h"

class ai
{
private:
	int aiSymbol;
	int playerSymbol;

public:
	void init(int newAISymbol);
	void performMove(board& gameBoard);

};

#endif