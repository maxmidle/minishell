#include "minishell.h"

int	run_bin(char **command, char **envorig, char **envexec)
{
	char **bpath;
	int y;
	pid_t pid;

	y = 0;
	while (envorig[y] && !(ft_strstr(envorig[y], "PATH=")))
		y++;
	bpath = ft_strsplit(&envorig[y][5], ':');
	y = 0;
	while (bpath[y])
	{
		ft_strconc(&bpath[y], "/");
		ft_strconc(&bpath[y], command[0]);
		if (!access(bpath[y], X_OK))
		{
			pid = fork();
			if (pid == 0)
				execve(bpath[y], command, envexec);
			ft_freetab(bpath);
			return (1);
		}
		y++;
	}
	ft_freetab(bpath);
	return (0);
}
