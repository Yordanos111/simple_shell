#include "monster.h"


void env_print(void)
{
        int x = 0;
        char **env = global_env;

        while (env[x])
        {
                write(STDOUT_FILENO, (const void *)env[x], str_len(env[x]));
                write(STDOUT_FILENO, "\n", 1);
                x++;
        }
}

