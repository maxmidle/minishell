#include "minishell.h"

char	**run_cmd(char **command, char **envorig, char **envexec)
{
	int	i;

	if ((i = env_verif(command, 0)) == -1)
		i = ft_tablen(command);
	ft_putnbr(i);
	if (command[i] && ft_isbuiltins(command[i]))
		envorig = run_builtins(command, envorig);
	else if (command[i] && !run_bin(&command[i], envorig, envexec))
	{
		if (ft_strcmp(command[i], "exit"))
		{
			ft_printf("-minishell: %s:", command[i]);
			ft_putstr(" command not found\n");
		}
		else
		{
			ft_freetab(envorig);
			return (NULL);
		}
	}
	return (envorig);
}

char	**run_builtins(char **command, char **envorig)
{
	if (!ft_strcmp(command[0], "cd"))
		ft_cd(command, envorig);
	else if (!ft_strcmp(command[0], "echo"))
		ft_echo(command);
	else if (!ft_strcmp(command[0], "setenv") && command[1] &&
		ft_strchr(command[1], '='))
		envorig = ft_setenv(envorig, command[1]);
	else if (!ft_strcmp(command[0], "unsetenv") && command[1])
		envorig = ft_unsetenv(envorig, command[1]);
	return (envorig);
}

int	ft_isbuiltins(char *command)
{
	if (!ft_strcmp(command, "echo") || !ft_strcmp(command, "unsetenv") ||
		!ft_strcmp(command, "setenv") || !ft_strcmp(command, "cd"))
		return (1);
	return (0);
}
