/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:18:53 by radler            #+#    #+#             */
/*   Updated: 2019/01/30 18:20:26 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **command, char **envorig)
{
	struct stat	sb;
	char		*path;
	char		oldpwd[2048];

	getcwd(oldpwd, 2048);
	if (command[1])
		path = getpath(command[1], oldpwd, envorig);
	else
		path = tilde(ft_strdup("~"), envorig);
	if (!lstat(path, &sb))
	{
		if (S_ISDIR(sb.st_mode))
		{
			if (!chdir(path))
				change_pwd(envorig, oldpwd);
			else if (command[1])
				cd_error(1, command[1]);
		}
		else if (command[1])
			cd_error(2, command[1]);
	}
	else if (command[1])
		cd_error(3, command[1]);
	ft_strdel(&path);
}

char	*getpath(char *command, char *oldpwd, char **envorig)
{
	int		i;
	char	*path;

	i = 0;
	while (envorig[i] && ft_strcmp(envorig[i], "OLDPWD") != 61)
		i++;
	if (!ft_strcmp(command, "-"))
	{
		if (envorig[i])
			return (ft_strdup(&envorig[i][7]));
		else
			return (ft_strdup("-"));
	}
	if (command && command[0] == '/')
		return (ft_strdup(command));
	path = ft_strdup(oldpwd);
	if (path[ft_strlen(path) - 1] != '/' && command[0] != '/')
		ft_strconc(&path, "/");
	if (command)
		ft_strconc(&path, command);
	return (path);
}

void	cd_error(int mode, char *command)
{
	ft_printf("-minishell: cd: %s: ", command);
	if (mode == 1)
		ft_putendl("Permission denied");
	if (mode == 2)
		ft_putendl("Not a directory");
	if (mode == 3)
		ft_putendl("No such file or directory");
}

void	change_pwd(char **envorig, char *oldpwd)
{
	int		i;
	int		y;
	char	buff[2048];

	y = 0;
	i = 0;
	while (envorig[i] && ft_strcmp(envorig[i], "OLDPWD") != 61)
		i++;
	while (envorig[y] && ft_strcmp(envorig[y], "PWD") != 61)
		y++;
	if (envorig[i])
	{
		ft_strdel(&envorig[i]);
		envorig[i] = ft_strdup("OLDPWD=");
		ft_strconc(&envorig[i], oldpwd);
	}
	if (envorig[y])
	{
		ft_strdel(&envorig[y]);
		envorig[y] = ft_strdup("PWD=");
		ft_strconc(&envorig[y], getcwd(buff, 2048));
	}
}
