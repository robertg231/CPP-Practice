//gameOfChance
//taken from Hacking Art Of Exploitation pg 102-110
//Rewritting their code so i understand it better
//and actually see it run


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "errors.c"

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

		scanf("%d", &choice);

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

	fd = open(DATAFILE, O_RDONLY);
	if(fd == -1)
	{
		return -1;
	}
	
	readBytes = read(fd, &entry, sizeof(struct user));

	while(entry.uid != uid && readBytes > 0)
	{
		readBytes = read(fd, &entry, sizeof(struct user));
	}

	close(fd);

	if(readBytes < sizeof(struct user))
	{
		return -1;
	}
	else
	{
		player = entry;
	}

	return 1;
}


//this is the new user registration function.
//it will create a new player account and append it to the file.
void registerNewPlayer()
{
	int fd;
	
	printf("-=-={ New Player Registration }=-=-\n");
	printf("Enter your name: ");
	inputName();

	player.uid = getuid();
	
	player.credits = 100;
	player.highScore = player.credits;

	fd = open(DATAFILE, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

	if(fd == -1)
	{
		fatal("in registerNewPlayer() while opening file");
	}
	
	write(fd, &player, sizeof(struct user));
	close(fd);

	printf("\nWelcome to the Game of Chance %s.\n", player.name);
	printf("You have been given %u credits.\n", player.credits);
}

//this function writes the current player data to the file
//it is used primarily for updating the credits after games
void updatePlayerData()
{
	int fd;
	int i;
	int readUid;
	char burnedByte;

	fd = open(DATAFILE, O_RDWR);
	if(fd == -1)
	{
		fatal("in updatePlayerData() while opening file");
	}
	
	read(fd, &readUid, 4);
	
	while(readUid != player.uid)
	{
		for(i = 0; i < sizeof(struct user) - 4; i++)
		{
			read(fd, &burnedByte, 1);
		}
		read(fd, &readUid, 4);
	}

	write(fd, &(player.credits), 4);
	write(fd, &(player.highScore), 4);
	write(fd, &(player.name), 100);
	close(fd);
}

//this function will display the current high score and
//the name of the person who set that high score.
void showHighScore()
{
	unsigned int topScore = 0;
	char topName[100];
	struct user entry;
	int fd;
	
	printf("\n====================| HIGH SCORE |====================\n");
	fd = open(DATAFILE, O_RDONLY);
	if(fd == -1)
	{
		fatal("in showHighScore() while opening file");
	}
	
	while(read(fd, &entry, sizeof(struct user)) > 0)
	{
		if(entry.highScore > topScore)
		{
			topScore = entry.highScore;
			strcpy(topName, entry.name);
		}
	}
	
	close(fd);
	if(topScore > player.highScore)
	{
		printf("%s has the high score of %u\n", topName, topScore);
	}
	else
	{
		printf("you currently have the high score of %u credits!\n", player.highScore);
	}
	
	printf("===========================================================================\n\n");
}

//this function awards the jackpot for the Pick a Number game
void jackpot()
{
	printf("*+*+*+*+*+*+* JACKPOT *+*+*+*+*+*+*\n");
	printf("You have won the jackpot of 100 credits!\n");
	player.credits += 100;
}

//this function is used to input the player name, since
//scanf(%s", &whatever) will stop input at the first space
void inputName()
{
	char* namePtr;
	char* inputChar = '\n';

	while(inputChar == '\n')
	{
		scanf("%c", &inputChar);
	}
	
	namePtr = (char*) &(player.name);
	
	while(inputChar !=  '\n')
	{
		*namePtr = inputChar;
		scanf("%c", &inputChar);
		namePtr++;
	}
	
	*namePtr = 0;
}


//this function print the 3 cards for the Find the Ace game.
//it expects a message to display, a pointer to the cards array,
//and the card the user has picked as input. if the userPick is
//-1, then the selection numbers are displayed.
void printCards(char* message, char* cards, int userPick)
{
	int i;
	printf("\n\t*** %s ***\n", message);
	printf("     \t._.\t._.\t._.\n");
	printf("cards:\t|%c|\t|%c|\t|%c|\n\t", cards[0], cards[1], cards[2]);
	if(userPick == -1)
	{
		printf(" 1 \t 2 \t 3\n");
	}
	else
	{
		for(i = 0; i < userPick; i++)
		{
			printf("\t");
		}
		printf(" ^-- your pick\n");
	}
}

//this function inputs wages for both the No Match Dealer and
//Find the Ace games. It expects the available credits and the
//previous wager as arguments. The previousWager is only important
//for the second wager in the Find the Ace game. The function
//returns -1 if the wager is too big or too little, and it returns
//the wager amount otherwise
int takeWager(int availableCredits, int previousWager)
{
	int wager;
	int totalWager;

	printf("how many of your %d credits would you like to wager?   ", availableCredits);
	scanf("%d", &wager);

	if(wager < 1)
	{
		printf("Nice try, but you must wager a positive number!\n");
		return -1;
	}
	
	totalWager = previousWager + wager;
	if(totalWager > availableCredits)

	{
		printf("your total wager of %d is more than you have!\n", totalWager);
		printf("you only have %d available credits, try again.\n", availableCredits);
		return -1;
	}
	return wager;
}

//this function contains a loop to allow the current game to be
//played again. t also writes the new credit total to file
//after each game is played
void playGame()
{
	int playAgain = 1;
	int (*game) ();
	char selection;

	while(playAgain)
	{
		printf("\n[Debug] currentGame pointer @ 0x%08x\n", player.currGame);
		if(player.currGame() != -1)
		{
			if(player.credits > player.highScore)
			{
				player.highScore = player.credits;
			}

			printf("\nYou now have %u credits\n", player.credits);
			updatePlayerData();
			printf("Would you like to play again? (y/n) ");
			selection = '\n';
			while(selection == '\n')
			{
				scanf("%c", &selection);
			}
			if(selection == 'n')
			{
				playAgain = 0;
			}
		}
		else
		{
			playAgain = 0;
		}
	}
}



//this function is the Pick a Number game
//it return -1 if the player doesn't have enough credits.
int pickNumber()
{
	int pick;
	int winningNumber;
	
	printf("\n######### Pick a Number ##########\n");
	printf("this game costs 10 credits to play. Simply pick a number\n");
	printf("between 1 and 20, and if you pick the winning number, you\n");
	printf("will win the jackpot of 100 credits!\n\n");
	
	winningNumber = (rand() % 21);

	if(player.credits < 10)
	{
		printf("you only have %d credits. that's not enough to play!\n\n", player.credits);
		return -1;
	}

	player.credits -= 10;
	printf("10 credits have been deducted from you account.\n");
	printf("Pick a number between 1 and 20: ");
	scanf("%d", &pick);

	printf("the winning number is %d\n", winningNumber);
	
	if(pick == winningNumber)
	{
		jackpot();
	}
	else
	{
		printf("sorry, you didn't win.\n");
	}
	return 0;
}


//this is the No Match Dealer Game
//it returns -1 if the player has 0 credits
int dealerNoMatch()
{
	int i;
	int j;
	int numbers[16];
	int wager = -1;
	int match = -1;

	printf("\n:::::: No Match Dealer :::::::\n");
	printf("in this game, you can wager up to all of you credits.\n");
	printf("The dealer will deal out 16 random numbers between 0 and 99.\n");
	printf("if there are not matches among them, you double your money!\n\n");

	if(player.credits == 0)
	{
		printf("you don't have any credits to wager!\n\n");
		return -1;
	}

	while(wager == -1)
	{
		wager = takeWager(player.credits, 0);
	}
	
	printf("\n\t:: Dealing out 16 random numbers ::\n");
	
	for(i = 0; i < 16; i++)
	{
		numbers[i] = rand() % 100;
		printf("%2d\t", numbers[i]);
		if(i % 8 == 7)
		{
			printf("\n");
		}
	}

	for(i = 0; i < 15; i++)
	{
		j = i + 1;
		while(j < 16)
		{
			if(numbers[i] == numbers[j])
			{
				match = numbers[i];
			}
			j++;
		}
	}

	if(match != -1)
	{
		printf("the dealer matched the number % d!\n", match);
		printf("you lose %d credits.\n", wager);
		player.credits -= wager;
	}
	else
	{
		printf("there were no matches! you win %d credits!\n", wager);
		player.credits += wager;
	}
	return 0;
}

//this is the find the ace game
//it returns -1 if the player has 0 credits
int findAce()
{
	int i;
	int ace;
	int totalWager;

	int invalidChoice;
	int pick = -1;
	int wagerOne = -1;
	int wagerTwo = -1;
	
	char choiceTwo;
	char cards[3] = {'X','X','X'};

	ace = rand() % 3;

	printf("********** Find the Ace ***********\n");
	printf("in this game,you can wager up to all of you credits.\n");
	printf("three cards will be dealt out, two queens and one ace\n");
	printf("if you find the ace, you will win your wager.\n");
	printf("After choosing a card, one of the queens will be revealed.\n");
	printf("at this point, you may either select a different card or\n");
	printf("increase your wager.\n\n");
	
	if(player.credits == 0)
	{
		printf("You odn't have any credits to wager!\n\n");
		return -1;
	}

	while(wagerOne == -1)
	{
		wagerOne = takeWager(player.credits, 0);
	}

	printCards("Dealing cards", cards, -1);

	pick = -1;

	while((pick < 1) || (pick >3))
	{
		printf("Select a card: 1, 2, or 3 ");
		scanf("%d", &pick);
	}

	pick--;
	i = 0;

	while(i == ace || i == pick)
	{
		i++;
	}
	cards[i] = 'Q';

	printCards("Revealing a queen", cards, pick);

	invalidChoice = 1;

	while(invalidChoice)
	{
		printf("Would you like to:\n[c]hange your pick\tor\t[i]ncrease your wager?\n");
		printf("select c or i: ");
		choiceTwo = '\n';
		while(choiceTwo == '\n')
		{
			scanf("%c", &choiceTwo);
		}
		if(choiceTwo == 'i')
		{
			invalidChoice = 0;
			while(wagerTwo == -1)
			{
				wagerTwo = takeWager(player.credits, wagerOne);
			}
		}

		if(choiceTwo == 'c')
		{
			invalidChoice = 0;
			i = invalidChoice;

			while(i  == pick || cards[i] == 'Q')
			{
				i++;
			}

			pick = i;
			printf("your card pick has been changed to card %d\n", pick+1);
		}
	}

	for(i = 0; i < 3; i++)
	{
		if(ace == i)
		{
			cards[i] = 'A';
		}
		else
		{
			cards[i] = 'Q';
		}
	}

	printCards("End result", cards, pick);

	if(pick == ace)
	{
		printf("you have won %d credits from your first wager\n", wagerOne);
		player.credits += wagerOne;

		if(wagerTwo != -1)
		{
			printf("and an additional %d credits from your second wager!\n", wagerTwo);
			player.credits += wagerTwo;
		}
	}
	else
	{
		printf("you have lost %d credits from your first wager\n", wagerOne);
		player.credits -= wagerOne;
		if(wagerTwo != -1)
		{
			printf("and an additional %d credits from your second wager!\n", wagerTwo);
			player.credits -= wagerTwo;
		}
	}
	
	return 0;
}
