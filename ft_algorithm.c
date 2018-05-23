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

int		*ft_intcopy(int *tocopy, int len)
{
	int i;
	int *res;

	i = 0;
	res = (int*)malloc(sizeof(int) * (len + 1));
	res[len] = 0;
	while (i < len)
	{
		res[i] = tocopy[i];
		i++;
	}
	return (res);
}

int		ft_find_index_by_status(int status)
{
	t_graph_point *tmp;
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

void		ft_findpath(int path_n, int *rooms)
{
	int i;
	t_list *new;
	int *cont;

	i = 0;
	rooms[path_n] = 1;
	while (i < g_n_of_rooms)
	{
		if ((g_adjacency_matrix[path_n][i] == 1) && (rooms[i] == 0))
		{
			if (i == g_end_index)
			{
				if (ft_intlsthascontent(rooms) == 0)
				{
					cont = ft_intcopy(rooms, g_n_of_rooms);
					new = ft_lstnew(cont, (g_n_of_rooms * (sizeof(int) / sizeof(void))));
					ft_lstaddtotail(&g_ways, new);
				}
			}
			else
			{
				rooms[i] = 1;
				ft_findpath(i, rooms);
			}
		}
		i++;
	}
	rooms[path_n] = 0;
}

void	ft_fill_pathmatrix(void)
{
	int *rooms;
	int i;

	g_start_index = ft_find_index_by_status(1);
	g_end_index = ft_find_index_by_status(2);
	rooms = (int*)malloc(sizeof(int) * (g_n_of_rooms + 1));
	rooms[g_n_of_rooms] = 0;
	i = 0;
	while (i < g_n_of_rooms)
	{
		rooms[i] = 0;
		i++;
	}
	ft_findpath(g_start_index, rooms);
	if (g_ways == NULL)
		ft_exit();
}

void	ft_solve(void)
{
	ft_fill_pathmatrix();
	ft_findoptimalways();
	ft_go();
}
