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

// ft_change()
// {

// }
// t_list	*ft_findbest(all_optimal_pathes)
// {

// }

int		ft_countpathlen(t_list *path)
{
	int i;
	int len;
	int *rooms;

	i = 0;
	len = 0;
	rooms = (int*)path->cont;
	while (i < g_n_of_rooms)
	{
		if (rooms[i] == 1)
			len++;
		i++;
	}
	ft_printf("Now path length is %d\n", len);
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

void	ft_findoptimalways(void)
{
	t_list *all_optimal_pathes;
	t_list *res;

	all_optimal_pathes = ft_findshortest();
	res = ft_findbest(all_optimal_pathes);
	// tmp = all_optimal_pathes;
	// max_n_of_ways = -1;
	// while (tmp)
	// {
	// 	tmp_sum = ft_findlensum(tmp, &n_of_ways);
	// 	if (max_n_of_ways == -1)
	// 	{
	// 		min_sum = tmp_sum;
	// 		max_n_of_ways = n_of_ways;	
	// 	}
	// 	else if (tmp_sum < min_sum)
	// 	{
	// 		min_sum = tmp_sum;
	// 	}
	// 	tmp = tmp->next;
	// }
	// new = ft_lstnew(cont, (g_n_of_rooms * (sizeof(int) / sizeof(void))));
	// ft_lstaddtotail(&g_ways, new);
	return (res);
}
