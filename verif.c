#include "minishell.h"

int	env_verif(char **cmd)
{
	int i;
	int stop;

	i = 1;
	stop = 0;
	while (!stop && cmd[i])
	{
		if (cmd[i][0] == '-')
		{
			if (!ft_strchr(cmd[i], 'i') && !ft_strchr(cmd[i], 'u'))
			{
				ft_printf("env: illegal option -- %c", cmd[i][1]);
				ft_putendl("\nusage: env [-i] [-u name] [name=value]");
				return (-1);
			}
			if (ft_strchr(cmd[i], 'u'))
				i++;
		}
		else if (ft_strcmp(cmd[i], "env") && !ft_strchr(cmd[i], '='))
		{
			stop = 1;
			i--;
		}
		i++;
	}
	return (i);
}
