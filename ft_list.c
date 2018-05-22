/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:03:19 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/09 18:03:21 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph_point	*ft_newgraphlist(void)
{
	t_graph_point *res;

	if ((res = (t_graph_point*)malloc(sizeof(t_graph_point))) == NULL)
	{
		perror("Error in ft_newgraphlist: ");
		return (NULL);
	}
	res->name = NULL;
	res->pos_x = -1;
	res->pos_y = -1;
	res->status = -1;
	res->next = NULL;
	return (res);
}

int				ft_addtotail(t_graph_point *elem)
{
	if (elem == NULL)
		return (0);
	if (g_tail == NULL)
	{
		g_tail = elem;
		g_head = elem;
	}
	else
	{
		g_tail->next = elem;
		g_tail = elem;
	}
	return (1);
}

void			ft_printgraphlist(void)
{
	t_graph_point	*tmp;
	int				i;

	if (g_head == NULL)
		ft_putstr("The graph list is empty\n");
	else
	{
		i = 0;
		tmp = g_head;
		while (tmp)
		{
			ft_printf("Room %d : name = '%s', ", ft_findgraphindex(tmp->name), tmp->name);
			ft_printf("pos_x = %d, pos_y = %d, ", tmp->pos_x, tmp->pos_y);
			ft_printf("status = %d, next is %p\n", tmp->status, tmp->next);
			tmp = tmp->next;
		}
	}
}

t_graph_point	*ft_findelem(char *name)
{
	t_graph_point	*tmp;
	int i;

	if ((name == NULL) || (g_head == NULL))
		return (NULL);
	i = 0;
	tmp = g_head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				ft_graphlistlen(void)
{
	int				len;
	t_graph_point	*tmp;

	len = 0;
	tmp = g_head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
