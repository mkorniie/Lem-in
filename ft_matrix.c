/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:04:11 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/14 18:04:12 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_findgraphindex(char *name)
{
	t_graph_point	*tmp;
	int				number;

	if ((name == NULL) || (g_head == NULL))
		ft_exit();
	number = 0;
	tmp = g_head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (number);
		tmp = tmp->next;
		number++;
	}
	return (-1);
}

void	ft_fillwithzeroes(int *line, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		line[i] = 0;
		i++;
	}
}

void	ft_create_matrix(void)
{
	int	i;

	g_n_of_rooms = ft_graphlistlen();
	g_adjacency_matrix = (int**)malloc(sizeof(int*) * (g_n_of_rooms + 1));
	if (g_adjacency_matrix == NULL)
	{
		perror("Error in ft_create_matrix: ");
		exit(0);
	}
	g_adjacency_matrix[g_n_of_rooms] = NULL;
	i = 0;
	while (i < g_n_of_rooms)
	{
		g_adjacency_matrix[i] = (int*)malloc(sizeof(int) * (g_n_of_rooms + 1));
		if (g_adjacency_matrix[i] == NULL)
		{
			perror("Error in ft_create_matrix: ");
			exit(0);
		}
		ft_fillwithzeroes(g_adjacency_matrix[i], g_n_of_rooms + 1);
		i++;
	}
}

void	ft_addtomatrix(char **split)
{
	int first_pos;
	int second_pos;

	if (g_adjacency_matrix == NULL)
		ft_create_matrix();
	first_pos = ft_findgraphindex(split[0]);
	second_pos = ft_findgraphindex(split[1]);
	if (first_pos == -1 || second_pos == -1)
		ft_exit();
	g_adjacency_matrix[first_pos][second_pos] = 1;
	g_adjacency_matrix[second_pos][first_pos] = 1;
}
