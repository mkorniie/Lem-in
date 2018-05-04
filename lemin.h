#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
// void perror(const char *str)
# include <string.h>
// strerror(error_num);
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"

#define BUFSIZE  1024

typedef struct	s_room
{
	char		**name;
	int			has_start_end;
	int			pos_x;
	int			pos_y;
	int			*links;
}				t_room;

int		g_n_of_ants;
t_room*	g_params;

int	ft_parse(void);
int	ft_fill_data(char *line, int line_number);
int	ft_isnumline(char *line);
int	ft_valid_room(char *line);
int	ft_valid_link(char *line)
#endif