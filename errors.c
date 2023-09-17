#include "shell.h"

/**
 * _eputchar - this writes char c to stderr..
 * @c: char to print..
 *
 * Return: If successful 1..
 * On error, -1 is returned, and errno is set appropriately..
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_eputs - prints string input..
 * @str: for string to be printed..
 *
 * Return: void..
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 *_putsfd - to print input string..
 * @str: string to print..
 * @fd: filedescriptor to write to..
 *
 * Return: the no. of chars put..
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _putfd - writes the character c to given fd..
 * @c: to print char..
 * @fd: filedescriptor to write into..
 *
 * Return: If Successful 1..
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
