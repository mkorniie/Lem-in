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

void	ft_lstprintarr(t_list *head)
{
	t_list *tmp;
	size_t i;
	int *line;

	tmp = head;
	while (tmp)
	{
		i = 0;
		while (i < tmp->content_size)
		{
			line = (int*)tmp->content;
			ft_printf("%d ", line[i]);
			i++;
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	ft_lstprint(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while (tmp)
	{
		write(1, tmp->content, tmp->content_size);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	ft_lstaddtotail(t_list **alst, t_list *new)
{
	t_list *tmp;

	ft_printf("It's ft_lstaddtotail!\n");
	if (alst == NULL || new == NULL)
	{
		ft_printf("It's null!\n");
		return ;
	}
	if (*alst == NULL)
	{
		ft_printf("It's the first one!\n");
		*alst = new;
	}
	else
	{
		tmp = *alst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
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