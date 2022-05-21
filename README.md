# Our own simple shell
This is our group owned simple shell in C language.

### About
Shell is a user interface to use the services of a computer. It can be a command-line interface –the one we will build- or graphical user interface, like regular software such as Windows Office.

### Compilation
This simple shell is compiled with:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
### Output
This program have exact same output as sh as well as the exact same error output. The only difference is when it prints an error, the name of the program is equivalent to argv[0].

#### Example of error with sh:
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
#### Error with our program:
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
### Testing
#### Our shell work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
#### But also in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
### Examples
$ /bin/pwd
/home/vagrant/shell
$ ls -la
total 108**
* -rw-r--r-- 1 abel 22691  487 May 5 10:10 _dollar_special.c
* -rw-r--r-- 1 abel 22691  824 May 5 10:23 _get_history_lines_count.c
* -rw-r--r-- 1 abel 22691  363 May 5 10:30 _getenv.c* 
* -rw-r--r-- 1 abel 22691  818 May 5 10:39 _handle_var_replacement.c
* -rw-r--r-- 1 abel 22691 1745 May 5 10:45 _help.c
* -rw-r--r-- 1 abel 22691 1587 May 5 11:06 _history.c
* -rw-r--r-- 1 abel 22691  750 May 5 11:15 _own_memory.c
* -rw-r--r-- 1 abel 22691  232 May 5 11:24 _puts.c
* -rw-r--r-- 1 abel 22691  351 May 5 11:36 _strcpy.c
* -rw-r--r-- 1 abel 22691  448 May 5 11:43 _strncpy.c
* -rw-r--r-- 1 abel 22691 1327 May 5 11:59 _strtok.c
* -rw-r--r-- 1 abel 22691  491 May 5 12:19 _write_history.c
* -rw-r--r-- 1 abel 22691  158 May 5 12:33 AUTHORS
* -rw-r--r-- 1 abel 22691 3978 May 6 11:15 builtins.c
* -rw-r--r-- 1 abel 22691 3934 May 6 11:16 f_alias_list.c
* -rw-r--r-- 1 abel 22691 1083 May 6 11:16 f_builtin_utils.c
* -rw-r--r-- 1 abel 22691 3018 May 6 11:16 f_command_handlers.c
* -rw-r--r-- 1 abel 22691  754 May 6 11:14 f_error.c
* -rw-r--r-- 1 abel 22691 1372 May 6 11:15 f_exit.c
* -rw-r--r-- 1 abel 22691 1910 May 6 11:15 f_handle_builtins.c
* -rw-r--r-- 1 abel 22691  502 May 6 11:14 f_handle_comment.c
* -rw-r--r-- 1 abel 22691  316 May 6 11:16 f_handle_enter.c
* -rw-r--r-- 1 abel 22691 4138 May 6 11:21 f_handle_shell_logical_operators.c
* -rw-r--r-- 1 abel 22691 1271 May 7 11:21 f_linked_lists.c
* -rw-r--r-- 1 abel 22691 1399 May 7 11:19 f_memory.c
* -rw-r--r-- 1 abel 22691  727 May 7 11:17 f_special.c
* -rw-r--r-- 1 abel 22691 1809 May 7 11:17 f_strings.c
* -rw-r--r-- 1 abel 22691 1238 May 7 11:17 f_strings_creations.c
* -rw-r--r-- 1 abel 22691 1002 May 7 11:18 f_strings2.c
* -rw-r--r-- 1 abel 22691 2156 May 7 11:18 main.c
* -rw-r--r-- 1 abel 22691 1752 May 7 11:37 man_1_simple_shell
* -rw-r--r-- 1 abel 22691 2657 May 7 11:37 README.md
* -rw-r--r-- 1 abel 22691 4088 May 7 11:25 shell.h
$ Eth5 
* ./hsh: No such file or directory
### Authors
Yordanos Eshetu and Amanuel Paulos.
