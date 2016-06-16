#include"stdafx.h"
#include"board.h"

#include<string>

//array of chars for printing symbols on board
//using 3d array. 
//I THINK!!!!! may not be correct
//yz coords change, but x stays the same
//so for each x(0,1,2) we have different "symbols"
//x = 0 = blank
//x = 1 = X
//x = 2 = O
const char SYMBOLS[3][3][3] =
{
	{	{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	},
	{
		{ 'X', ' ', 'X' },
		{ ' ', 'X', ' ' },
		{ 'X', ' ', 'X' }
	},
	{
		{ 'O', 'O', 'O' },
		{ 'O', ' ', 'O' },
		{ 'O', 'O', 'O' }
	}
};

//private member functions

void board::addHorizontalLine(string& currBoard) const
{
	currBoard += "-";

	for (int i = 0; i < size; i++)
	{
		currBoard += "----";
	}

	currBoard += "--\n";
}

void board::addGuide(string& currBoard) const
{
	currBoard += " ";

	for (int i = 1; i <= size; i++)
	{
		currBoard += "| " + to_string(i) + " ";
	}

	currBoard += "|\n";
}




//public member functions

void board::init(int newSize)
{
	//we limit the size to 9 cause of limited console space
	if (newSize > 9)
	{
		newSize = 9;
	}

	size = newSize;

	//using the vectors fancy function to reset the size to whatever we want.
	gameBoard.resize(size * size);
	
	//clearing the board so we don't have garbage in it
	clear();
}

void board::clear()
{
	//iterating through whole vector and setting to "zero" value aka NO_VAL
	for (int i = 0; i < gameBoard.size(); i++)
	{
		gameBoard[i] = NO_VAL;
	}
}

void board::print() const
{
	//according to the tutorial it is faster to build a string
	//and print it rather than calling a print
	//function(ex printf, cout, ect.)multiple times.
	//this makes sense cause there will be fewer function calls(i think
	//cause i'm not sure if the building the string will have many calls)

	string text = "";

	//reserving some memory
	text.reserve(size * size * 4);

	//making top guide. STILL NOT SURE WHAT A "GUIDE" IS BUT.... we'll see
	addGuide(text);

	//looping through printed board columns. cause the board is size * size
	//so we look at size number of columns
	for (int y = 0; y < size; y++)
	{
		addHorizontalLine(text);

		//looping through symbol y coord. remember how we are using our symbol array 
		//think like books on a shelf. the yz coords change(to print the symbol)
		//but x stays the same
		for (int gy = 0; gy < 3; gy++)
		{

			//i don't understand this if....yet....
			//to my understanding... if we are in the middle part of the 
			//symbol(when gy ==1) we print a number.. why????
			if (gy == 1)
			{
				text += to_string(size - y);
			}
			else
			{
				text += " ";
			}

			//looping through printed board row cells
			for (int x = 0; x < size; x++)
			{
				//looping through symbol z coord
				text += "|";
				for (int gx = 0; gx < 3; gx++)
				{
					//depending on the value in the vector, we will print the
					//corresponding symbol
					//gy and gx are changing. they represent the y and z coords respectively
					text += SYMBOLS[getVal(x, size - y - 1)][gy][gx];
				}
			}

			text += "|";

			if (gy == 1)
			{
				text += to_string(size - y) + "\n";
			}
			else
			{
				text += "\n";
			}
		}
	}

	//adding bottom line
	addHorizontalLine(text);

	addGuide(text);

	//according to the tutorial, printf is faster than cout
	printf("%s\n", text.c_str());

}

//returns winner of game or tie or noVal depending on game state
int board::checkWin() const
{
	bool win;
	int c;

	//checking the rows
	for (int y = 0; y < size; y++)
	{
		//we get the first value in the column starting with y =0 then 1 then 2
		c = getVal(0, y);

		//as long as there is a value there(aka a O or X)
		//we check the rest of the spots
		if (c != NO_VAL)
		{
			win = true;
			//since we are checking rows we iterated through the x coordinates for a specific y
			for (int x = 0; x < size; x++)
			{
				//if the values are not equal to the first value we grabbed, then no win.
				if (getVal(x, y) != c)
				{
					win = false;
					break;
				}
			}

			if (win)
			{
				return c;
			}
		}
	}


	//checking the columns
	for (int x = 0; x < size; x++)
	{
		//we get the first value in the row starting with x = 0 then 1 then 2
		c = getVal(x, 0);

		//as long as there is a value there, we check the rest of the spots
		if (c != NO_VAL)
		{
			win = true;
			//since we are checking the columns we iterate through the y coordinates for a specific x
			for (int y = 0; y < size; y++)
			{
				//if the values aren't equal to the first one we grabbed, then no win.
				if (getVal(x, y) != c)
				{
					win = false;
					break;
				}
			}
			if (win)
			{
				return c;
			}
		}
	}


	//checking diagonal top left to bottom right

	//grabbing our top left corner value
	c = getVal(0, 0);
	
	//as long as there's a value there, we check the rest of the spots
	if (c != NO_VAL)
	{
		win = true;
		//we iterate diagonaly so both x and y are equal
		for (int xy = 0; xy < size; xy++)
		{
			//if the values aren't equal then no win
			if (getVal(xy, xy) != c)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			return c;
		}
	}


	//checking diagonal top right to bottom left to
	
	//grabbing the bottom left corner value
	c = getVal(size - 1, 0);

	//as long as there is a value there, we check the rest
	if (c != NO_VAL)
	{
		win = true;
		//we want to iterate from top right to bottom left
		//this means that the y coordinate is increasing 
		//and the x coordinate is decreasing
		for (int xy = 0; xy < size; xy++)
		{
			//if the values don't match then no win
			if (getVal(size - xy - 1, xy) != c)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			return c;
		}
	}

	//checking for tied game
	//so we check all the spots in the gameBoard
	for (int i = 0; i < gameBoard.size(); i++)
	{
		//if we haven't found a win yet, and there's still open spots
		//this means the games is still going. 
		//so we return No val.
		if (gameBoard[i] == NO_VAL)
		{
			return NO_VAL;
		}
	}

	//if we get here, every spot has been filled. so return tie
	return TIE_VAL;
}


//sets value at x,y spot
void board::setVal(int x, int y, int val)
{
	//we are using a vector(which is just a fancy 1d array)
	//but we are logically treating it as a 2d array
	gameBoard[(y * size) + x] = val;
}

//gets value at x,y spot
int board::getVal(int x, int y) const
{
	//remember we are logically treating our vector as a 2d array
	return gameBoard[(y * size) + x];
}

int board::getSize() const
{
	return size;
}