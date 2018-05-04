/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:25:44 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:25:48 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ft_isnumline(char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (!(ft_isdigit(line[i])))
			return (0);
	}
	if (i > 10)
		return (0);
	return (1);
}

// int	ft_mask(char *mask, char *line)
// {
// 	int a;
// 	int b;

// 	a = 0;
// 	b = 0;
// 	if ((mask == NULL) || (line == NULL))
// 		return (0);
// 	while (line[b] != '\0')
// 	{
// 		if (mask[a] != line[b])
// 		{
// 			if (mask[a] == '*')
// 				while (mask[a] == '*')
// 					a++;
// 		}
// 	}
// 	return (0);
// }
