#include "monty.h"

void free_all(stack_t **head, char *buffer, FILE *file)
{
	if (buffer != NULL)
		free(buffer);
	freenodes(head);
	fclose(file);

}
