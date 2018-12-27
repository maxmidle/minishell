#include "minishell.h"

char	*tilde(char *command, char **environ)
{
	int i;
	int y;
	int j;
	char *str;

	i = 0;
	y = 0;
	while (environ[y] && !(ft_strstr(environ[y], "HOME=")))
		y++;
	if (!environ[y])
		return (command);
	j = ft_strlen(environ[y]) - 5;
	str = ft_strnew(ft_strlen(command) + j);
	while (command[i] != '~')
	{
		str[i] = command[i];
		i++;
	}
	j = 0;
	while(environ[y][j + 5])
	{
		str[i + j] = environ[y][j + 5];
		j++;
	}
	while (command[i])
	{
		str[i + j] = command[i + 1];
		i++;
	}
	free(command);
	return (str);
}
