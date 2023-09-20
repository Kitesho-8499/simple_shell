#ifndef _MAIN_H_
#define _MAIN_H_

#define DELIM " \n\t\a\r:"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

extern char **__environ;
int count_token(char *buffer, char *delim);
char **tokenize_line(char *buffer, char *delim, int token_no);
void _puts(char *str);
void exec_cmd(char **arg, char **argv, int count);
char *_getenv(const char *name);
char *_strchr(char *str, int c);
void print_PATH(char *envVar, char *delim);
char *_strdup(char *org);
void free_buffer(char **argv);

#include <limits.h>
#include <stdint.h>

#define HEX 16
#define DECIMAL 10

void _putchar_c(char c);
void _putchar(va_list a);
void print_str(va_list a);
void print_int(va_list a);
int _printf(const char *format, ...);
void unsignedNumberToString(uint64_t, int, char *);
void numberToString(int64_t, int, char *);

/**
 * struct Cspecs - structure for format specifiers
 * @cs: Letter representing format specifier
 * @f: function pointer
 * Description: Structure for printf format specifiers
 */

typedef struct Cspecs
{
	char cs;
	void (*f)();
} cs_t;


/**
 * struct builtins - it shows the builtins in our shell
 * @command: the command we entered
 * @func : function pointer to the actual command in the shell
 * that would be displayed
 * Description: structure for my_builtins
 */
typedef struct builtins
{
	char *command;
	void (*func)(char **);
} builtins;

/**
 * struct flags - struct to determine interactive vs non
 * interactive mode
 * @interactive: Mode type
 * Description: Struct for our mode type
 */
struct flags
{
	bool interactive;
};
struct flags flag;

int builtin_size(void);
void shell_exit(char **args);
void shell_cd(char **args);
void print_env(char **args);
void shell_help(char **args);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exec_builtin_commands(char **argv);
char **tokenize_PATH(char *envVar, char *delim);
char *find_path(char **pathTokens, char **argv);
char *append_to_directory(char *directory, char **argv, char *character);
int prompt(void);
void ctrl_C(int signum);
int print(char *var, int fd);
char *command_dir(char **cmd);

#endif
