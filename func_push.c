#include "monty.h"
/**
 * func_push - add node into a doubly linked list
 * @head: Pointer head of the double linkedlist
 * @line_number: line number of bytecode file
 */
void func_push(stack_t **head, unsigned int line_number)
{

	stack_t *new_node = NULL;
	char *value;
	int num;

	value = strtok(NULL, " ");
	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = is_digit(head, value, line_number);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freenodes(head);
		exit(EXIT_FAILURE);

	}
	new_node->n = num;
	new_node->prev = NULL;
	if (*head == NULL)
		new_node->next = NULL;
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;

}


