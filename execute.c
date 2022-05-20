#include "main.h"

/**
 * execute - executes a shell command
 * @buffer: buffer string
 * @argVec: argument vector
 * @envVec: environment vector
 */

void execute(char *buffer, char *argVec[], char *envVec[])
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		/* fork error */
		/* return (1); */
		write(2, "fork error!", 11);
	}
	if (pid == 0) /* Child process */
	{       /* Start of an execve call */
		if (execve(buffer, argVec, envVec) == -1)
		{
			/* command not found error handler */
			char execErr1[] = "./shell"; /* "Could not execute: "; */
			char execErr2[] = ": No such file or directory\n";
			/* perror("Could not execute "); */
			write(2, execErr1, sizeof(execErr1));
			/* write(2, buffer, sizeof(buffer)); */
			write(2, execErr2, sizeof(execErr2));
			exit(0);
		}
	}
	else /* Main process */
	{
		int wstatus;

		wait(&wstatus);
		check_wait_status(wstatus);
	}
}
