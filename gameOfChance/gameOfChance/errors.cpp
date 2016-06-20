#include "stdafx.h"
#include <string>

//a function to display an error message and then exit
void fatal(char* message)
{
	char errorMessage[100];

	strcpy_s(errorMessage, "[!!] Fatal Error ");
	strncat_s(errorMessage, message, 83);
	perror(errorMessage);
	exit(-1);
}

//an error checked malloc() wrapper function
void* ecMalloc(unsigned int size)
{
	void* ptr;
	ptr = malloc(size);
	
	if (ptr == NULL)
	{
		fatal("in ecMalloc() on memory allocation");
	}

	return ptr;
}