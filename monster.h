#ifndef _SHELL_H_
#define _SHELL_H_


#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *i_to_a(int num);
char **str_tok(char *line, char *delim);
char *get_loc(char *command);
int run(char **args, char **beginning);
void re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_list(list_t *head);
list_t *path_dir(char *path);

char **copy_env(void);
void free_env_copy(void);
char **get_env(const char *var);



int call_args(char **args, char **beginning, int *run_exe);
void line_handle(char **line, ssize_t read);
void var_replace(char **args, int *run_exe);
char *get_args(char *line, int *run_exe);

int exe_args(char **args, char **front, int *run_exe);
int args_handle(int *run_exe);
int check_args(char **args);
void free_args(char **args, char **beginning);
char **aliases_replace(char **args);

int str_len(const char *s);
char *str_cat(char *dest, const char *src);
char *str_ncat(char *dest, const char *src, size_t n);
char *str_cpy(char *dest, const char *src);
char *str_chr(char *s, char c);
int str_spn(char *s, char *accept);
int str_cmp(char *s1, char *s2);
int str_ncmp(const char *s1, const char *s2, size_t n);

int (*get_builtin(char *command))(char **args, char **beginning);
int exit_ay(char **args, char **beginning);
int env_ay(char **args, char __attribute__((__unused__)) **beginning);
int setenv_ay(char **args, char __attribute__((__unused__)) **beginning);
int unsetenv_ay(char **args, char __attribute__((__unused__)) **beginning);
int cd_ay(char **args, char __attribute__((__unused__)) **beginning);
int alias_ay(char **args, char __attribute__((__unused__)) **beginning);
int help_ay(char **args, char __attribute__((__unused__)) **beginning);


alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_link(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);


int write_error(char **args, int err);
char *err_env(char **args);
char *err_1(char **args);
char *err_exit_2(char **args);
char *err_cd_2(char **args);
char *err_syntax_2(char **args);
char *err_13(char **args);
char *err_37(char **args);


void all_help(void);
void alias_help(void);
void cd_help(void);
void exit_help(void);
void help_sos(void);
void env_help(void);
void setenv_help(void);
void unsetenv_help(void);
void his_help(void);


int file_command(char *file_path, int *exe_ret);

/* Global aliases linked list */
alias_t *aliases;

/* Global environemnt */
extern char **global_env;
/* Global program name */
char *app_name;
/* Global history counter */
int his_counter;


typedef struct list_s
{
        char *dir;
        struct list_s *next;
} list_t;


typedef struct builtin_s
{
        char *name;
        int (*f)(char **argv, char **front);
} builtin_t;


typedef struct alias_s
{
        char *name;
        char *value;
        struct alias_s *next;
} alias_t;


#endif
