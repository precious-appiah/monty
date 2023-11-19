#include "monty.h"
/**
 * push - function to push element unto stack
 * @stack: structure of node
 * @value: number to be inserted
 * Return: nothing
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - function to print all
 * @stack : val to be added
 * Return: nothin
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * pint - function to print first element
 * @stack : val to be added
 * Return: nothing
 */
void pint(stack_t *stack)
{
	if (stack == NULL)
	{
		printf("can't pint, stack empty");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * pop - function to print first element
 * @stack : val to be added
 * Return: nothing
 */
void pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("can't pop an empyty stack \n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}


