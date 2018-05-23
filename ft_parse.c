/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:26:03 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 21:26:05 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**ft_getroomparams(char *line)
{
	char	*temp;
	char	**split;
	int		i;

	i = 0;
	temp = line;
	if (line == NULL)
		return (NULL);
	while ((temp = ft_strchr(temp, ' ')) != NULL)
	{
		i++;
		if (temp[1] == '\0')
			break ;
		else
			temp = temp + 1;
	}
	if (i != 2)
		return (NULL);
	split = ft_strsplit(line, ' ');
	return ((ft_arrlen(split) != 3) ? NULL : split);
}

int		ft_parseroom(char *line)
{
	static int		status;
	t_graph_point	*new;
	char			**split;

	if (status == 0)
		if ((status = ft_line_is_command(line)) != 0)
			return (1);
	if ((line == NULL) || (line[0] == 'L') || (line[0] == '#'))
		return (0);
	new = ft_newgraphlist();
	if ((split = ft_getroomparams(line)) == NULL)
		return (0);
	new->name = split[0];
	new->pos_x = ft_getint(split[1]);
	new->pos_y = ft_getint(split[2]);
	new->status = status;
	if (!ft_unique_name_and_coords(split[0], new->pos_x, new->pos_y))
		ft_exit();
	ft_addtotail(new);
	status = 0;
	return (1);
}

char	**ft_getlinkparams(char *line)
{
	char	*temp;
	char	**split;
	int		i;

	i = 0;
	temp = line;
	if (line == NULL)
		return (NULL);
	while ((temp = ft_strchr(temp, '-')) != NULL)
	{
		i++;
		if (temp[1] == '\0')
			break ;
		else
			temp = temp + 1;
	}
	if (i != 1)
		return (NULL);
	split = ft_strsplit(line, '-');
	return ((ft_arrlen(split) != 2) ? NULL : split);
}

void	ft_parselink(char *line)
{
	char **split;

	if (line == NULL)
		return ;
	if ((split = ft_getlinkparams(line)) == NULL)
		ft_parse_exit(line);
	ft_addtomatrix(split);
}

int		ft_parse(void)
{
	int		len;
	char	*line;
	int		flag;

	flag = -1;
	while ((len = get_next_line(0, &line)) > 0)
	{
		if (!ft_is_comment(line) && !ft_if_unknown_command(line))
		{
			if (flag == -1)
			{
				ft_parsefirstline(line);
				flag = 0;
			}
			else if ((flag == 0) && (!ft_parseroom(line)))
			{
				ft_parselink(line);
				flag = 1;
			}
			else if (flag == 1)
				ft_parselink(line);
		}
		free(line);
	}
	return (flag == 1 ? 1 : 0);
}
