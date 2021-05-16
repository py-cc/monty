#include "monty.h"
/**
 * func_pint -  opcode pint prints the value at the top of the stack
 * @head: pointer to double linked list
 * @line_number: line file to check
 *
 *
 */
void func_pint(stack_t **head, unsigned int line_number)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
