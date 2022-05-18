int check_er(char **cmd, char *buff)
{
        if (handle_builtin(cmd, buff))
                return (1);
        else if (**cmd == '/')
        {
                run(cmd[0], cmd);
                return (1);
        }
        return (0);
}

