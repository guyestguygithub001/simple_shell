#include "shell.h"

/**
 * unset_alias - sets alias to string..
 * @info: parameter structures..
 * @str: string alias..
 *
 * Return: Always 0 if success, 1 if else
 */
int unset_alias(info_t *info, char *str)
{
	char *p, b;
	int retrn;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	b = *p;
	*p = 0;
	retrn = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = b;
	return (retrn);
}

/**
 * our_history - displays history list, one command by line, preceded..
 *              with line no. starts at 0.
 * @info: Struct. containing potential args. to maintain
 *        constant function prototype..
 *  Return: Always 0
 */
int our_history(info_t *info)
{
	print_list(info->history);
	return (0);
}


/**
 * our_alias - mimics the alias builtin (man alias)..
 * @info: Struct containing potential args. Used to maintain
 *          constant func prototype..
 *  Return: Always 0 if Successful..
 */
int our_alias(info_t *info)
{
	int a = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_list(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		p = _strchr(info->argv[a], '=');
		if (p)
			unset_alias(info, info->argv[a]);
		else
			print_list(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}



/**
 * set_alias - sets alias to string..
 * @info: for parameter struct..
 * @str: for string alias..
 *
 * Return: Always 0 if success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - to print an alias string..
 * @node: alias node..
 *
 * Return: Always 0 if success, 1 if else..
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
