#include "monty.h"
/**
* is_digit - function check string if number
* @s: string to check
*
* Return: true or false
*/
int is_digit(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[0] == '-') || (s[i] >= '0' && s[i] <= '9'))
			continue;
		else
			return (0);
	}
	return (1);
}
