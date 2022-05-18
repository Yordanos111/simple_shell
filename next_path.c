#include "monster.h"

char *path_append(char *path, char *command)
{
        size_t i = 0, j = 0;
	char *buff;

        if (command == 0)
                command = "";

        if (path == 0)
                path = "";

        buff = malloc(sizeof(char) * (str_len(path) + str_len(command) + 2));
        if (!buff)
                return (NULL);

        while (path[i])
        {
                buff[i] = path[i];
                i++;
        }

        if (path[i - 1] != '/')
        {
                buff[i] = '/';
                i++;
        }
        while (command[j])
        {
                buff[i + j] = command[j];
                j++;
        }
        buff[i + j] = '\0';
        return (buff);
}

