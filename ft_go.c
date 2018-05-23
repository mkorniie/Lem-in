/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:19:24 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/22 18:19:28 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph_point	*ft_findby_index(int index)
{
	t_graph_point *tmp;
	int i;

	tmp = g_head;
	i = 0;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

t_graph_point	*ft_findby_status(int status)
{
	t_graph_point *tmp;
	int i;

	tmp = g_head;
	i = 0;
	while (tmp)
	{
		if (tmp->status == status)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

t_graph_point	**ft_findorder(void)
{
	t_list			*optimal;
	int				path;
	int				*rooms;
	int				i;
	int				res_counter;
	t_graph_point	**res;

	
	optimal = (t_list*)(g_optimalpool->content);
	rooms = (int*)optimal->content;
	rooms[g_end_index] = 1;
	res = (t_graph_point**)malloc(sizeof(t_graph_point*) * (g_optimal_len));
	path = g_start_index;
	i = 0;
	res_counter = 0;
	while (i < g_n_of_rooms)
	{
		rooms[path] = 0;
		if ((g_adjacency_matrix[path][i] == 1) && (rooms[i] == 1))
		{
			path = i;
			res[res_counter] = ft_findby_index(i);
			i = 0;
			res_counter++;
			if (res_counter == g_optimal_len)
				return (res);
		}
		else
			i++;
	}
	return (NULL);
}

void			ft_print_n(int len, int front_ant, t_graph_point **order)
{
	static int end;
	int i;
	int z;

	i = 0;
	if (len == g_optimal_len - 1)
	{
		if (end == 0)
			end = -1;
		else if (end == -1)
			end = 1;
	}
	if (end == 1)
		z = g_optimal_len - 1;
	else
		z = len - 1;
	while (i < len)
	{
		ft_printf("L%d-%s ", front_ant + i, (order[z])->name);
		i++;
		z--;
	}
}

void			ft_go(void)
{
	int				i;
	int				front_ant;
	t_graph_point	**order;

	i = 1;
	front_ant = 1;
	order = ft_findorder();
	while (i < (g_n_of_ants + g_optimal_len))
	{
		if (i <= g_optimal_len)
			ft_print_n(i, 1, order);
		else if (i >= g_n_of_ants)
			ft_print_n(g_n_of_ants + g_optimal_len - i, i - g_optimal_len + 1, order);
		else
		{
			front_ant = i - g_optimal_len + 1;
			ft_print_n(g_optimal_len, front_ant, order);
		}
		ft_printf("\n");
		i++;
	}
}
