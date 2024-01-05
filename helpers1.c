#include "shell.h"

/**
 * custom_strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int custom_strlen(const char *str)
{
	int length = 0;

	if (!str)
		return (0);

	while (*str++)
		length++;
	return (length);
}

/**
 * custom_strcmp - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * Return: 0 if @s1 and @s2 are equal,
 *		 a negative value if @s1 is less than @s2,
 *		 or a positive value if @s1 is greater than @s2.
 */
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((int)(*str1) - (*str2));
}

/**
 * custom_strncmp - Compare two strings up to a specified length.
 * @str1: First string to compare.
 * @str2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters, negative value
 *		 if s1 is less than s2, or positive value if s1 is greater than s2.
 */
int custom_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char c1, c2;

	while (n-- > 0)
	{
		c1 = (unsigned char)*str1++;
		c2 = (unsigned char)*str2++;

		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break;
	}

	return (0);
}

/**
 * custom_strstr - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *custom_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			int j;

			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}
	return (NULL);
}

/**
 * custom_strchr - a function that locates a character in a string
 *
 * @str: pointer to our string array input
 * @c: character to locate from input array
 *
 * Return: first occurrence of character or null if not found
*/

char *custom_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	/**
	 * if c is '\0', you should return
	 * the pointer to the '\0' of the
	 * string str
	*/
	if (*str == c)
		return (str);
	/*return null if not found*/
	return (NULL);
}

