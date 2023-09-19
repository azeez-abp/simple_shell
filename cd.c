#include "header.h"

/**
 *clean_cd - clearing memo
 *@dir_info: directory info
 *@oldpwd:old dir
 *@arg: the token of input console
 *Return: 0 successful, else error
 */
int clean_cd(char *oldpwd, char **args)
{
	char *dir_info_key;
	char *dir_info_val;
	char *pwd;

	pwd = NULL;

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);
	dir_info_key = "OLDPWD";
	dir_info_val = oldpwd;

	if (_setenv(dir_info_key, dir_info_val) == -1)
		return (-1);
	dir_info_key = "PWD";
	dir_info_val = pwd;

	if (_setenv(dir_info_key, dir_info_val) == -1)
		return (-1);
	if (args[1] && args[1][0] == '-' && args[1][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
/**
 * _cd - Changes the current directory of the shellby process.
 * @args: An array of arguments.
 * Return:
 *	 If the given string is not a directory - 2.
 *	 If an error occurs - -1.
 *	 Otherwise - 0.
 */
int _cd(char **args)
{

	char *oldpwd = NULL;
	struct stat dir;
	char *dir_;
	char **genv;

	oldpwd = getcwd(oldpwd, 0);
	printf("fasd");
	if (!oldpwd)
		return (-1);

	if (args[1])
	{
		if (*(args[1]) == '-' || _strncmp(args[1], "--", _strlen(args[1])) == 0)
		{
			if ((args[1][1] == '-' && args[1][2] == '\0') ||
			    args[1][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
				{
					genv = _getenv("OLDPWD");
					dir_ = _strtok(*(genv + 0), "=");
					dir_ = _strtok(NULL, "=");
					(chdir(dir_));
				}
			}
			else
			{
				free(oldpwd);
				return (2);
				/*Not a dir*/
			}
		}
		else
		{
			if (stat(args[1], &dir) == 0 && S_ISDIR(dir.st_mode) && ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[1]);
			else
			{
				free(oldpwd);
				return (2);
				/*invalid dir*/
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
		{
			genv = _getenv("HOME");
			dir_ = _strtok(*(genv + 0), "=");
			dir_ = _strtok(NULL, "=");
			(chdir(dir_));
		}
	}

	clean_cd(oldpwd, args);
	return (0);
}

