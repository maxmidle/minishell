#include "minishell.h"

int	main()
{
	extern char **environ;
	char *command;
	char **param;

	command = ft_strnew(0);
	while(ft_strcmp(command, "exit"))
	{
		ft_strclr(command);
		wait(0);
		ft_putstr("$>");
		param = read_line(&command);
		if (!ft_strcmp(command, "env"))
			ft_print_words_tables(environ);
		else if (!run_bin(command, param, environ))
		{
			if (ft_strcmp(command, "exit"))
			{
				ft_printf("-minishell: %s:", command);
				ft_putstr(" command not found\n");
			}
		}
		ft_freetab(param);
	}
	ft_strdel(&command);
	return (0);
}
