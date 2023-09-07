#ifndef SHELL_H_C
#define SHELL_H_C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <signal.h>
#lnclude <errno.h>

#define BUF_SIZE 1024
#define TOK_BUF_SIZE 128
#define TOK_DELIME "\t\r\n\a"

extern char **environmevt;


typedef struct data {
    
}

#endif