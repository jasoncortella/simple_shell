#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(__attribute__((unused)) info_t info)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');  /* _puts does not add a newline */
	}
	return (0);
}

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 */
int _myexit(info_t info)
{
	char **arg_array;

	arg_array = info.argv;
	_puts("Exiting...\n");
	if (arg_array[1])  /* If there is an exit arguement */
		exit(_atoi(arg_array[1]));
	exit(0);
}


/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t info)
{
	char **arg_array;

	arg_array = info.argv;
	_puts("cd call works. Function not yet implemented \n");
	if (0)
		puts(*arg_array); /* temp att_unused workaround */
	return (0);
}


/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t info)
{
	char **arg_array;

	arg_array = info.argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
