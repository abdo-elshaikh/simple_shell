#ifndef __HSH_H
#define __HSH_H

/* include lib */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

/* define */
#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\n\a"
#define MAX_HISTORY_SIZE 100

/* environment*/
extern char **environ;

/**
 * struct alias - struct to alias
 * @head: head of struct
 * @command: commands
 * @next: poiner to next
 */
typedef struct Alias
{
	char *name;
	char *command;
	struct Alias *next;

} Alias;

/* Function prototypes */
int main(void);
void start_shell_interactive(void);
void start_shell_non_interactive(void);
int execute_command(char **args);
int change_directory(char **args);
int exit_shell(char **args);
int print_environment(char **args);
int show_help(char **args);
char **split_input_line(char *line);
char *read_user_input(void);
char *read_stream_input(void);
void execute_shell(void);
char **parse_command(char *command);
int new_process(char **args);
void free_args(char **args);
void set_environment(char *var, char *value);
char *get_environment(char *var);
void unset_environment(char *var);
char *get_line(void);
int pipe_commands(char **first_command, char **second_command);
int redirect_output(char *filename);
int redirect_input(char *filename);
void handle_signal(int signo);
Alias *add_alias(Alias *head, const char *name, const char *command);
const char *find_alias(const Alias *head, const char *name);
void add_directory_to_path(char *directory);
void remove_directory_from_path(char *directory);
void handleChildProcess1(int pipe_fd[], char **command1);
void handleChildProcess2(int pipe_fd[], char **command2);
void closePipe(int pipe_fd[]);
#endif
