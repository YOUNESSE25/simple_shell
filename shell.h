#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include "macros.h"

/**
 * struct info - structur program data
 * @program_name: the name of the program
 * @input_line: pointer input (_getline)
 * @command_name: pointer first command
 * @exec_counter: numb exec comd
 * @file_descriptor: file description comand
 * @tokens: pointer array input
 * @env: copy environ
 * @alias_list: array pointer aliases
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_program;
/**
 * struct builtin - struct builtins
 * @builtin: builtin name
 * @function: associated func colled for builtin
 */
typedef struct builtin
{
	char *builtin;
	int (*function)(data_program *data);
} builtin;

void inicialize_data(data_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_program *data);
void handle_ctrl_c(int opr UNUSED);
int builtin_exit(data_program *data);
int builtin_cd(data_program *data);
int set_work_directory(data_program *data, char *new_dir);
int builtin_help(data_program *data);
int builtin_alias(data_program *data);
int gline(data_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
void expand_variables(data_program *data);
void expand_alias(data_program *data);
int buffer_add(char *buffer, char *str_to_add);
void free_array_of_pointers(char **directories);
void free_recurrent_data(data_program *data);
void free_all_data(data_program *data);
void tokenize(data_program *data);
char *_strtok(char *line, char *delim);
int execute(data_program *data);
int builtins_list(data_program *data);
char **tokenize_path(data_program *data);
int find_program(data_program *data);
int builtin_env(data_program *data);
int builtin_set_env(data_program *data);
int builtin_unset_env(data_program *data);
char *env_get_key(char *name, data_program *data);
int env_set_key(char *key, char *value, data_program *data);
int env_remove_key(char *key, data_program *data);
void print_environ(data_program *data);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_program *data);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *str1, char *str2, int num);
char *str_concat(char *str1, char *str2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
int print_alias(data_program *data, char *alias);
char *get_alias(data_program *data, char *alias);
int set_alias(char *alias_string, data_program *data);

#endif
