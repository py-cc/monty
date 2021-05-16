#include "monty.h"
/**
 * func_pall - Print all of the data in double linkedlist.
 * @head: Pointer head of the double linkedlist.
 * @UNUSED: macro
 *
 */
void func_pall(stack_t **head, unsigned int line_number UNUSED)
{

	stack_t *tmp = NULL;

	tmp = *head;

	if (*head != NULL)
	{
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
