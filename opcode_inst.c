#include "monty.h"

/**
 * select_opcodes - selects the correct opcode
 * @tokens: tokens array containing instructions
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 *
 * Return: 0 on success, 1 on failure
 */


int select_opcodes(char **tokens, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/**
		 * {"swap", swap},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		*/
		{NULL, NULL}
	};

	int i = 0;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(tokens[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	return (1); /* fail */
}
