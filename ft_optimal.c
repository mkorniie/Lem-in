/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:43:27 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/20 17:43:40 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_countpathlen(t_list *path)
{
	int i;
	int len;
	int *rooms;

	i = 0;
	len = 0;
	rooms = (int*)(path->content);
	while (i < g_n_of_rooms)
	{
		if (rooms[i] == 1)
			len++;
		i++;
	}
	return (len);
}

int		ft_count_shortest_len(void)
{
	int		min_len;
	int		curr_len;
	int		is_first;
	t_list	*tmp;

	is_first = 0;
	tmp = g_ways;
	while (tmp)
	{
		curr_len = ft_countpathlen(tmp);
		if (is_first == 0)
		{
			is_first = 1;
			min_len = curr_len;
		}
		else if (curr_len < min_len)
			min_len = curr_len;
		tmp = tmp->next;
	}
	return (min_len);
}

t_list	*ft_findshortest(void)
{
	int		shortes_len;
	t_list	*tmp;
	t_list	*add;
	t_list	*all_optimal_pathes;

	shortes_len = ft_count_shortest_len();
	g_optimal_len = shortes_len;
	all_optimal_pathes = NULL;
	tmp = g_ways;
	while (tmp)
	{
		if (ft_countpathlen(tmp) == shortes_len)
		{
			add = ft_lstnew(tmp, sizeof(t_list*));
			ft_lstaddtotail(&all_optimal_pathes, add);
		}
		tmp = tmp->next;
	}
	return (all_optimal_pathes);
}

void	ft_poollstprint(t_list *pool)
{
	t_list	*tmp;
	t_list	*to_print;
	int		*rooms;
	int		i;

	tmp = pool;
	while (tmp)
	{
		to_print = (t_list*)(tmp->content);
		rooms = (int*)to_print->content;
		i = 0;
		while (i < g_n_of_rooms)
		{
			ft_printf("%d ", rooms[i]);
			i++;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	ft_findoptimalways(void)
{
	t_list *all_optimal_pathes;

	all_optimal_pathes = ft_findshortest();
	g_optimalpool = all_optimal_pathes;
}
