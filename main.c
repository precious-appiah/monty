#include "monty.h"
/**
 * main- entry for code
 * @argc: argc count
 * @argv: array
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		exit(EXIT_FAILURE);
	}
	
	file = argv[1];

	execute_file(file);
	 
	return (0);
}
