char *locate_path(void)
{
        int x;
        char **env = global_env, *path = NULL;

        while (*env)
        {
                if (str_ncmp(*env, "PATH=", 5) == 0)
                {
                        path = *env;
                        while (*path && x < 5)
                        {
                                path++;
                                x++;
                        }
                        return (path);
                }
                env++;
        }
        return (NULL);
}
