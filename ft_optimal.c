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

void	ft_findoptimalways(void)
{
	t_list *all_optimal_pathes;
	t_list *tmp;
	int		n_of_way;
	int		max_n_of_ways;
	int		min_sum;
	int		tmp_sum;

	all_optimal_pathes = ft_findshortest();
	tmp = all_optimal_pathes;
	max_n_of_ways = -1;
	while (tmp)
	{
		tmp_sum = ft_findlensum(tmp, &n_of_ways);
		if (max_n_of_ways == -1)
		{
			min_sum = tmp_sum;
			max_n_of_ways = n_of_ways;	
		}
		else if (tmp_sum < min_sum)
		{
			min_sum = tmp_sum;
		}
		tmp = tmp->next;
	}
	new = ft_lstnew(cont, (g_n_of_rooms * (sizeof(int) / sizeof(void))));
	ft_lstaddtotail(&g_ways, new);
}
