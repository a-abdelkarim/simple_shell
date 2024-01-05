#include "shell.h"

/**
 * displayShellHelp - displays help information for built-in commands
 */
void displayShellHelp(void)
{
	printString("\nShell Version 1.0.0\n\n");
	printString("Usage: ./hsh\n\n");
	printString("Shell built-in commands:\n\n");
	printString("help\t\tDisplay this help information\n\n");
	printString("cd [dir]\tChange the current working directory\n\n");
	printString("env\t\tDisplay the environment variables\n\n");
	printString("setenv\t\tSet an environment variable\n\n");
	printString("unsetenv\tUnset an environment variable\n\n");
	printString("exit\t\tExit the shell\n\n");
}

