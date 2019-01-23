int	ft_strccmp(char *s1, char *s2, char c)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-2048);
	while ((s1[i] || s2[i]) && s1[i] != c && s2[i] != c)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
