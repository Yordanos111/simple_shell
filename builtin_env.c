#include "monster.h"

int setenv_ay(char **args, char __attribute__((__unused__)) **beginning)
{
        int index;
	char **var_env = NULL, **new_environ, *newvalue;
        size_t size;

        if (!args[0] || !args[1])
                return (write_error(args, -1));

        newvalue = malloc(str_len(args[0]) + 1 + str_len(args[1]) + 1);
        if (!newvalue)
                return (write_error(args, -1));
        str_cpy(newvalue, args[0]);
        str_cat(newvalue, "=");
        str_cat(newvalue, args[1]);

        var_env = get_env(args[0]);
        if (var_env)
        {
                free(*var_env);
                *var_env = newvalue;
                return (0);
        }
        for (size = 0; global_env[size]; size++)
                ;

        new_environ = malloc(sizeof(char *) * (size + 2));
        if (!new_environ)
        {
                free(newvalue);
                return (write_error(args, -1));
        }

        for (index = 0; global_env[index]; index++)
                new_environ[index] = global_env[index];

        free(global_env);
        global_env = new_environ;
        global_env[index] = newvalue;
        global_env[index + 1] = NULL;

        return (0);
}

int unsetenv_ay(char **args, char __attribute__((__unused__)) **beginning)
{
        char **var_env, **new_environ;
        size_t size;
        int index, index2;

        if (!args[0])
                return (write_error(args, -1));
        var_env = get_env(args[0]);
        if (!var_env)
                return (0);

        for (size = 0; global_env[size]; size++)
                ;

        new_environ = malloc(sizeof(char *) * size);
        if (!new_environ)
                return (write_error(args, -1));

        for (index = 0, index2 = 0; global_env[index]; index++)
        {
                if (*var_env == global_env[index])
                {
                        free(*var_env);
                        continue;
                }
                new_environ[index2] = global_env[index];
                index2++;
        }
        free(global_env);
        global_env = new_environ;
        global_env[size - 1] = NULL;

        return (0);
}



int env_ay(char **args, char __attribute__((__unused__)) **beginning)
{
        int index;
        char nc = '\n';

        if (!global_env)
                return (-1);

        for (index = 0; global_env[index]; index++)
        {
                write(STDOUT_FILENO, global_env[index], str_len(global_env[index]));
                write(STDOUT_FILENO, &nc, 1);
        }

        (void)args;
        return (0);
}

