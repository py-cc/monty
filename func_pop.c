#include "monty.h"

void func_pop(stack_t **head, unsigned int line_number)
{
	if(*head)
	{
		*head = (*head)->next;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


}
