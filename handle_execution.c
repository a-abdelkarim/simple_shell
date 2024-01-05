#include "shell.h"

/**
 * executeCommand - Execute a command with arguments.
 * @arguments: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int executeCommand(char **arguments)
{
	pid_t processID;
	int exitStatus = 0;
	char *commandPath, *environmentVariables[2];

	if (arguments == NULL || *arguments == NULL)
		return (exitStatus);

	if (isBuiltinCommand(arguments))
		return (exitStatus);

	processID = fork();

	if (processID < 0)
	{
		printError("fork");
		return (1);
	}

	if (processID == -1)
	{
		perror(arguments[0]);
		freeTokens(arguments);
		freePreviousUserInput();
	}

	if (processID == 0)
	{
		environmentVariables[0] = getPath();
		environmentVariables[1] = NULL;
		commandPath = NULL;

		if (arguments[0][0] != '/')
			commandPath = findCommandInPath(arguments[0]);

		if (commandPath == NULL)
			commandPath = arguments[0];

		if (execve(commandPath, arguments, environmentVariables) == -1)
		{
			perror(arguments[0]);
			freeTokens(arguments);
			freePreviousUserInput();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(processID, &exitStatus, WUNTRACED);
		} while (!WIFEXITED(exitStatus) && !WIFSIGNALED(exitStatus));
	}

	return (exitStatus);
}

