#ifndef _FILE_H_
#define _FILE_H_

/*C standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

#define UNUSED  __attribute__((unused))
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void opcode(stack_t **head, char *token, unsigned int line_number);
void freenodes(stack_t **head);
void free_all(stack_t **head, char *buffer, FILE *file);
void func_push(stack_t **head, unsigned int line_number);
void func_pall(stack_t **head, unsigned int line_number);
void func_pint(stack_t **head, unsigned int line_number);
void func_pop(stack_t **head, unsigned int line_number);
void func_add(stack_t **head, unsigned int line_number);
void func_swap(stack_t **head, unsigned int line_number);
void func_nop(stack_t **head, unsigned int line_number);
int is_digit(stack_t **head, char *value, unsigned int line_number);
#endif /* MONTY_H */
