#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int _strlen(const char *s);
int check_exit(const char *buffer);
int print_command(char *buffer);
void check_wait_status(int wstatus);
void execute(char *buffer, char *argVec[], char *envVec[]);

#endif
