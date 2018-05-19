/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:01:39 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/17 20:01:43 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*ft_find_index_by_status(int status)
{
	t_graph_point tmp;
	int i;

	tmp = g_head;
	i = 0;
	while (tmp)
	{
		if (tmp->status == status)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int		ft_findpath(int path_n, int *rooms)
{
	int i;

	i = 0;
	rooms[path_n] = 1;
	while (i < g_n_of_rooms)
	{
		if (g_adjacency_matrix[path_n][i] == 1)
		{
			if (rooms[i] == 0)
			{
				rooms[i] = 1;
				if (i == g_end_index)
					return (1);	
				if (ft_findpath(i, rooms) == 1)
					return (1);
				else
					return (0);
			}
		}
		i++;
	}
}

t_list	*ft_fill_pathmatrix(void)
{
	t_list *head;

	g_start_index = ft_find_index_by_status(1);
	g_end_index = ft_find_index_by_status(2);
	while ()
	{

	}
}

void	ft_findpath(void);
{
	t_list* path_matrix;

	path_matrix = ft_fill_pathmatrix();
	ft_findoptimalways(path_matrix);
	ft_go();
}
