#include "shell.h"

/**
 * findCommandInPath - Looks for a cmd in directory in the PATH
 *				environment variable
 * @targetCommand: pointer to `targetCommand` string to look for.
 *
 * Return: pointer to string containing the full path (success) if it is found,
 *		 or NULL if it is not found (failure).
 */
char *findCommandInPath(char *targetCommand)
{
	struct stat fileSt;
	int statRes, i;
	char buffer[PATH_MAX_LENGTH], *path, *result, **directories;

	path = getPath();
	if (!path)
		return (NULL);

	directories = tokenize_input_string(path, PATH_SEPARATOR);
	if (!directories)
		return (NULL);

	for (i = 0; directories[i]; i++)
	{
		custom_memset(buffer, 0, PATH_MAX_LENGTH);
		custom_strcpy(buffer, directories[i]);
		custom_strcat(buffer, "/");
		custom_strcat(buffer, targetCommand);

		statRes = stat(buffer, &fileSt);

		if (statRes == 0 && S_ISREG(fileSt.st_mode) && (fileSt.st_mode & S_IXUSR))
		{
			freeTokens(directories);
			result = malloc(sizeof(char) * (strlen(buffer) + 1));

			if (!result)
				return (NULL);

			custom_strcpy(result, buffer);
			return (result);
		}
	}

	if (statRes == -1)
	freeTokens(directories);

	return (NULL);
}

