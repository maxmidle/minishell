/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:24:53 by radler            #+#    #+#             */
/*   Updated: 2019/01/30 18:24:55 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include "libft/ft_printf.h"

int		run_bin(char **command, char **envorig, char **envexec);
char	**read_line(char **environ);
char	**split_line(char *str);
int		count_words(char *str);
char	*tilde(char *command, char **environ);

char	**env(char **command, char **envorig, char **envexec);
char	**env_option(char **envexec, char **command, int *u);
char	**ft_setenv(char **environ, char *var);
char	**ft_unsetenv(char **environ, char *var);
char	**ft_unsetenv_all(char **environ);

int		env_verif(char **command, int mode);
int		env_param_error(char **cmd, int i);
int		env_error_print(char **cmd, int i, int mode);
int		env_search(char **environ, char *var);

void	ft_cd(char **command, char **envorig);
void	cd_error(int mode, char *command);
void	change_pwd(char **envorig, char *oldpwd);
char	*getpath(char *command, char *oldpwd, char **envorig);

void	ft_echo(char **command);
void	ft_prompt(char **envorig);

char	**dollar(char **command, char **environ);
char	*dollar_verif(char *command, char **environ);
char	*dollar_fill(char *command, char *environ);

char	**run_cmd(char **command, char **envorig, char **envexec);
char	**run_builtins(char **command, char **envorig);
int		ft_isbuiltins(char *command);
#endif
