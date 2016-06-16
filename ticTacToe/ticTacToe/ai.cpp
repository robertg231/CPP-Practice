#include"stdafx.h"
#include"ai.h"
#include<ctime>
#include<cstdlib>

//constant representing infinity
const int INF = 999999;

aiMove ai::getBestMove(board& currGameBoard, int currPlayerSymbol, aiMove alpha, aiMove beta)
{
	//base case checking to see if someone has won
	int winner = currGameBoard.checkWin();

	//if we have a winner we return the appropriate score
	//using minimax algorithm
	//ai wants to get highest score, player(human) wants to get smallest score
	if (winner == aiSymbol)
	{
		//our ai wants to get a winning value but our random adjustment can distort the value
		//and turn it into a losing value
		return aiMove(10 - getLevelAdjustment());
	}
	else if (winner == playerSymbol)
	{
		//our opponent wants a losing value(for ai) but our random adjustment can distort the value
		//and turn it into a winning value
		return aiMove(-10 + getLevelAdjustment());
	}
	else if (winner == TIE_VAL)
	{
		return aiMove(0);
	}


//here is where we will implement the alpha beta pruning

	//making a move so we can store the bestMove
	aiMove move;


	//if current player is ai, we find best move for human player
	//otherwise, we find best move for aiplayer
	if (currPlayerSymbol == aiSymbol)
	{
		//ai wants max score, we will store it in alpha

		//iterate through all the positions on the board until we find a valid spot
		for (int y = 0; y < currGameBoard.getSize(); y++)
		{
			for (int x = 0; x < currGameBoard.getSize(); x++)
			{
				//checking for valid move
				if (currGameBoard.getVal(x, y) == NO_VAL)
				{
					//storing our move coordinates
					move.x = x;
					move.y = y;

					//temporarily set move on board****REMEMBER TO REMOVE IT!!!
					currGameBoard.setVal(x, y, currPlayerSymbol);

					move.score = getBestMove(currGameBoard, playerSymbol, alpha, beta).score;

					if (move.score > alpha.score)
					{
						alpha = move;
					}

					//removing our temp move
					currGameBoard.setVal(x, y, NO_VAL);

					//prune if we find a move that isn't worth checking
					if (alpha.score >= beta.score)
					{
						return alpha;
					}
				}
			}
		}

		return alpha;
	}
	else
	{
		//human player wants min score, we will store it in beta

		//:( i know.... duplicate code :(((((

		//iterate through all the positions on the board until we find a valid spot
		for (int y = 0; y < currGameBoard.getSize(); y++)
		{
			for (int x = 0; x < currGameBoard.getSize(); x++)
			{
				//checking for valid move
				if (currGameBoard.getVal(x, y) == NO_VAL)
				{
					//storing our move coordinates
					move.x = x;
					move.y = y;

					//temporarily set move on board****REMEMBER TO REMOVE IT!!!
					currGameBoard.setVal(x, y, currPlayerSymbol);

					move.score = getBestMove(currGameBoard, aiSymbol, alpha, beta).score;

					if (move.score < beta.score)
					{
						beta = move;
					}

					//removing our temp move
					currGameBoard.setVal(x, y, NO_VAL);

					//prune if we find a move that isn't worth checking
					if (alpha.score >= beta.score)
					{
						return beta;
					}
				}
			}
		}

		return beta;
	}
}

int ai::getLevelAdjustment()
{
	srand(time(NULL));

	//we get a random number in our range or values based on our level
	//the larger the level number the higher the chance we get that our win and loss
	//will be chosen over the other
	//so if we have a rand num ranging from 1-50 and we add/sub from our win/loss values.
	//we have a 20%(1/5) chance of our value(originally 10) of being changed to a (still)favorable value
	//so we would have a 80% chance of considering a losing move as a winning move
	//and considering a winning move as a losing move
	return (rand() % (level + 1));
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
	aiMove initAlpha(-INF);
	aiMove initBeta(INF);

	aiMove bestMove = getBestMove(currGameBoard, aiSymbol, initAlpha, initBeta);
	currGameBoard.setVal(bestMove.x, bestMove.y, aiSymbol);
}

void ai::setLevel(int newLevel)
{
	level = newLevel;
}