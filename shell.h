#ifndef SHELL_H_
#define SHELL_H_

<<<<<<< HEAD
    /* add reqired lib */
    == == ==
    =
/* add required libraries*/
>>>>>>> 2ae9993b109d7b044b6c87e905e8a825ac69f97a
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* define delematers */
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

/* define // max number of letters to be supported */
#define MAX_CMD_NUM 1024

/* define // max number of letters to be supported */
#define MAX_CMD_LEN 100

/* define for command chaining */

/*Clearing the shell using escape sequences */
#define CLEAR_SCREEN "\033[2J\033[1;1H"
#define CLEAR_LINE "\033[2K"
#define CLEAR_SCREEN_LINE "\033[2J\033[1;1H\033[2K"
#define CLEAR_LINE_SCREEN "\033[2K\033[1;1H"

        /*Clearing prototypes */
    void clear();
void clearLine();
void clearScreenLine();
void clearLineScreen();

/* Printing the shell using escape sequences */

/* Include the global variable 'environ' */
extern char **environ;

/* getline prototypes */
char *read_line();
char **parse_input(char *input);
int execute_command(char **args);
void init_shell();

/* str_fun prototypes */
char *_strcpy(char *str, char *src);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str1);
char *_strcat(char *str1, char *str2);
char *_strrev(char *str);
char *_strchr(char *str, char c);
int _putchar(char c);
int _putstr(char *str);

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct s_passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    char **env;
    char **environ;
    struct s_history *history;
    struct s_alias *alias;
    int env_changed;
    int status;
    char **cmd_buf;
    char cmd_buf_type;
    int readfd;
    int histcount;
} passinfo_t;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct s_liststr
{
    int num;
    char *str;
    struct s_liststr *next;
} liststr_t;

/**
 * struct s_alias - singly linked list of aliases
 * @alias: the alias
 * @next: points to the next node
 */
typedef struct s_alias
{
    char *alias;
    struct s_alias *next;
} alias_t;

/**
 * struct s_history - singly linked list of history
 * @history: the history
 * @next: points to the next node
 */
typedef struct s_history
{
    char *history;
    struct s_history *next;
} history_t;

/* functions_prototype */
int new_process(char **args);
void free_args(char **args);
char **parse_command(char *command);
void change_directory(char *path);
void execute_shell_command(char *command);
void print_current_directory();

#endif
