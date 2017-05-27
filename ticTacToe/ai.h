#ifndef AI_H
#define AI_H

#include"board.h"

struct aiMove
{
	aiMove(){};
	aiMove(int newScore) : score(newScore){}
	int x;
	int y;
	int score;
};

class ai
{
private:
	int aiSymbol;
	int playerSymbol;
	int level;

	aiMove getBestMove(board& currGameBoard, int currPlayerSymbol, aiMove alpha, aiMove beta);
	int getLevelAdjustment();

public:
	void init(int newAISymbol);
	void performMove(board& currGameBoard);
	void setLevel(int newLevel);

};

#endif