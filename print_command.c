#include "main.h"

/**
 * print_command - prints user input command
 * @buffer: character string buffer
 * Return: 0 on success, otherwises 1
 */

int print_command(char *buffer)
{
	int i;

	/* if (write(1, "Your Command: ", 14) == -1) */
	/*	return (1); */
	for (i = 1; *(buffer + i - 1) != '\n'; i++)
	{
	/*	if (write(1, (buffer + i - 1), 1) == -1) */
	/*		return (1); */
		;
	}
	*(buffer + i - 1) = '\0';
	/* if (write(1, "\n", 1)) */
	/*	return (1); */

	return (0);
}
