/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:09:00 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/14 16:09:02 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int		ft_is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int		ft_getint(char *line)
{
	if (!ft_lineisint(line))
		ft_parse_exit(line);
	return (ft_atoi(line));
}

void	ft_parsefirstline(char *line)
{
	g_n_of_ants = ft_getint(line);
	if (g_n_of_ants <= 0)
		ft_parse_exit(line);
	
}