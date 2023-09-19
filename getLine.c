#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t a = 0;
	size_t length = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		a = getline(buf, &length, stdin);
#else
		a = _getline(info, buf, &length);
#endif
		if (a > 0)
		{
			if ((*buf)[a - 1] == '\n')
			{
				(*buf)[a - 1] = '\0'; /* remove trailing newline */
				a--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = a;
				info->cmd_buf = buf;
			}
		}
	}
	return (a);
}

/**
 * get_input - get a line without the newline..
 * @info: for parameter struct..
 *
 * Return: bytes read..
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t b, c, len;
	ssize_t a = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	a = input_buf(info, &buf, &len);
	if (a == -1) /* EOF */
		return (-1);
	if (len)
	{
		c = b;
		p = buf + b;
		chain_check(info, buf, &c, b, len);
		while (c < len)
		{
			if (chain_test(info, buf, &c))
				break;
			c++;
		}
		b = c + 1;
		if (b >= len)
		{
			b = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (a);
}

/**
 * read_buf - this reads a buffer..
 * @info: the parameter struct..
 * @buf: buffer..
 * @i: size..
 *
 * Return: a..
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{

	ssize_t a = 0;

	if (*i)

		return (0);
	a = read(info->readfd, buf, READ_BUF_SIZE);
	if (a >= 0)
		*i = a;
	return (a);
}

/**
 * sigintHandler - Restricts ctrl-C..
 * @sig_num: for signal no..
 *
 * Return: void..
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * _getline - this gets next line of input from STDIN..
 * @info: for parameter struct..
 * @ptr: an address of pointer to buffer, preallocated or NULL..
 * @length: size of preallocated ptr buffer if not NULL.
 *
 * Return: d..
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t b, len;
	size_t m;
	ssize_t a = 0, d = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		d = *length;
	if (b == len)
		b = len = 0;
	a = read_buf(info, buf, &len);
	if (a == -1 || (a == 0 && len == 0))
		return (-1);
	c = _strchr(buf + b, '\n');
	m = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, d, d ? d + m : m + 1);
	if (!new_p) /* FAILED MALLOC */
		return (p ? free(p), -1 : -1);

	if (d)
		_strncat(new_p, buf + b, m - b);
	else
		_strncpy(new_p, buf + b, m - b + 1);

	d += m - b;
	b = m;
	p = new_p;

	if (length)
		*length = d;
	*ptr = p;
	return (d);
}
