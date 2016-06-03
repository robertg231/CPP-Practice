#include"board.h"

#include<string>

//array of chars for printing symbols on board
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

