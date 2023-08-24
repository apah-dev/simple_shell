#include "shell.h"

/**
 * _myhist - this displays the history list with one command by line.
 * 		Starting at 0 then precede with line numbers.
 * @info: This structure containing potential arguments.
 * 	 This is to maintain constant function prototype.
 *  Return: 0
 */

int _myhist(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - this willl set alias to the string
 * @info: this structures the parameter
 * @str: this is the string alias
 * Return: 0 on when success while 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - this will set alias to string
 * @info: thisstructures the parameter
 * @str: this is the string alias
 * Return: 0 on when success while 1 on error
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
 * print_alias - this prints an alias string
 * @node: this is an alias node
 * Return: 0 on when success while 1 on error
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

/**
 * _myalias - this will imitate the alias builtin
 * @info: this is the tructure containing potential arguments.
 * 	 This will maintain constant function prototype.
 *  Return: 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
