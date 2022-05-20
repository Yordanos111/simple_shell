#include "main.h"

/**
 * main - main shell program
 * Return: 0 on success, something else otherwise
 */

int main(void)
{
	char *buffer;
	int cmd = 1; /* run == 1 exit == 0 */

	while (cmd == 1)
	{
		/* command parameters */
		char *argVec[] = {"./shell", NULL}; /* {"ls", "-l", NULL}; */
		char *envVec[] = {NULL};

		/* allocate memory for buffer */
		buffer = malloc(50 * sizeof(char));
		write(1, "#cisfun$ ", 9);
		if (read(0, buffer, 50))
		{/* Not EOF */
			/* print command */
			print_command(buffer);
			/* check if exit command */
			if (check_exit(buffer) == 0)
			{
				free(buffer); /* free buffer */
				exit(0); /* exit code */
			}
			else /* not exit command */
			{
				execute(buffer, argVec, envVec);
			}
		}
		else
		{
			/* EOF Handler */
			write(1, "\n", 1);
			free(buffer);
			exit(0);
		}
	}
	return (0);
}
