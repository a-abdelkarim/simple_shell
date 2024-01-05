#include "shell.h"

/**
 * sigint_handler - Signal handler for SIGINT (Ctrl+C)
 * @signal_number: Signal number
 *
 * Return: Nothing
 */
void sigint_handler(int signal_number)
{
	(void) signal_number;
	custom_putchar('\n');
	prompt();
}

/**
 * sigquit_handler - Signal handler for SIGQUIT (Ctrl+\)
 * @signal_number: Signal number
 *
 * Return: Nothing
 */
void sigquit_handler(int signal_number)
{
	(void) signal_number;
	printError("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * sigstop_handler - Signal handler for SIGTSTP (Ctrl+Z)
 * @signal_number: Signal number
 *
 * Return: Nothing
 */
void sigstop_handler(int signal_number)
{
	(void) signal_number;
	printString("\n");
	prompt();
}

