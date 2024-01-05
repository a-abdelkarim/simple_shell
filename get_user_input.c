#include "shell.h"

static char *previousUserInput;

/**
 * getUserInput - Read a line of input from the user.
 *
 * Return: Pointer to a buffer containing the user's input.
 */
char *getUserInput(void)
{
	char *inputBuffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead;

	do {
		/* Print the shell prompt */
		prompt();

		/* Get a line of input from the user */
		bytesRead = getline(&inputBuffer, &bufferSize, stdin);

		/* Check for EOF or error */
		if (bytesRead == -1)
		{
			free(inputBuffer);
			printString("\n");
			return (NULL);
		}

		/* Remove trailing newline character */
		inputBuffer[bytesRead - 1] = '\0';

	} while (inputBuffer[0] == '\0' || isspace(inputBuffer[0]));

	/* Update previousUserInput to point to the new input */
	previousUserInput = inputBuffer;
	return (inputBuffer);
}

/**
 * freePreviousUserInput - Free the memory allocated for the recent input.
 *
 * This function should be called after the input string is no longer needed.
 */
void freePreviousUserInput(void)
{
	free(previousUserInput);
	previousUserInput = NULL;
}

