#include "monty.h"

/**
 * execute_file- functtion to read and execute file content
 * @arg: path to file to be read
 * Return: nothing
 */
void execute_file(char *arg)
{
	char *buffer = NULL;
	size_t n = 0;
	char **token;
	FILE *file;
	unsigned int line_num;
	stack_t *my_stack = NULL;
	int val;

	file = fopen(arg, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &n, file) != -1)
	{
		line_num += 1;
		token = str_tok(buffer);
		if (token != NULL)
		{
			if (strcmp(token[0], "push") == 0 && token[1] != NULL)
			{
				val = atoi(token[1]);
				push(&my_stack, val);
			}
			else if (strcmp(token[0], "pall") == 0)
				pall(my_stack);
			else if (strcmp(token[0], "pint") == 0)
				pint(my_stack);
			else if (strcmp(token[0], "pop") == 0)
				pop(&my_stack);
			else
			{
				printf("An error occured");
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(file);
	free(buffer);
	free(token);
	free(my_stack);
}
