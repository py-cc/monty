#include "monty.h"
/**
 * func_swap - swaps the top two elements of the stack.
 * @head: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 */
void func_swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int number, nodes;

	nodes = len_stack(*head);
	if (nodes >= 2)
	{
		tmp = (*head)->next;
		number = tmp->n;
		tmp->n = (*head)->n;
		(*head)->n = number;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
