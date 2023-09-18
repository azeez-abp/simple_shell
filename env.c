#include "header.h"

/**
 * setenv - set enviroment variable
 * @key: is the key
 * @value: is the value
 *
 */
int  setenvfunc(char *key, char *val)
{
	if (key[0])
	{
		int haset;

		haset = _setenv(key, val);

		if (haset != 0)
		{
			printf("Error!\n");
		}
	}

	return (0);
}

/**
 * unsetenv - set enviroment variable
 * @key: is the key
 *
 */
void unsetenvfunc(char *key)
{
	if (key[0])
	{
		int haset;

		haset = _unsetenv(key);

		if (haset <  0)
		{
			printf("Error!\n");
		}
	}
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @str: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(char *str)
{
	int index, len;

	len = _strlen(str);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(str, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
/**
 * _setenv - Changes or adds an environmental variable to the PATH.
 * @key: string use to identify the env
 * @val: the value of the env
 * Return: 0 success , -1
 */
int _setenv(char *key, char *val)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int index;

	if (!key || !val)
		return (-1);

	new_value = malloc(_strlen(key) + 1 + _strlen(val) + 1);
	if (!new_value)
		return (-1);
	_strcpy(new_value, key);
	_strcat(new_value, "=");
	_strcat(new_value, val);

	env_var = _getenv(key);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return  (-1);
	}

	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];

	/*free(environ);*/
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * _unsetenv - Deletes an environmental variable from the PATH.
 * @key: String of key to use in setting env
 * Description: args[1] is the PATH variable to remove
 * Return: If an error occurs - -1.
 *	 Otherwise - 0.
 */
int _unsetenv(char *key)
{
	char **env_var, **new_environ;
	size_t size;
	int index, index2;

	if (!key)
		return (-1);
	env_var = _getenv(key);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (-1);
	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++;
	}
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}
