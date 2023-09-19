#include "shell.h"

/**
 * print_error - prints an error message..
 * @info: parameter & return info struct..
 * @estr: string that contains specified error type..
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error..
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - func. prints a decimal (integer) number (base 10).
 * @input: input..
 * @fd: filedescriptor to write into..
 *
 * Return: no. of chars printed..
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, sum = 0;
	unsigned int _br, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_br = -input;
		__putchar('-');
		sum++;
	}
	else
		_br = input;
	current = _br;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_br / a)
		{
			__putchar('0' + current / a);
			sum++;
		}
		current %= a;
	}
	__putchar('0' + current);
	sum++;

	return (sum);
}

/**
 * _erratoi - this converts a string to an int..
 * @s: the string to convert..
 * Return: 0 if no int in string, converted int else
 *       -1 on error..
 */
int _erratoi(char *s)
{
	int a = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;  /* TODO: why this allows main return 255? */
	for (a = 0;  s[a] != '\0'; a++)
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			output *= 10;
			output += (s[a] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}

/**
 * remove_comments - funct replaces first instance of '#' with '\0'
 * @buf: address of string to modify..
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}

/**
 * convert_number - converter function, a clone of itoa.
 * @num: no..
 * @base: base..
 * @flags: arg flags.
 *
 * Return: string..
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
