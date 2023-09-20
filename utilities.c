#include "shell.h"

/**
 * prompt - prints $ to let user know the program is ready
 * to takeinput
 * Return: Nothing
 */

int prompt(void)
{

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flag.interactive = 1;
	else
		return (0);
	if (flag.interactive)
		write(STDOUT_FILENO, "$ ", 2);
	return (1);
}

/**
 * _getenv - A function that gets env path passed to it
 * @name: Env name to get the path
 * Return: A pointer containing the path for the env passed to it
 */

char *_getenv(const char *name)
{
	int len, i = 0;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);

	while (__environ[i] != NULL)
	{
		if (_strncmp(name, __environ[i], len) == 0)
		break;
		i++;
	}
	return (__environ[i]);
}

/**
 * tokenize_PATH - Tokenizes the string into substrings using delim
 * @envVar: A pointer to the string to be tokeni
 * @delim: Array of characters containing delimiters for tokenization
 * Return: Array of tokenized substings
 */

char **tokenize_PATH(char *envVar, char *delim)
{
	char **tokenized_path = NULL;
	ssize_t num_substrings;
	char envVar_duplicate[1024];
	int i = 0;

	_strcpy(envVar_duplicate, envVar);
	num_substrings = count_token(envVar_duplicate, delim);

	tokenized_path = malloc(sizeof(char *) * num_substrings);
	if (tokenized_path == NULL)
	{
		perror("Malloc unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	tokenized_path = tokenize_line(envVar, delim, num_substrings);

	/*To remove the "PATH=" at the beginning of first token*/
	while (tokenized_path[i])
	{
		tokenized_path[i] = tokenized_path[i + 1];
		i++;
	}

	return (tokenized_path);
}

/**
 * append_to_directory - Append a '/' and command name to the end of a dir
 * @directory: Command directory where character and command is to be appended
 * @argv: Array of command passed by user
 * @character: Character to be appended to directory
 * Return: Pointer to newly created string
 */

char *append_to_directory(char *directory, char **argv, char *character)
{
	char *temp = NULL;
	int buff_size;

	buff_size = (_strlen(directory) + _strlen(argv[0] + 2));
	temp = malloc(sizeof(char) * buff_size);
	if (!temp)
		return (argv[0]);

	if (directory == NULL)
		return (argv[0]);

	_strcpy(temp, directory);
	_strcat(temp, character);
	_strcat(temp, argv[0]);

	return (temp);
}

/**
 * exec_cmd - Function to execute command
 * @arg: An array of commands to be executed
 * @argv: Argument vectors from main.c
 * @count: Argument counter
 * Return: Nothing
 */

void exec_cmd(char **arg, char **argv, int count)
{
	pid_t pid;
	char *cmd = NULL;
	int ch = '/', status;

	if (exec_builtin_commands(arg) == 0)
		return;
	if (_strchr(arg[0], ch) == NULL)
		cmd = append_to_directory("/bin", arg, "/");

/*if ((cmd_path = command_dir(arg)) == NULL)*/
/* _printf("%s: %i: %s: not found\n", argv[0], count, arg[0]);*/
/*free(cmd_path);*/
/*return;*/
	else
		cmd = arg[0];

	pid = fork();
	if (pid == -1)
	{
		perror("Unable to create child process\n");
		return;
	}
	else if (pid == 0)
	{
		if (execve(cmd, arg, __environ) == -1)
		{
			_printf("%s: %i: %s: not found\n", argv[0], count, arg[0]);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &status, WUNTRACED);
}
