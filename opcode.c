#include "monty.h"

/**
 * opcode - calls for the function read
 * @head: Pointer head of double linked list
 * @token: Monty command
 * @line_number: NUmber of line read from file
 */

void opcode(stack_t **head, char *token, unsigned int line_number)
{

	int i;
	instruction_t command[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_add},
		{NULL, NULL}
	};

	i = 0;

	while (command[i].opcode)
	{
		if ((strcmp(command[i].opcode, token)) == 0)
		{
			command[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}

}
