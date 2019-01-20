#include "minishell.h"

int	main()
{
	int exit;
	int i;
	extern char **environ;
	char **command;
	char **envexec;

	exit = 1;
	while(exit)
	{
		i = 0;
		command = NULL;
		wait(0);
		ft_putstr("$>");
		command = read_line(environ);
		envexec = ft_tabdup(environ);
		if (command[i] && !ft_strcmp(command[i], "env"))
		{
			if ((i = env_verif(command)) != -1)
				envexec = env(command, environ, envexec);
			else
				i = ft_tablen(command);
		}
		if (command[i] && !run_bin(&command[i], environ, environ))
		{
			if (ft_strcmp(command[i], "exit"))
			{
				ft_printf("-minishell: %s:", command[i]);
				ft_putstr(" command not found\n");
			}
			else
				exit = 0;
		}
		if (command)
			ft_freetab(command);
		if (envexec)
			ft_freetab(envexec);
	}
	return (0);
}
