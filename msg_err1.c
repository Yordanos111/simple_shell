#include "monster.h"


char *err_env(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        args--;
        len = str_len(app_name) + str_len(hist_str) + str_len(args[0]) + 45;
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
        str_cat(err, " Monster: Unable to add/remove from environment\n");

        free(hist_str);
        return (err);
}



char *err_syntax_2(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        len = str_len(app_name) + str_len(hist_str) + str_len(args[0]) + 33;
        err = malloc(sizeof(char) * (len + 1));
        if (!err)
        {
                free(hist_str);
                return (NULL);
        }

        str_cpy(err, app_name);
        str_cat(err, ": ");
        str_cat(err, hist_str);
        str_cat(err, ": SYNTAX ERROR: \"");
        str_cat(err, args[0]);
        str_cat(err, "\" unexpected\n");

        free(hist_str);
        return (err);

}



char *err_1(char **args)
{
        char *err;
        int len;

        len = str_len(app_name) + str_len(args[0]) + 13;
        err = malloc(sizeof(char) * (len + 1));
        if (!err)
                return (NULL);

        str_cpy(err, "Alias: ");
        str_cat(err, args[0]);
        str_cat(err, " NOT FOUND\n");

        return (err);
}



char *err_exit_2(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        len = str_len(app_name) + str_len(hist_str) + str_len(args[0]) + 27;
        err = malloc(sizeof(char) * (len + 1));
        if (!err)
        {
                free(hist_str);
                return (NULL);
        }

        str_cpy(err, app_name);
        str_cat(err, ": ");
        str_cat(err, hist_str);
        str_cat(err, ": EXIT- Illegal Number: ");
        str_cat(err, args[0]);
        str_cat(err, "\n");

        free(hist_str);
        return (err);
}

char *err_cd_2(char **args)
{
        char *err, *hist_str;
        int len;

        hist_str = i_to_a(his_counter);
        if (!hist_str)
                return (NULL);

        if (args[0][0] == '-')
                args[0][2] = '\0';
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
        if (args[0][0] == '-')
                str_cat(err, ": CD : Illegal option ");
        else
                str_cat(err, ": CD : can't cd to ");
        str_cat(err, args[0]);
        str_cat(err, "\n");

        free(hist_str);
        return (err);
}
