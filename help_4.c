#include "shell.h"
/**
 * str_length - get a length string
 * @string: pointer str
 * Return: int length
 */
int str_length(char *string)
{
	int l = 0;

	if (string == NULL)
		return (0);
	while (string[l++] != '\0')
	{
	}
	return (--l);
}
/**
 * str_duplicate - duplicates an str
 * @string: string
 * Return: pointer
 */
char *str_duplicate(char *string)
{
	char *result;
	int length;
	int i;

	if (string == NULL)
		return (NULL);
	length = str_length(string) + 1;
	result = malloc(sizeof(char) * length);
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length; i++)
	{
		result[i] = string[i];
	}
	return (result);
}
/**
 * str_compare - compare strings
 * @str1: shorter string
 * @str2: longest string
 * @num: caracters number
 * Return: 1 or 0
 */
int str_compare(char *str1, char *str2, int num)
{
	int i;

	if (str1 == NULL && str2 == NULL)
		return (1);
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (num == 0)
	{
		if (str_length(str1) != str_length(str2))
			return (0);
		for (i = 0; str1[i]; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < num; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
}
/**
 * str_concat - concatenates 2 strings
 * @str1: string
 * @str2: string
 * Return: pointer
 */
char *str_concat(char *str1, char *str2)
{
	char *result;
	int l1 = 0, l2 = 0;

	if (str1 == NULL)
		str1 = "";
	l1 = str_length(str1);
	if (str2 == NULL)
		str2 = "";
	l2 = str_length(str2);
	result = malloc(sizeof(char) * (l1 + l2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (l1 = 0; str1[l1] != '\0'; l1++)
		result[l1] = str1[l1];
	free(str1);
	for (l2 = 0; str2[l2] != '\0'; l2++)
	{
		result[l1] = str2[l2];
		l1++;
	}
	result[l1] = '\0';
	return (result);
}
/**
 * str_reverse - string revers
 * @string: pointer
 */
void str_reverse(char *string)
{
	int i = 0;
	int l;
	char k;

	l = str_length(string) - 1;
	while (i < l)
	{
		k = string[i];
		string[i++] = string[l];
		string[l--] = k;
	}
}
