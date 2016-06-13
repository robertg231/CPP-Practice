#include"stdafx.h"
#include"ai.h"

aiMove ai::getBestMove(board& currGameBoard, int currPlayerSymbol)
{
	//base case checking to see if someone has won
	int winner = currGameBoard.checkWin();

	//if we have a winner we return the appropriate score
	//using minimax algorithm
	//ai wants to get highest score, player(human) wants to get smallest score
	if (winner == aiSymbol)
	{
		return aiMove(10);
	}
	else if (winner == playerSymbol)
	{
		return aiMove(-10);
	}
	else if (winner == TIE_VAL)
	{
		return aiMove(0);
	}

	//used to store our temp moves
	vector<aiMove> moves;

	//iterate through all the positions on the board until we find a valid spot
	for (int y = 0; y < currGameBoard.getSize(); y++)
	{
		for (int x = 0; x < currGameBoard.getSize(); x++)
		{
			//checking for valid move
			if (currGameBoard.getVal(x, y) == NO_VAL)
			{
				aiMove move;
				move.x = x;
				move.y = y;

				//temporarily set move on board****REMEMBER TO REMOVE IT!!!
				currGameBoard.setVal(x, y, currPlayerSymbol);

				//best moves are calculated by score

				//if current player is ai, we find best move for human player
				//otherwise, we find best move for aiplayer
				if (currPlayerSymbol == aiSymbol)
				{
					move.score = getBestMove(currGameBoard, playerSymbol).score;
				}
				else
				{
					move.score = getBestMove(currGameBoard, aiSymbol).score;
				}

				//storing our temp move
				moves.push_back(move);

				//removing our temp move
				currGameBoard.setVal(x, y, NO_VAL);
			}
		}
	}

	//index of best move in vector
	int bestMove = 0;

	//checking all the moves made and finding the one with the highest score
	//if we are the AI we want the highest score
	//if we are the player(human) we want the lowest score
	if (currPlayerSymbol == aiSymbol)
	{
		//since ai wants the highest, we start off with a really small score so it gets overwritten
		int bestScore = -100000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else
	{
		//since player(human) wants the lowest, we start off with a really high score
		int bestScore = 100000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	//returning the bestmove stored in the moves vector
	return moves[bestMove];
}

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

void ai::performMove(board& currGameBoard)
{
	aiMove bestMove = getBestMove(currGameBoard, aiSymbol);
	currGameBoard.setVal(bestMove.x, bestMove.y, aiSymbol);
}