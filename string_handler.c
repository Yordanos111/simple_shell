#include "monster.h"

char *str_chr(char *s, char c)
{
        while (*s)
        {
                if (*s == c)
                        return (s);
                s++;
        }
        if (!c)
                return (s);
        return (NULL);
}


char *str_dup(char *s)
{
        char *ptr;
        int i, len;

        if (s == NULL)
                return (NULL);

        len = str_len(s);

        ptr = malloc(sizeof(char) * (len + 1));
        if (!ptr)
                return (NULL);
        for (i = 0; *s != '\0'; s++, i++)
                ptr[i] = s[0];

        ptr[i++] = '\0';
        return (ptr);
}


int str_ncmp(char *s1, char *s2, int n)
{
        int i;

        for (i = 0; s1[i] && s2[i] && i < n; i++)
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
        }
        return (0);
}


int str_len(char *s)
{
        int count = 0;

        while (*s != '\0')
        {
                count++;
                s++;
        }
        return (count);
}

int str_cmp(char *s1, char *s2)
{
        int i = 0, output;

        while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
                i++;

        output = (*(s1 + i) - *(s2 + i));

        return (output);
}

