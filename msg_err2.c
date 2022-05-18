#include "monster.h"

char *err_13(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        len = str_len(app_name) + str_len(hist_str) + str_len(args[0]) + 24;
        err = malloc(sizeof(char) * (len + 1));
        if (!err)
        {
                free(hist_str);
                return (NULL);
        }

        str_cpy(err, app_name);
        str_cat(err, ": ");
        str_cat(err, hist_str);
        str_cat(err, ": ");
        str_cat(err, args[0]);
        str_cat(err, ": Access Denied\n\tMonster pervililage need\n");

        free(hist_str);
        return (err);
}



char *err_37(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        len = str_len(app_name) + str_len(hist_str) + str_len(args[0]) + 16;
        err = malloc(sizeof(char) * (len + 1));
        if (!err)
        {
                free(hist_str);
                return (NULL);
        }

        str_cpy(err, app_name);
        str_cat(err, ": ");
        str_cat(err, hist_str);
        str_cat(err, ": ");
        str_cat(err, args[0]);
        str_cat(err, ": NOT FOUND\n");

        free(hist_str);
        return (err);
}
