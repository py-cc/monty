#include "monty.h"
/**
 * is_digit - check number is negative or number
 * @UNUSED: argument no used
 * @value: value to check
 * @line_number: line to evaluate
 * Return: number to evaluate
 */

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
