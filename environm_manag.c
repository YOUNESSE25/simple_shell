#include "shell.h"
/**
 * env_get_key - gets value environment
 * @key: the environment variable
 * @data: structur data
 * Return: pointer
 */
char *env_get_key(char *key, data_program *data)
{
	int i;
	int key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length)
				&& data->env[i][key_length] == '=')
			return (data->env[i] + key_length + 1);
	}
	return (NULL);
}
/**
 * env_set_key - overwrite value environment
 * @key: name variable
 * @value: new value
 * @data: structur data
 * Return: int
 */
int env_set_key(char *key, char *value, data_program *data)
{
	int i;
	int key_length = 0;
	int is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
				data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);
	if (is_new_key)
		data->env[i + 1] = NULL;
	return (0);
}
/**
 * env_remove_key - remove key
 * @key: key
 * @data: structur data
 * Return: int
 */
int env_remove_key(char *key, data_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
				data->env[i][key_length] == '=')
		{
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
				data->env[i - 1] = data->env[i];
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
/**
 * print_environ - print environement
 * @data: structur data
 */
void print_environ(data_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
