#include "minishell.h"

int	main()
{
	int exit;
	int i;
	extern char **environ;
	char **envorig;
	char **command;
	char **envexec;

	exit = 1;
	envorig = ft_tabdup(environ);
	while(exit)
	{
		i = 0;
		command = NULL;
		wait(0);
		ft_printf("minishell: %s/ $>", (ft_strrchr(envorig[12], '/') + 1));
		command = read_line(envorig);
		envexec = ft_tabdup(envorig);
		if (command[i] && !ft_strcmp(command[i], "env"))
		{
			if ((i = env_verif(command)) != -1)
				envexec = env(command, envorig, envexec);
			else
				i = ft_tablen(command);
		}
		if (!ft_strcmp(command[i], "cd"))
			ft_cd(command, envorig);
		else if (!ft_strcmp(command[i], "echo"))
			ft_echo(command);
		else if (!ft_strcmp(command[i], "setenv") && command[i + 1] &&
			ft_strchr(command[i + 1], '='))
			envorig = ft_setenv(envorig, command[1]);
		else if (!ft_strcmp(command[i], "unsetenv") && command[i + 1])
			envorig = ft_unsetenv(envorig, command[i + 1]);
		else if (command[i] && !run_bin(&command[i], envorig, envexec))
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
	if (envorig)
		ft_freetab(envorig);
	return (0);
}
