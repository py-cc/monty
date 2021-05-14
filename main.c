#include "monty.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of string arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		error_file(argv[1]);

	read_file(file);
	fclose(file);
	return (0);
}
/**
 * error_usage - prints error file in standar error
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * error_file - prints error if can't open file
 * @argv: array string to evaluate
 * Return: nothing
 */
void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
/**
 * read_file - function read lines of file and call instructions
 * @file: file to be read
 */
void read_file(FILE *file)
{
	char *token, *tmp, *buffer = NULL;
	int line_number = 1, cont = 0;
	size_t size_len = 0;
	stack_t *head = NULL;

	number = 0;
	while (getline(&buffer, &size_len, file) != EOF)
	{

		token = strtok(buffer, " \n");

		cont = 0;
		while (token != NULL)
		{
			cont++;

			if (cont == 2)
			{
				if (is_digit(token) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				number = atoi(token);
				token = tmp;
				function_instruc(token, line_number, &head);
			}
			else if (cont == 1 && (strcmp(token, "push") == 0))
				token = token;

			else if (cont == 1 && (strcmp(token, "pall") == 0))
				 function_instruc(token, line_number, &head);

			else if (cont == 1 && (strcmp(token, "pint") == 0))
				function_instruc(token, line_number, &head);

			else if (cont == 1 && (strcmp(token, "pop") == 0))
				function_instruc(token, line_number, &head);

			else if (cont == 1 && (strcmp(token, "swap") == 0))
				function_instruc(token, line_number, &head);

			else if (cont == 1 && (strcmp(token, "add") == 0))
				function_instruc(token, line_number, &head);

			else if (cont == 1 && (strcmp(token, "nop") == 0))
				function_instruc(token, line_number, &head);

			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			tmp = token;
			token = strtok(NULL, " \n");
			if ((cont == 1) && (strcmp(tmp, "push") == 0) && (token == NULL))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	freenodes(head);
	free(buffer);
}

void freenodes(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
