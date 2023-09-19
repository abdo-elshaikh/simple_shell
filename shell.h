#ifndef __SHELL_H
#define __SHELL_H
/*---INCLUDES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>

/*---MACROS---*/
#define PROMPT "($) "
#define DELIMITER " \t\r\n\a\""
#define BUFFER_SIZE 1024

/* datastructures for alias and env */
#define MAX_ALIAS 50
#define MAX_ENV 50

/*---VARIABLES---*/
extern char **environ;
extern int last_command_status;
extern char *last_command;

typedef struct alias
{
    char *name;
    char *value;
} alias_t;

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
int shell_alias(char **args);

/* execute.c */
int new_process(char **args);

/* utils.c */
void free_line(char *line);
void free_line_array(char **line_array);
void free_args(char **args);

/* alias.c */
void print_alias(void);
void print_specefic_alias(char **args);
void define_alias(char *args);

/* replace_var.c */
char *replace_variables(char *line);

/* env.c */
void print_env(void);
void print_specefic_env(char **args);
void define_env(char *args);
void unset_env(char *args);

/* string_fun.c */
int str_cmp(char *s1, char *s2);
char *str_cat(char *s1, char *s2);
char *str_cpy(char *s1, char *s2);
char *str_dup(char *s1);

#endif