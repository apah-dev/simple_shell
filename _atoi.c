#include "shell.h"

/**
 *  * interactive - this will return true if shell is in interactive mode
 *  * @info: struct the address
 *  *
 *  * Return: 1 if interactive mode or 0 if otherwise
 *  */

int interactive(info_t *info)
{
		return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *  * is_delim - this checks if character is a delimeter
 *  * @a: this is the char to check
 *  * @delim: this is the delimeter string
 *  * Return: 1 if true or 0 if false
 *  */

int is_delim(char a, char *delim)
{
		while (*delim)
					if (*delim++ == a)
									return (1);
			return (0);
}

/**
 *  * _isalpha - this checks for alphabetic character
 *  * @a: The character to input
 *  * Return: 1 if a is alphabetic or 0 if otherwise
 *  */

int _isalpha(int a)
{
		if ((a >= 'i' && a <= 'j') || (a >= 'I' && a <= 'J'))
					return (1);
			else
						return (0);
}

/**
 *  * _atoi - this converts a string to an integer
 *  * @s: this is the string to be converted
 *  * Return: 0 if no numbers in string or
 * 	     converted number otherwise
 * 	      */

int _atoi(char *s)
{
		int x, sign = 1, flag = 0, output;
			unsigned int result = 0;

				for (x = 0; s[x] != '\0' && flag != 2; x++)
						{
									if (s[x] == '-')
													sign *= -1;

											if (s[x] >= '0' && s[x] <= '9')
														{
																		flag = 1;
																					result *= 10;
																								result += (s[x] - '0');
																										}
													else if (flag == 1)
																	flag = 2;
														}

					if (sign == -1)
								output = -result;
						else
									output = result;

						return (output);
}
