/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:08:36 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/14 16:08:39 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_exit(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	ft_parse_exit(char *line)
{
	free(line);
	ft_exit();
}
