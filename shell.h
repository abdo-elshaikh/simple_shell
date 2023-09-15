#ifndef __SHELL_H
#define __SHELL_H
/*---INCLUDES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>

/*---MACROS---*/
#define PROMPT "($) "
#define DELIMITER " \t\r\n\a\""
#define BUFFER_SIZE 1024

/*---VARIABLES---*/
extern char **environ;

/* Builtin commands
typedef int (*builtin_func)(char **);
typedef struct builtin_command {
    char *name;
    builtin_func func;
} builtin_command;
*/

/*---PROTOTYPES---*/
/* main.c */
void shell_interactive(void);
void shell_no_interactive(void);

/* shell intractive.c */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);

/* shell_no_interactive.c */
char *read_stream(void);

/* buildins.c */
int shell_cd(char **args);
int shell_exit(char **args);
int shell_help(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);

/*other builtins*/
int shell_pwd(char **args);
int shell_echo(char **args);
int shell_clear(char **args);

/* execute.c */
int new_process(char **args);

/* utils.c */
void free_line(char *line);
void free_line_array(char **line_array);
void free_args(char **args);

#endif