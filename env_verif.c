#include "minishell.h"

int	env_verif(char **cmd, int mode)
{
	int i;
	int stop;

	i = 1;
	stop = 0;
	if (ft_strcmp(cmd[0], "env"))
		return (0);
	while (!stop && cmd[i])
	{
		if (cmd[i][0] == '-')
		{
			if (env_param_error(cmd, i))
				return (env_error_print(cmd, i, mode));
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

int	env_param_error(char **cmd, int i)
{
	int y;

	y = 1;
	if (!cmd[i][y])
		return (1);
	while (cmd[i][y])
	{
		if ((cmd[i][y] != 'i' && cmd[i][y] != 'u') ||
			(cmd[i][y] == 'u' && !cmd[i + 1]))
			return (y);
		y++;
	}
	return (0);
}

int	env_error_print(char **cmd, int i, int mode)
{
	int y;

	y = env_param_error(cmd, i);
	if (mode)
	{
		if (!cmd[i][y])
			ft_putendl("env : any options specified");
		else if (cmd[i][y] == 'u')
			ft_putendl("env : option requires an argument -- u");
		else
			ft_printf("env: illegal option -- %c\n", cmd[i][y]);
		ft_putendl("usage: env [-i] [-u name] [name=value]");
	}
	return (-1);
}