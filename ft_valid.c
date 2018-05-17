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

int		ft_is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
	{
		ft_printf("%s\n", line);
		return (1);
	}
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