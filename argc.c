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

	new_str = _duplicate(str);
	token = strtok(new_str, " ");
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}
	free(new_str);
	return (i);
}
