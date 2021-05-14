#include "monty.h"


/**
 * fun_pint - prints the value at the top of the stack
 * @head: pointer to node
 * @line_number: unsigned int line number
 * Return: Void
 */

void fun_pint(stack_t **head, unsigned int line_number)
{

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: usage: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*head)->n);

	*head = (*head)->next;
}

/**
 * fun_pop - removes the top element of the stack.
 * @head: pointer to node
 * @line_number: unsigned int line number
 * Return: Void
 */

void fun_pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: usage: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

/**
 * fun_swap - swaps the top two elements of the stack.
 * @head: pointer to node
 * @line_number: unsigned int line number
 * Return: Void
 */

void fun_swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;
	int i = 0;

	tmp = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: usage: can't swap, stack null\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	while (tmp != NULL)
	{
		tmp = (tmp)->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: usage: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	tmp2 = (*head)->next;
	(*head)->next = (*head)->next->next;
	tmp2->next = *head;
	*head = tmp2;
}

/**
 * fun_add - adds the top two elements of the stack.-
 * @head: pointer to node
 * @line_number: unsigned int
 * Return: Void
 */

void fun_add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;
	int i = 0;
	int sum = 0;

	tmp = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: usage: can't add, stack null\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	while (tmp != NULL)
	{
		tmp = (tmp)->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: usage: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	sum = (*head)->n + (*head)->next->n;

	tmp2 = *head;
	*head = (*head)->next;
	(*head)->n = sum;
	free(tmp2);
}

/**
 * fun_nop - t does not anything
 * @head: pointer to node
 * @line_number: unsigned int line number
 * Return: Void
 */

void fun_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
