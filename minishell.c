/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:14:34 by radler            #+#    #+#             */
/*   Updated: 2019/01/30 18:15:52 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	extern char	**environ;
	char		**envorig;
	char		**envexec;
	char		**command;

	envorig = ft_tabdup(environ);
	while (envorig)
	{
		command = NULL;
		wait(0);
		ft_prompt(envorig);
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

void	ft_prompt(char **envorig)
{
	char	*tmp;
	int		i;

	i = 0;
	while (envorig[i] && ft_strcmp(envorig[i], "PWD") != 61)
		i++;
	if (envorig[i] && (tmp = ft_strrchr(envorig[i], '/') + 1))
		ft_printf("msh: \x1B[34m%s/\x1B[33m )>\x1B[0m", tmp);
	else
		ft_printf("msh: \x1B[34mPWD/\x1B[33m )>\x1B[0m");
}
