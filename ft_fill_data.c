/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:26:33 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:26:35 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ft_line_is_command(char *line)
{
	if (line == NULL)
		return (0);
	if (ft_strequ(line, "##start") == 1)
	{
		g_has_start_end++;
		if (g_has_start_end <= 2)
			return (1);
		else
			ft_parse_exit(line);
	}
	if (ft_strequ(line, "##end") == 1)
	{
		g_has_start_end++;
		if (g_has_start_end <= 2)
			return (2);
		else
			ft_parse_exit(line);
	}
	return (0);
}