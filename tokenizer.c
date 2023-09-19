#include "shell.h"

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, c, f, no_wrd = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
			(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			no_wrd++;
		if (no_wrd == 0)
			return (NULL);
	s = malloc((1 + no_wrd) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < no_wrd; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < c; f++)
			s[b][f] = str[a++];
		s[b][f] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow - splits strings to words. Repeat delimiters ignored
 * @d: the delimeter string
 * @str: the input string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int a, b, c, f, no_wrd = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			no_wrd++;

	if (no_wrd == 0)
		return (NULL);
	s = malloc((1 + no_wrd) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < no_wrd; b++)
	{
		while (is_delim(str[a], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < c; f++)
			s[b][f] = str[a++];
		s[b][f] = 0;
	}
	s[b] = NULL;
	return (s);
}
