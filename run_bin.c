#include "minishell.h"

int	run_bin(char *command, char **param, char **environ)
{
	char *bpath;
	pid_t pid;

	bpath = NULL;
	bpath = ft_strdup("/bin/");
	ft_strconc(&bpath, command);
	if (!access(bpath, X_OK))
	{
		pid = fork();
		if (pid == 0)
			execve(bpath, param, environ);
		ft_strdel(&bpath);
		return (1);
	}
	ft_strdel(&bpath);
	return (0);
}
