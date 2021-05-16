#include "monty.h"

/**
 * opcode - calls for the function read
 * @head: Pointer head of double linked list
 * @token: Monty command
 * @line: NUmber of line read from file
 *
 */

void opcode(stack_t **head, char *token, unsigned int line_number, char **buffer, FILE *file)
{

		int i;
		instruction_t command[] = {
			{"push", func_push},
			{"pall", func_pall},
			{NULL, NULL}
		};

		i = 0;

		while(command[i].opcode)
		{
			if((strcmp(command[i].opcode, token)) == 0)
			{
				command[i].f(head, line_number);
				break;
			}
			i++;
		}
		if (command[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			free_all(head, *buffer, file);
			exit(EXIT_FAILURE);
		}

}
