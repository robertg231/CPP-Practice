#include"stdafx.h"
#include"ai.h"

void ai::init(int newAISymbol)
{
	aiSymbol = newAISymbol;

	if (aiSymbol == X_VAL)
	{
		playerSymbol = O_VAL;
	}
	else
	{
		playerSymbol = X_VAL;
	}
}

void ai::performMove(board& gameBoard)
{
	//todo
}