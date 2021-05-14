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
