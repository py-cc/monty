#include "monty.h"

void func_pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if(*head && head)
	{
		tmp = *head;
		*head = tmp->next;
		if(tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


}
