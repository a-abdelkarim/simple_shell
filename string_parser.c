#include "shell.h"

/**
 * tokenize_input_string - Parsing user input into arguments
 *						 by splitting an array string into tokens using a delimiter.
 * @input_str: The string to be tokenized.
 * @delimiter: The delimiter used to split the string.
 *
 * Return: An array of pointers to the tokens,
 *		 or NULL if an error occurs.
 */
char **tokenize_input_string(char *input_str, const char *delimiter)
{
	char *current_token = NULL;
	char **result_tokens = NULL;
	int token_count = 0;

	current_token = strtok(input_str, delimiter);
	while (current_token)
	{
		result_tokens = realloc(result_tokens, sizeof(char *) * (token_count + 1));
		if (result_tokens == NULL)
			return (NULL);

		result_tokens[token_count] = malloc(custom_strlen(current_token) + 1);
		if (!(result_tokens[token_count]))
			return (NULL);

		custom_strcpy(result_tokens[token_count], current_token);
		current_token = strtok(NULL, delimiter);
		token_count++;
	}

	/* Increase the size of the array */
	result_tokens = realloc(result_tokens, (token_count + 1) * sizeof(char *));
	if (!result_tokens)
		return (NULL);

	result_tokens[token_count] = NULL;
	return (result_tokens);
}

/**
 * tokenize_user_input - Split input str to tokens with tokenize_input_string()
 * @user_input: The user input string to be tokenized.
 *
 * Return: An array of pointers to the tokens, or NULL if an error occurs.
 */
char **tokenize_user_input(char *user_input)
{
	char **tokens = NULL;
	char *temp_str = NULL;

	temp_str = custom_strdup(user_input);
	if (temp_str == NULL)
	{
		printString("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize_input_string(temp_str, " \t\r\n\a");
	free(temp_str);

	return (tokens);
}

