#include "monty.h"
/**
 * str_tok - function to tokenize
 * @input: input param
 * Return: char
 */
char **str_tok(char *line)
{
	char *token;
	size_t arg_count;
	int count = 0;
	char **argv;

	arg_count = _argc(line);
	arg_count++;
	argv = malloc(sizeof(char *) * arg_count);
	token = strtok(line, " \t\n");
	while (token)
	{
		argv[count] = token;
		token = strtok(NULL, " \t\n");
		count++;
	}
	argv[count] = NULL;
	return (argv);
}
