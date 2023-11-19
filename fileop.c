#include "monty.h"
#include <stdio.h>

/**
 * execute_file- functtion to read and execute file content
 * @file_path: path to file to be read
 * Return: nothing
 */
void execute_file(FILE *file)
{
	char *line, f_open;
	size_t line_size = 0;
	char *token;
	unsigned int line_num;

	f_open = fopen(file, "r");
	if (f_open == NULL)
		exit(EXIT_FAILURE);
	while (getline(&line, &line_size, f_open) != -1)
	{
		line_num += 1;
		token = str_tok(line);
		if (token != NULL)
		{
			if (strcmp(token[0], "push") == 0 && token[1] != NULL)
			{
				/**
				 * val = atoi(token[1]);
				 * push(&my_stack,val);
				 */
				printf("I worked");
			}
			/**
			* else if (strcmp(token[0], "pall") == 0)
			* pall(&my_stack);
			*/
			else
			{
				printf("An error occured");
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(f_open);
	free(line);
	free(token);
}
