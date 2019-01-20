#include "minishell.h"

char	*tilde(char *command, char **environ)
{
	int i;
	int y;
	int j;
	char *str;

	i = 0;
	y = 0;
	j = 0;
	while (environ[y] && !(ft_strstr(environ[y], "HOME=")))
		y++;
	if (!environ[y])
		return (command);
	str = ft_strnew(ft_strlen(command) + ft_strlen(environ[y] - 5));
	while(command[i] && command[i] != '~')
	{
		str[i] = command[i];
		i++;
	}
	while(environ[y][j + 5])
	{

		str[i + j] = environ[y][j + 5];
		j++;
	}
	str[i + j] = '\0';
	while (command[i + 1])
	{
		str[i + j] = command[i + 1];
		i++;
	}
	str[i + j] = '\0';
	free(command);
	return (str);
}
