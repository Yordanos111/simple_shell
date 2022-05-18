int builtin_handler(char **command, char *line)
{
        struct builtin builtin = {"env", "exit"};

        if (str_cmp(*command, builtin.env) == 0)
        {
                env_print();
                return (1);
        }
        else if (str_cmp(*command, builtin.exit) == 0)
        {
                exit_shell(command, line);
                return (1);
        }
        return (0);
}

