#include "shell.h"

/**
 * is_delim - checks if char. is delimeter..
 * @c: char check..
 * @delim: for delimeter string..
 * Return: 1 if true, 0 if not true..
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * interactive - true if shell is in interactive mode..
 * @info: for struct address..
 *
 * Return: 1 if interactive mode, 0 else..
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_atoi - converts a string to int..
 *@s: the string to convert..
 *Return: 0 if no int in string, converted no. else.
 */

int _atoi(char *s)
{
	int a, symbol = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			symbol *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (symbol == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 *_isalpha - checks for alphabet chars..
 *@c: char input..
 *Return: 1 if c is an alphabet, 0 if else..
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
