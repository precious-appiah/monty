#include "monty.h"
/**
 * main- entry for code
 * @argc: argc count
 * @argv: array
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execute_file(argv[1]);
	return (0);
}
