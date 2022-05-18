#include "monster.h"

void exit_shell(char **command, char *line)
{
        free(line);
        free_buffers(command);
        exit(0);
}

