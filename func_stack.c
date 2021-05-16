#include "monty.h"
/**
 * func_add - adds the top two elements of the stack.
 * @head: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 */
void func_add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int nodes;

	nodes = len_stack(*head);
	if (nodes >= 2)
	{
		tmp = *head;
		*head = tmp->next;
		(*head)->n = tmp->n + (*head)->n;
		(*head)->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
