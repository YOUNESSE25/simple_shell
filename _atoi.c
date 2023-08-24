#include "shell.h"
/**
 * _atoi - convert str to int
 * @s: pointer str
 * Return: int
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	int output, i, flag = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign = -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			number *= 10;
			number += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -number;
	else
		output = number;
	return (output);
}
