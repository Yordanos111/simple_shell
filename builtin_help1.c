#include "monster.h"

void cd_help(void)
{
	char *txt = "cd: cd [DIRECTORY]\n\tChanging directory of the";

	write(STDOUT_FILENO, txt, str_len(txt));
        txt = " process to DIRECTORY.\n\n\tNo argument is given, the ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "command is interpreted, $HOME! If the argument '-' is";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = " given, the command is interpreted as cd $OLDPWD.\n\n";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "\tThe environment variables PWD and OLD_PWD are updated ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "after a change of directory.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}


void exit_help(void)
{
	char *txt = "EXIT: exit [STATUS]\n'tQutiting The Monster.\n\t "

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "The STATUS argument(integer) is used to exit the monster.";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = " If there is no argument given, the command is interpreted as";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = " EXIT 0.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}

void help_sos(void)
{
        char *txt = "HELP: sos\n\tSee all possible ay(aman_yordi) builtin commands.\n";

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "\n help [BUILTIN NAME]\n\tSee specific information on each ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "builtin commands.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}


void all_help(void)
{
        char *txt = "AY(aman_yordi)\nInternal Monster commands.\n";

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "Command 'help' shows this list.\nType 'help name' to find ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "out more about the function 'name'.\n\n  alias   \t";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "unsetenv [VARIABLE]\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}

void alias_help(void)
{
        char *txt = "Alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "\n\talias: Prints all aliases.\n ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "In the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = " the aliases name, name2, etc. one per line, in the ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = " an alias for each NAME whose VALUE is given. If NAME ";
        write(STDOUT_FILENO, txt, str_len(txt));
        txt = "is already an alias, replace its value with VALUE.\n";
        write(STDOUT_FILENO, txt, str_len(txt));
}

