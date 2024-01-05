#include "shell.h"

/**
 * freeError - frees allocated pointers following system error
 * @args: pointer to a pointer to an array of pointers
 * @arg: pointer to a pointer to an array of characters
 *
 * Return: void.
 */
void freeError(char **args, char *arg)
{
	int index;

	for (index = 0; args[index]; index++)
		free(args[index]);
	free(args);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * freeTokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void freeTokens(char **ptr)
{
	int index;

	for (index = 0; ptr[index]; index++)
		free(ptr[index]);
	free(ptr);
}

/**
 * freePath - Frees the global variable containing the PATH environment
 *			  variable value
 *
 * Return: Nothing
 */
void freePath(void)
{
	if (environ != NULL)
	{
		size_t index = 0;

		while (environ[index] != NULL)
		{
			if (custom_strncmp(environ[index], "PATH=", 5) == 0)
			{
				free(environ[index]);
				environ[index] = NULL;
				break;
			}
			index++;
		}
	}
}

