#include "shell.h"
/**
 * builtins_list - search and execute
 * @data: structur data
 * Return: int
 */
int builtins_list(data_program *data)
{
	int iterator;
	bloc_info options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	for (iterator = 0; options[iterator].bloc_info != NULL; iterator++)
	{
		if (str_compare(options[iterator].bloc_info, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
