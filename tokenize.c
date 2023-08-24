#include "shell.h"
/**
 * tokenize - separate the string
 * @data: pointer program
 */
void tokenize(data_program *data)
{
	char *delim = " \t";
	int i, j, l, c = 2;

	l = str_length(data->input_line);
	if (l)
	{
		if (data->input_line[l - 1] == '\n')
			data->input_line[l - 1] = '\0';
	}
	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (data->input_line[i] == delim[j])
				c++;
		}
	}
	data->tokens = malloc(c * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delim));
	data->command_name = str_duplicate(data->tokens[0]);

	while (data->tokens[i++])
		{
			data->tokens[i] = str_duplicate(_strtok(NULL, delim));
		}
}
