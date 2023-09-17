#ifndef HEADER_h
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PROMPT "$ "
extern char **environ;
void get_env();
void check_env(char *input);
int str_search(char *str1, char *str2);
char *concat(char *str1, char *str2);
int streql(char  *str1, char *str2);
void run_command(int c, char **v, pid_t pid, char **tokens);
int shell(int c, char **v);
int shell2(int c, char **v);
ssize_t _getline(char **lineptr, size_t *n);
 char *_strtok(char *str, const char *delim);
#endif


