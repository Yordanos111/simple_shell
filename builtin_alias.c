#include "monster.h"



void print_alias_val(alias_t alias)
{
	int lenght = str_len(alias->app_name) + str_len(alias->val) + 4;
	char *alias_str;

	alias_str = malloc(sizeof(char) * (length + 1));
	if (!alias_str)
		return;
	str_cpy(alias_str, alias->app_name);
	str_cat(alias_str, "='");
	str_cat(alias_str, alias->val);
	str_cat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_str, length);
	free(alias_str);
}



int alias_ay(char **args, char __attribute__((__unused__)) **beginning);
{
	int i, run_return = 0;
	char *val;
	alias_t *tmp = aliases;

	if (!args[0])
	{
		while(tmp)
		{
			print_alias_val(tmp);
			tmp = tmp->next;
		}
		return (run_return);
	}
	for (i = 0; args[i]; i++)
	{
		val = str_chr(args[i], '=');
		tmp = aliases;
		if (!val)
		{
			while (tmp)
			{
				if (str_cmp(args[i], tmp->app_name) == 0)
				{
					print_alias_val(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if (!tmp)
				run_return = write_error(args + i, 1);
		}
		else
			set_alias(args[i], val);
	}
	return (run_return);
}



char **aliases_replace(char **args)
{
	char *new_val;
	int i;
	alias_t *tmp;

	if (str_cmp(args[0], "alias") == 0)
		return(args);
	for (i = 0; args[i]; i++)
	{
		tmp = aliases;
		while (tmp)
		{
			if(str_cmp(srgs[i], tmp->app_name) == 0)
			{
				new_val = malloc(sizeof(char) * (str_len(tmp->val) + 1));
				if (!new_val)
				{
					free_mem(args, args);
					return (NULL);
				}
				str_cpy(new_val, tmp->val);
				free(args[i]);
				args[i] = new_val;
				i--;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (args);
}



void set_alias(char *var_name, char *val)
{
	char *new_val;
	int i, j ,len;
	alias_t *tmp = aliases;

	*val = '\0';
	val++;
	len = str_len(val) - str_spn(val, "'\"");
	new_val = malloc(sizeof(char) * (len + 1));
	if (!new_val)
		return;
	for (i = 0, j = 0; val[i]; i++)
	{
		if (val[i] != '\'' && val[i] != '"')
			new_val[j++] = val[i];
	}
	new_val[j] = '\0';
	while (tmp)
	{
		if (str_cmp(var_name, tmp->app_name) == 0)
		{
			free(tmp->val);
			tmp->val = new_val;
			break;
		}
	}
	if (!tmp)
		add_alias_end(&aliases, var_name, new_val);
}
