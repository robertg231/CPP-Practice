//gameOfChance
//taken from Hacking Art Of Exploitation pg 102-110
//Rewritting their code so i understand it better
//and actually see it run

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctime>
#include <cstdlib>
#include "errors.cpp"

//file to store the user data
#define DATAFILE "/var/chance.data"

//user struct to store information about the users
struct user
{
	int uid;
	int credits;
	int highScore;
	char name[100];
	int(*currGame)();
};

//we could make this thing into a class but the book is using C not C++
//**************Practice Idea.*************************
//Convert from C to C++.
//rewrite all this code to use classes.
//use private, public functions.
//make seperate header files for class declaration and cpp file for function definitions.
//try to get rid of the global variable.


//function prototypes
int getPlayerData();
void registerNewPlayer();
void updatePlayerData();
void showHighScore();
void jackpot();
void inputName();
void printCards(char*, char *, int);
int takeWager(int, int);
void playGame();
int pickNumber();
int dealerNoMatch();
int findAce();
void fatal(char*);

//global variable
struct user player;

int main()
{
	int choice = -1;
	int lastGame = -1;

	srand(time(0));

	if (getPlayerData() == -1)
	{
		registerNewPlayer();
	}

	while (choice != 7)
	{
		printf("-=[ Game of Chance Menu ]=-\n");
		printf("1 - Play the Pick a Number game\n");
		printf("2 - Play the No Match Dealer game\n");
		printf("3 - Play the Find the Ace game\n");
		printf("4 - Play View current high score\n");
		printf("5 - Change your user name\n");
		printf("6 - Reset your account at 100 credits\n");
		printf("7 - Quit\n");
		printf("[Name: %s]\n", player.name);
		printf("[You have %u credits] -> ", player.credits);

		scanf_s("%d", &choice);

		if ((choice < 1) || (choice > 7))
		{
			printf("\n[!!] The number %d is an invalid selection.\n\n", choice);
		}
		else if (choice < 4)
		{
			if (choice != lastGame)
			{
				if (choice == 1)
				{
					player.currGame = pickNumber;
				}
				else if (choice == 2)
				{
					player.currGame = dealerNoMatch;
				}
				else
				{
					player.currGame = findAce;
				}
				lastGame = choice;
			}
			playGame();
		}
		else if (choice == 4)
		{
			showHighScore();
		}
		else if (choice == 5)
		{
			printf("\nChange user name\n");
			printf("Enter your new name: ");
			inputName();
			printf("Your name has been changed.\n\n");
		}
		else if (choice == 6)
		{
			printf("\nYour account has been reset with 100 credits.\n\n");
			player.credits = 100;
		}
	}

	updatePlayerData();

	printf("\nThanks for playing! Bye.\n");



	return 0;
}

//this function reads the player data for the current uid
//from the file. it returns -1 if it is unable to find player
//data for the current uid.
int getPlayerData()
{
	int fd;
	int uid;
	int readBytes;

	struct user entry;

	uid = getuid();
}