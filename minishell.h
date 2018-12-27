#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/ft_printf.h"

int	run_bin(char *command, char **param, char **environ);
char	**read_line(char **command);

#endif
