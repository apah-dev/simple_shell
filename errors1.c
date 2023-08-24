#include "shell.h"

/**
 *_eputs - this will print an input string
 * @str: this is the string that will be printed
 */

void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - this writes the char c to stderr
 * @c: this the char to be print
 * Return: 1 when success and -1 on error.
 * Errno is appropriately set
 */

int _eputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putfd -this will write the char c to the file descriptor
 * @c: This the char to be printed
 * @fd: This is the file descriptor
 * Return: 1 when success and -1 on error.
 * Errno is appropriately set.
 */

int _putfd(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 *_putsfd - this will print an input string
 * @str: string to be printed
 * @fd: the file descriptor
 * Return: the number of chars put
 */

int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
