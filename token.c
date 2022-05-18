#include "monster.h"

char **token(char *line)
{
        char *buff = NULL, *bufp = NULL, *token_ = NULL, *delim = " :\t\r\n";
        char **tokens = NULL;
        int tokensize = 1;
        size_t index = 0, flag = 0;

        buff = str_dup(line);
        if (!buff)
                return (NULL);
        bufp = buff;

        while (*bufp)
        {
                if (str_chr(delim, *bufp) != NULL && flag == 0)
                {
                        tokensize++;
                        flag = 1;
                }
                else if (str_chr(delim, *bufp) == NULL && flag == 1)
                        flag = 0;
                bufp++;
        }
        tokens = malloc(sizeof(char *) * (tokensize + 1));
        token_ = strtok(buf, delim);
        while (token_)
        {
                tokens[index] = str_dup(token_);
                if (tokens[index] == NULL)
                {
                        free(tokens);
                        return (NULL);
                }
                token_ = strtok(NULL, delim);
                index++;
        }
        tokens[index] = '\0';
        free(buff);
        return (tokens);
}
