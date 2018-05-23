/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:09:00 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/14 16:09:02 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_getint(char *line)
{
	if (!ft_lineisint(line))
		ft_parse_exit(line);
	return (ft_atoi(line));
}

void	ft_parsefirstline(char *line)
{
	g_n_of_ants = ft_getint(line);
	if (g_n_of_ants <= 0)
		ft_parse_exit(line);
}

void	ft_lstaddtotail(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		ft_is_comment(char *line)
{
	t_list	*new_comment;

	if (line[0] == '#' && line[1] != '#')
	{
		new_comment = ft_lstnew(line, ft_strlen(line));
		ft_lstaddtotail(&g_comments_head, new_comment);
		return (1);
	}
	return (0);
}
