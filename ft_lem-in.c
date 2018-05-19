/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem-in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:26:21 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:26:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_matrix(void)
{
	int i;
	int z;
	// int len;

	i = 0;
	// len = ft_graphlistlen();
	while (i < g_n_of_rooms)
	{
		z = 0;
		while (z < g_n_of_rooms)
		{
			ft_printf("%d", g_adjacency_matrix[i][z]);
			z++;
		}
		i++;
		ft_printf("\n");
	}
}

void	ft_globelsetup(void)
{
	g_has_start_end = 0;
	g_head = NULL;
	g_tail = NULL;
	g_adjacency_matrix = NULL;
	g_n_of_rooms = 0;
}

int		main(void)
{
	ft_globelsetup();
	if (!ft_parse())
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_lstprint(g_comments_head);
	// ft_printgraphlist();
	// ft_print_matrix();
	// ft_findpath();
	return (0);
}
