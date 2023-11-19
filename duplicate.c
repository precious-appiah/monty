#include "monty.h"

/**
 * _duplicate - function to create duplicate str
 * @str : string to be duplicated
 * Return: char
*/

char *_duplicate(char *str)
{
	char *new_str;
	char *cnt = str;
	int i = 0;

	while (*cnt)
	{
		cnt++;
		i++;
	}
	new_str = malloc(sizeof(char) * (i + 1));
	i = 0;
	cnt = str;
	while (*cnt)
	{
		*(new_str + i) = *cnt;
		cnt++;
		i++;
	}
	*(new_str + i) = '\0';

	return (new_str);
}
