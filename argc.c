#include "monty.h"
/**
 * _argc - function to return number of words
 * @str: tring to be checked
 * Return: integer
*/

int _argc(char *str)
{
	char *new_str;
	char *token;
	int i = 0;

	new_str = strdup(str);
	token = strtok(new_str, " \t\n");
	if (token == NULL)
	{
		free(str), str =  NULL;
		free(new_str), new_str = NULL;
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}
	free(new_str);
	return (i);
}
