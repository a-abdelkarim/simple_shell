#include "shell.h"

/**
 * readUserInput - Read input from the standard input.
 *
 * Return: The string entered by the user.
 */
void *readUserInput(void)
{
	static char inputBuffer[BUFFER_SIZE];
	static int bufferPosition, bufferSize;
	char *userInput = NULL;
	char currentCharacter;
	int inputLength = 0;

	while (1)
	{
		if (bufferPosition >= bufferSize)
		{
			bufferSize = read(STDIN_FILENO, inputBuffer, BUFFER_SIZE);
			bufferPosition = 0;
			if (bufferSize == 0)
				return (userInput);
			else if (bufferSize < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		currentCharacter = inputBuffer[bufferPosition];

		bufferPosition++;

		if (currentCharacter == '\n')
		{
			userInput = realloc(userInput, inputLength + 1);
			userInput[inputLength] = '\0';
			return (userInput);
		}
		else
		{
			userInput = realloc(userInput, inputLength + 1);
			userInput[inputLength] = currentCharacter;
			inputLength++;
		}
	}
}

