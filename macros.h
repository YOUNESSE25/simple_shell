#ifndef HELPERS_H
#define HELPERS_H

#define PROMPT_MSG "$"
#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024
#define HELP_CD_MSG "cd=\n"\
	"cd:\tcd [dir]\n\n"\
	"   change directory of wrk.\n\n"\
	"   if no argument whith cd tne command will be anterpreted as\n"\
	"   cd $HOME.\n"\
	"   if the argument help is - (cd -), the command will be interpreted as\n"\
	"   cd $OLDPWD.\n\n"
#define HELP_EXIT_MSG "exit=\n"\
	"exit:\texit [STATUS]\n\n"\
	"   exit simple-shell.\n\n"\
	"   exits the shell whuth N status\n\n"
#define HELP_ENV_MSG "env=\n"\
	"env:\tenv \n\n"\
	"   print environment.n\n\n"\
	"   the env cmd print a complete liste of environment variables.\n\n"
#define HELP_SETENV_MSG "setenv=\n"\
	"setenv:\tsetenv VARIABLE VALUE\n\n"\
	"   Change or add environment variable.\n\n"\
	"   init new environment variable or modifyexisting one\n"\
	"   when not corect number print error msg.\n\n"
#define HELP_UNSETENV_MSG "unsetenv=\n"\
	"unsetenv:\tunsetenv VARIABLE\n\n"\
	"   the unsetenv func del variable from the environment.\n\n"\
	"   wen not correct numbers of arguments print error msg.\n\n"
#define HELP_MSG "help=\n"\
	"help:\thelp [BULTIN_NAME]\n\n"\
	"   show info about builtin commands.\n\n"\
	"   show summaries of builtin cmds if BULTIN_NAME is \n"\
	"   gives and specified detailed help commands maching BULTIN_NAME,\n\n"

#endif
