#include "monty.h"

/**
 * swap - function to swap elements
 * @stack: stack
 * @line_num: line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - dunction to add elements
 * @stack: stack
 * @line_num
 */
void add(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	(*stack)->n = NULL;
}
