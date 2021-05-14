#include "monty.h"
/**
 * function_instruc - executions of opcode
 * @token: token string to evaluate
 * @line_number: line number of file
 * @head: node to handle
 *
 */
void function_instruc(char *token, unsigned int line_number, stack_t **head)
{
	instruction_t ops[] = {
		{"push", fun_push},
		{"pall", fun_pall},
		{"pint", fun_pint},
		{"pop", fun_pop},
		{"swap", fun_swap},
		{"add", fun_add},
		{"nop", fun_nop},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, token) == 0)
		{
			ops[i].f(head, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
/**
 * fun_pall - prints nodos
 * @head: pointer to nodo
 * @UNUSED: line number to file
 *
 */
void fun_pall(stack_t **head, unsigned int line_number UNUSED)
{
	stack_t *tmp = NULL;

	if (head == NULL || *head == NULL)
		return;

	tmp = *head;

	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
	*head = tmp;
}
/**
 * fun_push - pushes an element to the stack.
 * @head: pointer to node
 * @UNUSED: line number to file
 *
 */

void fun_push(stack_t **head, unsigned int line_number UNUSED)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (head == NULL)
	{
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}

/**
 * fun_pint - prints the value at the top of the stack
 * @head: pointer to node
 * @UNUSED: line number to file
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
 * @UNUSED: line number to file
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
 * @UNUSED: line number to file
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
 * fun_add adds the top two elements of the stack.-
 * @head: pointer to node
 * @UNUSED: line number to file
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
 * @UNUSED: line number to file
 */

void fun_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
