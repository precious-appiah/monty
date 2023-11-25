#include "monty.h"

/**
 * free_stack - function to free stack
 * @stack: stack to be freed
 * Return: none
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
 * free_close_exit - frees line, stack, fcloses and then exits
 * @line: the line we are on
 * @stack: the stack we are working with
 * @file: the file we are reading
 */
void free_close_exit(char *buffer, stack_t *stack, FILE *file)
{
	free(buffer);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * execute_file- function to read and execute file content
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
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_close_exit(buffer, my_stack, file);
		}
		

		if (buffer[0] == '#')
			continue;

		token = str_tok(buffer);

		if (token == NULL)
			continue;

		if (strcmp(token[0], "push") == 0)
		{
			if (token[1] == NULL || !is_valid_integer(token[1]))
			{
				fflush(stdout);
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				free(token);
				free_close_exit(buffer, my_stack, file);
			}
			val = atoi(token[1]);
			push(&my_stack, val);
		}
	}

	fclose(file);
	free(buffer);
	free(token);
	free_stack(&my_stack);
}
