#include "minishell.h"

int	main()
{
	extern char	**environ;
	char 		**envorig;
	char		**envexec;
	char		**command;

	envorig = ft_tabdup(environ);
	while(envorig)
	{
		command = NULL;
		wait(0);
		ft_prompt(envorig[12]);
		command = read_line(envorig);
		envexec = ft_tabdup(envorig);
		if (command && command[0] && !ft_strcmp(command[0], "env"))
		{
			if (env_verif(command, 1) != -1)
				envexec = env(command, envorig, envexec);
		}
		envorig = run_cmd(command, envorig, envexec);
		if (command)
			ft_freetab(command);
		if (envexec)
			ft_freetab(envexec);
	}
	return (0);
}

void	ft_prompt(char *envorig)
{
	char *tmp;
	
	tmp = ft_strrchr(envorig, '/') + 1;
	ft_printf("msh: \x1B[34m%s/\x1B[33m )>\x1B[0m", tmp);
}
