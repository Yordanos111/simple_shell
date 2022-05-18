#include "monster.h"

char **get_env(const char *var)
{
        int index, len;

        len = str_len(var);
        for (index = 0; global_env[index]; index++)
        {
                if (str_ncmp(var, global_env[index], len) == 0)
                        return (&global_env[index]);
        }

        return (NULL);
}

void free_env_copy(void)
{
        int index;

        for (index = 0; global_env[index]; index++)
                free(global_env[index]);
        free(global_env);
}



char **copy_env(void)
{
        char **new_env;
        size_t size;
        int index;

        for (size = 0; global_env[size]; size++)
                ;

        new_env = malloc(sizeof(char *) * (size + 1));
        if (!new_env)
                return (NULL);

        for (index = 0; global_env[index]; index++)
        {
                new_env[index] = malloc(str_len(global_env[index]) + 1);

                if (!new_env[index])
                {
                        for (index--; index >= 0; index--)
                                free(new_env[index]);
                        free(new_env);
                        return (NULL);
                }
                str_cpy(new_env[index], global_env[index]);
        }
        new_env[index] = NULL;

        return (new_env);
}

