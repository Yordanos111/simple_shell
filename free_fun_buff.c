#include "monster.h"

void free_buff(char **buff)
{
        int i = 0;

        if (!buff || buff == NULL)
                return;
        while (buff[i])
        {
                free(buff[i]);
                i++;
        }
        free(buff);
}

