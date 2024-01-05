#include "shell.h"

/**
 * changeCurrentDirectory - changes the current working directory of the shell
 * @arguments: array of arguments
 */
void changeCurrentDirectory(char **arguments)
{
	char *directory = arguments[1];
	int result;

	/* If no argument is provided, change to HOME directory */
	if (directory == NULL)
	{
		directory = getEnvVariable("HOME");
		if (directory == NULL)
		{
			printString("cd: No HOME directory found\n");
			return;
		}
	}

	result = chdir(directory);
	if (result == -1)
	{
		perror("cd");
	}
}

