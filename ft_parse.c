/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:26:03 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:26:05 by mkorniie         ###   ########.fr       */
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
	if ((line[0] == 'L') || (line[0] == '#'))
		return (0);
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

int		ft_parse(void)
{
	int		len;
	char	*line;
	int		i;

	i = 0;
	while ((len = get_next_line(0, &line)) > 0)
	{
		if (ft_valid_line(line) == -1 || \
			(!ft_fill_data(line, i++)))
		{
			ft_putstr("ERROR\n");
			return (0);
		}
	}
	return (1);
}
