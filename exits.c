#include "shell.h"

/**
 **_strchr - this locates char in string..
 *@s: the string to be parsed..
 *@c: character to look for..
 *Return: (s) a pointer to the memory area s..
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncpy - copies string..
 *@dest: destination string to be copied..
 *@src: source string..
 *@n: amount of chars to be copied..
 *Return: concatenated strings..
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates 2 strings..
 *@dest: the first string..
 *@src: the second string..
 *@n: the amount of bytes to be maximally used..
 *Return: concatenated strings..
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}
