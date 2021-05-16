#include "monty.h"
/**
 * main - entry point to program monty
 * @argc: amount argument
 * @argv: array of arguments
 * Return: 0 for success and 1 when it fails.
 */
int main(int argc, char **argv)
{

	FILE *file;
	char *buffer, *token = NULL;
	unsigned int line_number = 1;
	stack_t *head = NULL;
	size_t len;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &len, file) != -1)
	{
		buffer[strlen(buffer) - 1] = '\0';
		token = strtok(buffer, " ");
		if (token != NULL && strcmp(token, "nop") != 0)
		{
			opcode(&head, token, line_number);
		}
		line_number++;
	}
	free(buffer);
	freenodes(&head);
	fclose(file);
	return (0);
}
