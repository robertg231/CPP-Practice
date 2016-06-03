#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include"ai.h"
#include"board.h"


enum class gameState
{
	PLAYING,
	EXIT
};


class ticTacToe
{
private:

	board gameBoard;

	int playerSymbol;
	int aiSymbol;

	gameState currGameState;

	ai aiPlayer;

	bool isMultiplayer;


	void init();
	void playerMove();
	void aiMove();
	void changePlayer();
	void endGame(bool wasTie);

public:
	void run();



	
};


#endif