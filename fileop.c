#include "monty.h"
/**
 * free_stack - function to free stack
 * @stack: stack to be freed
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
 * @buffer: the line we are on
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
void execute_file(FILE *file)
{
	char *buffer = NULL;
	size_t n = 0;
	char **token;
	unsigned int line_num;
	stack_t *my_stack = NULL;

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
			push(&my_stack, atoi(token[1]));
		}
		else if (select_opcodes(token, &my_stack, line_num) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token[0]);
			free_close_exit(buffer, my_stack, file);
		}
	}
	free(buffer);
	free_stack(&my_stack);
}
