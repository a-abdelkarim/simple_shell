#include "shell.h"

/**
 * exitShell - Exit the shell.
 * @arguments: Arguments.
 *
 * Return: Nothing.
 */
void exitShell(char **arguments)
{
	int exitStatus = 0;

	if (arguments[1] != NULL)
	{
	exitStatus = custom_atoi(arguments[1]);
	}

	freeTokens(arguments);
	freePreviousUserInput();
	exit(exitStatus);
}

