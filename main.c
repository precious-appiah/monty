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
	
	file = fopen(argv[1], "r");

	if(!file)
	{
		exit(EXIT_FAILURE);
	}

	execute_file(file);
	fclose(file);

	return (0);
}
