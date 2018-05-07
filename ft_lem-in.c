/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem-in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:26:21 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:26:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	// g_params->has_start_end = 0;
	if (!ft_parse())
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	
	// int len;
	// char* buf;


	// buf = (char*)malloc(sizeof(char) * (BUFSIZE + 1));
	// buf[BUFSIZE] = '\0';
	// len = 1;
	// while(len > 0)
	// {
	// 	len = read(0, buf, BUFSIZE);
	// 	buf[len] = '\0';
	// 	if (ft_strstr(buf, "##end"))
	// 		break;
	// 	// printf("%s", buf);
	// }
	return (0);
}
