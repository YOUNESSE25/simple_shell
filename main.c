#include "shell.h"
/**
 * main - initialize the variables
 * @argc: integer that indicates num arguments of the command line
 * @argv: array of pointers to arrays of character
 * @env: numb of values recived
 *
 * Return: int
 */
int main(int argc, char *argv[], char *env[])
{
	data_program data_struct = {NULL};
	data_program *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);
	signal(SIGINT, handle_ctrl_c);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}
/**
 * handle_ctrl_c - print prompt nline
 * @UNUSED: option of ptyp
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}
/**
 * inicialize_data - initialize structur
 * @data: pointer structur
 * @argc: integer that indicates num arguments of the command line
 * @argv: array of pointers to arrays of character
 * @env: numb of values recived
 */
void inicialize_data(data_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;
	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * sisifo - loop to show the prompt
 * @prompt: prompt
 * @data: loop to shows
 */
void sisifo(char *prompt, data_program *data)
{
	int errcode = 0;
	int strlen = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		errcode = strlen = gline(data);
		if (errcode == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (strlen >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{
				errcode = execute(data);
				if (errcode != 0)
					_print_error(errcode, data);
			}
			free_recurrent_data(data);
		}
	}
}
