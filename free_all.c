#include "monty.h"
/**
 * free_all - free eveythings memory
 * @head: pointer to linked list
 * @buffer: buffer contents token
 * @file: file to manage
 */
void free_all(stack_t **head, char *buffer, FILE *file)
{
	if (buffer != NULL)
		free(buffer);
	freenodes(head);
	fclose(file);

}
