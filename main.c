#include "monster.h"

int run(char **args, char **beginning);
void signal_handler(int signal_);


int run(char **args, char **beginning)
{
	int flag = 0, run_return = 0, status;
	char *command = args[0];
	pid_t child_pid;

	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = locate_command(command);
	}
	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			run_return = (write_error(args, 13));
		else
			run_return = (write_error(args, 37));
	}
	else
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(command, args, global_env);
			if (errno == EACCES)
				run_return = (write_error(args,13));
			free_env_copy();
			free_mem(args, beginning);
			free_alias_link(aliases);
			_exit(run_return);
		}
		if (child_pid == -1)
                {
                        if (flag)
                                free(command);
                        perror("CHILD ERROR:");
                        return (1);
                }
		else
		{
			wait(&status);
			run_return = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(command);
	return (run_return);
}



void signal_handler(int signal_)
{
	char *new_line = "\n$ ";

	(void)signal_;
	signal(SIGINT, signal_handler);
	write(STDIN_FILENO, new_line, 3);
}


int main(int argc, char *argv[])
{
	char line = "$ ", *newline = "\n";
	int run_return = 0, _return;
	int *run_exe = &_return;

	app_name = argv[0];
	aliases = NULL;
	his_counter = 1;
	signal(SIGINT, signal_handler);

	*run_exe = 0;
	global_env = copy_env();
	if (!global_env)
		exit(-100);
	if (argc != 1)
	{
		run_return = file_command(argv[1], run_exe);
		free_env_copy();
		free_alias_link(aliases);
		return (*run_exe);
	}
	if (!isatty(STDIN_FILENO))
	{
		while ((run_return != END_OF_FILE) && (run_return != EXIT))
			run_return = args_handle(run_exe);
		free_env_copy();
		free_alias_link(aliases);
		return(*run_exe);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		run_return = args_handle(run_exe);
		if (run_return = END_OF_FILE || run_return = EXIT)
		{
			if (run_return = END_OF_FILE)
			{
				write(STDOUT_FILENO, newline, 1);
			}
			free_env_copy();
			free_alias_link(aliases);
			exit(*run_exe);
		}
	}
	free_env_copy();
	free_alias_link(aliases);
	return (*run_exe);
}
