#include "monster.h"

int print_string(char *s)
{
        int i = 0;

        while (s[i] != '\0')
        {
                _putchar(s[i]);
                i++;
        }

        return (i);
}



int _putchar(char c)
{
        return (write(1, &c, 1));
}

