#include "main.h"

/**
 * check_exit - checks exit code
 * @buffer: character string buffer
 * Return: 0 to exit the shell, 1 to continue
 * recieving commands from the user
 */

int check_exit(const char *buffer)
{
	int i, j = 0, cmd;
	char tmp[5] = "exit";
	/* calculate and check the exit value */
	for (i = 0; i <= 4; i++)
	{
		if (tmp[i] == *(buffer + i))
			j++;
	}
	if (j == 5)
		cmd = 0;
	else
		cmd = 1;
	return (cmd);
}
