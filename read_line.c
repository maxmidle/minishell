#include "minishell.h"

char	**read_line(char **command, char **environ)
{
	char	**param;
	char buff[2];
	int i;

	i = 0;
	buff[1] = '\0';
	read(0, &buff, 1);
	while (buff[0] != '\n')
	{
		ft_strconc(command, buff);
		read(0, &buff, 1);
	}
	if (ft_strchr(*command, '~'))
		*command = tilde(*command, environ);
	param = ft_strsplit(*command, ' ');
	while (command[0][i] && command[0][i] != ' ')
		i++;
	if (command[0][i] == ' ')
		command[0][i] = '\0';
	return (param);
}
