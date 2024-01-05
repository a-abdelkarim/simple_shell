#include "shell.h"

/**
 * clearTerminalScreen - clears the terminal screen.
 * @arguments: an array of arguments
 *
 * Return: 1 to continue executing,
 *		 or 0 to exit.
 */
int clearTerminalScreen(char **arguments)
{
	(void)arguments; /* avoid "unused parameter" warning */
	printString("\033[2J\033[H");
	return (1);
}

