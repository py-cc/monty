#include "monty.h"


int is_digit(stack_t **head UNUSED, char *value, unsigned int line_number)
{

	int i, num;

	num = atoi(value);

	if (num == 0 && *value != '0' && value[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; value[i] != '\0'; i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (num);
}
