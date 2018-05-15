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

// int	ft_fill_data(char *line, int line_number)
// {
// 	if (line_number == 0)
// 	{
// 		if (!ft_isnumline(line))
// 			return (0);
// 		g_n_of_ants = ft_atoi(line);
// 		if (g_n_of_ants <= 0)
// 			return (0);
// 		printf("g_n_of_ants is %d\n", g_n_of_ants);
// 	}
// 	if ((ft_strequ(line, "##start") == 1) || (ft_strequ(line, "##end") == 1))
// 	{
// 		g_params->has_start_end;
// 		g_params->name = ft_addtochararray(g_params->name, line);
// 	}
				
// }
