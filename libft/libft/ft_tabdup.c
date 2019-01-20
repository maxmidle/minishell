#include "libft.h"

char **ft_tabdup(char **tab)
{
	int	i;
	char	**cpy;

	i = 0;
	if (!tab)
		return (NULL);
	cpy = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
