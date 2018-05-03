#include "lemin.h"

int		ft_validate_name(char *name)
{
	if ((name[0] == 'L') || (name[0] == '#'))
		return (0);
	return (1);
}

int		ft_valid_link(char *line)
{
	int boolean;
	int i;

	i = -1;
	boolean = 0;
	if (line == NULL)
		return (0);
	while (line[++i] != '\0')
	{
		if ((ft_isdigit(line[i]) == 0) && (line[i] != '-'))
			return (0);
		if (line[i] == '-')
		{
			if (boolean == 0)
				boolean = 1;
			else
				return (0);
		}
	}
	return (1);
}

int		ft_valid_room(char *line)
{
	char *temp;
	int i;

	i = 0;
	temp = line;
	if (line == NULL)
		return (0);
	while ((temp = ft_strchr(temp, ' ')) != NULL)
	{
		i++; 
		if (temp[1] == '\0')
			break;
		else
			temp = temp + 1;
	}
	if (i == 2)
		return (1);
	return (0);
}

int		ft_valid_line(char *line)
{
	if (line[0] == '#')
	{
		if(line[1] == '#')
		{
			if ((ft_strequ(line, "##start") == 1) || (ft_strequ(line, "##end") == 1))
				return (1);
			return (-1);
		}
		return (1);
	}
	if (ft_valid_room(line) || ft_valid_link(line))
		return (1);
	return (-1);
}

t_room*	ft_parse(void)
{
	t_room* res;
	int len;
	char *line;

	while ((len = get_next_line(0, &line)) > 0)
	{
		if (ft_valid_line(line) == -1)
		{
			ft_putstr("ERROR\n");
			return (NULL);
		}
	}
	// if (ft_validate_name(name))
	res = NULL;
	return (res);
}