#ifndef SHELL_H_
#define SHELL_H_

/* add required libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* add definitions */
#define BUF_SIZE 1024
#define TOK_BUF_SIZE 128
#define TOK_DELIME "\t\r\n\a"
#define MAX_INPUT_LENGTH 1024

/* Include the global variable 'environ' */
extern char **environ;

/* Ffunction prototypes */
int new_process(char **args);
void free_args(char **args);
char **parse_command(char *command);
void change_directory(char *path);
void execute_shell_command(char *command);
void print_current_directory();

#endif
