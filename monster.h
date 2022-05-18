#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **global_env;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);		

/* handle built ins */
int check_er(char **cmd, char *buf);
void user_prompt_user(void);
void signal_handler(int m);
char **token(char *line);
char *path_test(char **path, char *command);
char *path_append(char *path, char *command);
int builtin_handler(char **command, char *line);
void exit_shell(char **command, char *line);

void env_print(void);

/* string handlers */
int str_cmp(char *s1, char *s2);
int str_len(char *s);
int str_ncmp(char *s1, char *s2, int n);
char str_dup(char *s);
char *str_chr(char *s, char c);

void run(char *cp, char **cmd);
char *locate_path(void);

/* helper function for efficient free */
void free_buff(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */
