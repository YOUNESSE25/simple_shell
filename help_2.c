#include "shell.h"
/**
 * long_to_string - number to string
 * @number: number
 * @string: string buffer
 * @base: base of convrt number
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0;
	int innegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';
	if (string[0] == '-')
		innegative = 1;
	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[(cociente % base)];
		cociente /= base;
	}
	if (innegative)
		string[index++] = '-';
	string[index] = '\0';
	str_reverse(string);
}
/**
 * count_characters - count caracter in string
 * @string: pointer string
 * @character: string
 * Return: int
 */
int count_characters(char *string, char *character)
{
	int i = 0;
	int c = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			c++;
	}
	return (c);
}
