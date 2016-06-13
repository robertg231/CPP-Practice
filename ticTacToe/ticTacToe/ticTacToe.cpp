#include"stdafx.h"
#include<iostream>
#include"ticTacToe.h"

using namespace std;

void ticTacToe::init()
{
	currGameState = gameState::PLAYING;
	gameBoard.init(3);
	playerSymbol = X_VAL;

	printf("\n\n****** Welcome to TIC_TAC_TOE ******\n\n");

	//check for multiplayer
	printf("\nMultiplayer? (y/n): ");

	char input = ' ';
	bool isValid;

	//grabbing input and checking if it's valid, loop while not valid
	do
	{
		isValid = true;

		if (!(cin >> input))
		{
			cout << "Invalid input!";
			cin.clear();
			cin.ignore(1000, '\n');
			isValid = false;
		}
		else if (input == 'y' || input == 'Y')
		{
			isMultiplayer = true;
		}
		else
		{
			isMultiplayer = false;
		}
	} while (isValid == false);


	//if single player, we ask player what they want to be X or O
	if (!isMultiplayer)
	{
		printf("\nWould you like to be X or O: ");

		//loop while user input is invalid
		do
		{
			isValid = true;

			if (!(cin >> input))
			{
				cout << "Invalid input!";
				cin.clear();
				cin.ignore(1000, '\n');
				isValid = false;
			}
			else if (input == 'x' || input == 'X')
			{
				aiSymbol = O_VAL;
			}
			else if (input == 'o' || input == 'O')
			{
				aiSymbol = X_VAL;
			}
			else
			{
				cout << "Must enter X or O!";
				isValid = false;
			}
		} while (isValid = false);

		//aiPlayer is given and initialized to opposite symbol of user
		aiPlayer.init(aiSymbol);
	}
	printf("\n\n");
}


void ticTacToe::playerMove()
{
	bool wasValid = false;

	int x;
	int y;

	//ask user for spot, keep asking while input is not valid
	do
	{
		printf("Enter the X: ");

		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			printf("Error: Invalid input!");
		}

		printf("enter the Y: ");
		
		while (!(cin >> y))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			printf("Error: Invalid input!");
		}

		if (x < 1 || y < 1 || x > gameBoard.getSize() || y > gameBoard.getSize())
		{
			printf("error: Invalid X or Y! \n");
		}
		else if (gameBoard.getVal(x - 1, y - 1) != 0)
		{
			printf("Error: That spot is taken! \n");
		}
		else
		{
			wasValid = true;
		}
	} while (!wasValid);

	//when user gives a valid position, we set it on the board
	gameBoard.setVal(x - 1, y - 1, playerSymbol);
}

void ticTacToe::aiMove()
{
	aiPlayer.performMove(gameBoard);
}

void ticTacToe::changePlayer()
{
	//switching the current player
	//this "current player" refers to the one who is supposed to make the move
	//so once they make a move, the current player changes to the other
	if (playerSymbol == X_VAL)
	{
		playerSymbol = O_VAL;
	}
	else
	{
		playerSymbol = X_VAL;
	}
}


void ticTacToe::endGame(bool wasTie)
{
	gameBoard.print();

	if (wasTie)
	{
		printf("\n\n Tie game! Enter any key to play again, or Q to quit: ");
	}
	else
	{
		//player symbol refers to the "current player"
		//the last player who made the move(aka the winning move) is the winner
		if (playerSymbol == X_VAL)
		{
			printf("\n\n Player X wins! Enter any key to play again or Q to quit: ");
		}
		else
		{
			printf("\n\n Player O wins! Enter any key to play again, or Q to quit: ");
		}
	}

	//taking input to play again or quit
	char input;
	cin >> input;

	if (input == 'Q' || input == 'q')
	{
		currGameState = gameState::EXIT;
	}
	else
	{
		//reinit the game
		init();
	}
}


void ticTacToe::run()
{
	init();

	//game loop
	//keep playing until user quits
	while (currGameState != gameState::EXIT)
	{
		gameBoard.print();

		//say which player's turn it is
		if (playerSymbol == X_VAL)
		{
			printf("    Player X's turn!\n\n");
		}
		else
		{
			printf("    Player O's turn!\n\n");
		}

		//perform a move
		if (!isMultiplayer && playerSymbol == aiSymbol)
		{
			aiMove();
		}
		else
		{
			playerMove();
		}

		//check for a win
		int rv = gameBoard.checkWin();
		//check that someone won. so this means rv would be tie, or some specific player symbol
		if (rv != NO_VAL)
		{
			//we tell endgame whether it was a tie or not
			endGame(rv == TIE_VAL);
		}
		else
		{
			//if game is not over(aka no win or tie) we switch "curr player"
			changePlayer();
			//add a bunch of newlines to clear the screen(aka command prompt)
			for (int i = 0; i < 3; i++)
			{
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			}
		}
	}
}