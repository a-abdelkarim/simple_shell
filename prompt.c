#include "shell.h"

/**
 * prompt - show shell prompt to stream.
 *
 * Return: void.
 */
void prompt(void)
{
	printString(PROMPT);
	fflush(stdout);
}

