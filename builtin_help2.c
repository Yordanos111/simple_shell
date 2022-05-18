#include "monster.h"


void setenv_help(void)
{
        char *txt = "Setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "environment variable, or modifies an existing one.\n\n";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "\tUpon failure, prints a message to STDERR.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}


void unsetenv_help(void)
{
        char *txt = "Unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "environmental variable.\n\n\tUpon failure, prints a ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "message to STDERR.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}

void env_help(void)
{
        char *txt = "Env: env\n\tPrints current environment.\n";

        write(STDOUT_FILENO, txt, str_len(txt));
}




