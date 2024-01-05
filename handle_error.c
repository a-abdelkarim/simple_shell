#include "shell.h"

/**
 * printString - Prints a string to the standard output stream
 * @string: The string to print
 *
 * Return: Void
 */
void printString(char *string)
{
	size_t length;
	ssize_t numWritten;

	length = custom_strlen(string);
	numWritten = write(STDOUT_FILENO, string, length);
	if (numWritten == -1)
	{
		perror("write");
	}
}

/**
 * printError - Prints an error message to the standard error stream
 * @errorMessage: The error message to print
 *
 * Return: Void
 */
void printError(char *errorMessage)
{
	size_t length;
	ssize_t numWritten;

	length = custom_strlen(errorMessage);
	numWritten = write(STDERR_FILENO, errorMessage, length);
	if (numWritten == -1)
	{
		perror("write");
	}
}

