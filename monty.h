#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int _argc(char *str);
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
char **str_tok(char *input);
void execute_file(FILE *file);
void pint(stack_t *stack);
void pop(stack_t **stack);
void free_close_exit(char *line, stack_t *stack, FILE *file);
void free_stack(stack_t **stack);
int is_valid_integer(char *str);
void free_array(char **tokens);
int select_opcodes(char **tokens, stack_t **stack, unsigned int line_number);

#endif
