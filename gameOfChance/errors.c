
#include <string.h>

//a function to display an error message and then exit
void fatal(char* message)
{
	char errorMessage[100];

	strcpy(errorMessage, "[!!] Fatal Error ");
	strncat(errorMessage, message, 83);
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
