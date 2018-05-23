/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:09:30 by mkorniie          #+#    #+#             */
/*   Updated: 2018/05/14 16:09:33 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include "ft_printf/header.h"

# define BUFSIZE  1024

typedef struct				s_graph_point
{
	char					*name;
	int						pos_x;
	int						pos_y;
	int						status;
	struct s_graph_point	*next;
}							t_graph_point;

int							g_n_of_ants;
int							**g_adjacency_matrix;
int							g_has_start_end;
int							g_n_of_rooms;
t_list						*g_comments_head;
t_list						*g_optimalpool;
int							g_optimal_len;
int							g_start_index;
int							g_end_index;
t_list						*g_ways;
t_graph_point				*g_head;
t_graph_point				*g_tail;

void						ft_solve(void);
void						ft_exit(void);
int							ft_parse(void);
void						ft_lstprintintarr(t_list *head);
int							ft_line_is_command(char *line);
int							ft_fill_data(char *line, int line_number);
int							ft_isnumline(char *line);
int							ft_valid_room(char *line);
int							ft_valid_link(char *line);
int							ft_lineisint(char *line);
void						ft_finish_programme(void);
int							ft_addtotail(t_graph_point *elem);
t_graph_point				*ft_newgraphlist(void);
t_graph_point				*ft_findelem(char *name);
int							ft_arrlen(char **arr);
void						ft_parse_exit(char *line);
int							ft_getint(char *line);
void						ft_parsefirstline(char *line);
int							ft_graphlistlen(void);
void						ft_printgraphlist(void);
t_graph_point				*ft_findelem(char *name);
int							ft_is_comment(char *line);
int							ft_if_unknown_command(char *line);
void						ft_addtomatrix(char **split);
void						ft_lstprint(t_list *head);
void						ft_lstaddtotail(t_list **alst, t_list *new);
void						ft_findoptimalways(void);
int							ft_intlsthascontent(int *content);
int							ft_findgraphindex(char *name);
int							ft_unique_name(char *name);
int							ft_unique_name_and_coords(char *name, \
	int pos_x, int pos_y);
void						ft_go(void);
#endif
