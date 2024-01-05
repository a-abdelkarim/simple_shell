#include "shell.h"

/**
 * getPath - Returns the value of the PATH environment variable.
 *
 * Return: Pointer to the value of $PATH.
 */
char *getPath(void)
{
	return (getEnvVariable("PATH"));
}

