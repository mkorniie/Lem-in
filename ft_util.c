int	ft_mask(char *mask, char *line)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if ((mask == NULL) || (line == NULL))
		return (0);
	while (line[b] != '\0')
	{
		if (mask[a] != line[b])
		{
			if (mask[a] == '*')
				while (mask[a] == '*')
					a++;
		}
	}
	return (0);
}