#include "shell.h"

/**
 * main - Implements a simple shell.
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *userInput;
	char **arguments;
	int executionStatus;

	/* Register signal handlers */
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGTSTP, sigstop_handler);

	do {
		userInput = getUserInput();
		if (!userInput || !*userInput) /* EOF detected, exit the loop */
			break;

		arguments = tokenize_user_input(userInput);
		if (!arguments || !*arguments)
		{
			free(userInput);
			freeTokens(arguments);
			continue;
		}

		executionStatus = executeCommand(arguments);
		free(userInput);
		freeTokens(arguments);

		/* Set executionStatus to 1 to continue the loop */
		executionStatus = 1;
	} while (executionStatus);

	return (EXIT_SUCCESS);
}

