#include "monster.h"

int main(int ac, char **av, char *envp[])
{
        char *line = NULL, *path_command = NULL, *path = NULL;
        size_t buff_size = 0;
        ssize_t line_size = 0;
        char **command = NULL, **paths = NULL;
        (void)envp, (void)av;
        if (ac < 1)
                return (-1);
        signal(SIGINT, signal_handler);
        while (1)
        {
                free_buff(command);
                free_buff(paths);
                free(path_command);
                user_prompt();
                line_size = getline(&line, &buff_size, stdin);
                if (line_size < 0)
                        break;
                info.ln_count++;
                if (line[line_size - 1] == '\n')
                        line[line_size - 1] = '\0';
                command = token(line);
                if (command == NULL || *command == NULL || **command == '\0')
                        continue;
                if (check_er(command, line))
                        continue;
                path = locate_path();
                paths = token(path);
                path_command = test_path(paths, command[0]);
                if (!path_command)
                        perror(av[0]);
                else
                        run(path_command, command);
        }
        if (line_size < 0 && flags.interactive)
                write(STDERR_FILENO, "\n", 1);
        free(line);
        return (0);
}

