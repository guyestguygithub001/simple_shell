#include "shell.h"

/**
 * our_env - prints current environ..
 * @info: Struct. containing potential args. for maintaining..
 *          constant funct. prototype..
 * Return: Always 0
 */
int our_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of environ variable..
 * @info: Struct. containing potential args. to maintain..
 * @name: env var name
 *
 * Return: value..
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * our_setenv - Init new environ variable,
 *             or modify existing one..
 * @info: Struct. containing potential args. to maintain..
 *        constant function prototype..
 *  Return: Always 0
 */
int our_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * our_unsetenv - get rid of environment variable..
 * @info: Struct. containing potential args. to maintain..
 *        constant func. prototype..
 *  Return: Always 0
 */
int our_unsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * populate_env_list - populates env linked list..
 * @info: Struc. containing potential args. Used to maintain..
 *          constant func. prototype..
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
