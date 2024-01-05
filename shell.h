#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* prompt.c */
void prompt(void);

/* get_user_input.c */
char *getUserInput(void);
void freePreviousUserInput(void);
/* read_user_input.c*/
void *readUserInput(void);

/* built-in functions */
int isBuiltinCommand(char **arguments);
int execute_buitlin(char *cmd, char **args);
void displayShellHelp(void);
void exitShell(char **arguments);
void changeCurrentDirectory(char **args);
int setEnvironmentVariable(char **arguments);
int unsetEnvironmentVariable(char **arguments);
int printEnvironmentVariables(void);
int clearTerminalScreen(char **args);

/* handle_signal.c */
void sigint_handler(int sig);
void sigquit_handler(int sig);
void sigstop_handler(int sig);

/* handle_execution.c */
int executeCommand(char **arguments);

/* string_parser.c */
char **tokenize_input_string(char *input_str, const char *delimiter);
char **tokenize_user_input(char *user_input);

/* get_envirnment.c */
char *getEnvVariable(const char *varName);

/* handle_path.c */
char *getPath(void);

/* find_cmd_in_path.c */
char *findCommandInPath(char *targetCommand);

/* free.c */
void freeError(char **args, char *arg);
void freeTokens(char **ptr);
void freePath(void);

/* handle_error.c */
void printString(char *string);
void printError(char *errorMessage);

/* helpers1.c */
int custom_strlen(const char *str);
int custom_strcmp(const char *str1, const char *str2);
int custom_strncmp(const char *str1, const char *str2, size_t n);
char *custom_strstr(char *haystack, char *needle);
char *custom_strchr(char *str, char c);

/* helpers2.c */
char *custom_strcpy(char *destination, char *source);
char *custom_strcat(char *destination, const char *source);
char *custom_strdup(const char *str);
int custom_putchar(char c);
unsigned int custom_strspn(char *s, char *accept);

/* helpers3.c */
int custom_atoi(const char *str);
char *custom_memset(char *s, char b, unsigned int n);
char *custom_memcpy(char *dest, char *src, unsigned int n);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *custom_calloc(unsigned int nmemb, unsigned int size);

#endif
