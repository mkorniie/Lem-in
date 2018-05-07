#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
// void perror(const char *str)
# include <string.h>
// char *strerror(int errnum);
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include "ft_printf/header.h"

#define BUFSIZE  1024

typedef struct				s_graph_point
{
	char					**name;
	int						pos_x;
	int						pos_y;
	int						status; //0 - start, 2 - average, 3 - end
	struct s_graph_point	*next;
}							t_graph_point;

int				g_n_of_ants;
int				**g_adjacency_matrix;
t_graph_point	*g_head;

int				ft_parse(void);
int				ft_fill_data(char *line, int line_number);
int				ft_isnumline(char *line);
int				ft_valid_room(char *line);
int				ft_valid_link(char *line);
int				ft_lineisint(char *line);
void			ft_finish_programme(void);
#endif