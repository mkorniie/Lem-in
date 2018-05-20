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

int	ft_intlsthascontent(int *content)
{
	t_list *tmp;
	int boolean;
	int i;
	int *tmp_content;

	tmp = g_ways;
	while (tmp)
	{
		i = 0;
		boolean = 1;
		tmp_content = (int*)(tmp->content);
		while (i < g_n_of_rooms)
		{
			if (content[i] != tmp_content[i])
				boolean = 0;
			i++;
		}
		if (boolean == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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