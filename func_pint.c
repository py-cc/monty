#include "monty.h"

void func_pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	*head = tmp;

}
