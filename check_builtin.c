#include "shell.h"

/**
 * isBuiltinCommand - checks if the command is a builtin
 * @arguments: the arguments array
 *
 * Return: 1 if the command is a builtin, 0 otherwise
 */
int isBuiltinCommand(char **arguments)
{
	if (!arguments[0])
		return (0);

	if (!custom_strcmp(arguments[0], "exit"))
		exitShell(arguments);
	else if (!custom_strcmp(arguments[0], "env"))
		printEnvironmentVariables();
	else if (!custom_strcmp(arguments[0], "setenv"))
		setEnvironmentVariable(arguments);
	else if (!custom_strcmp(arguments[0], "unsetenv"))
		unsetEnvironmentVariable(arguments);
	else if (!custom_strcmp(arguments[0], "help"))
		displayShellHelp();
	else if (!custom_strcmp(arguments[0], "cd"))
		changeCurrentDirectory(arguments);
	else if (!custom_strcmp(arguments[0], "clear"))
		clearTerminalScreen(arguments);
	else
		return (0);

	return (1);
}

