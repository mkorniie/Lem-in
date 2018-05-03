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
	char		*name;
	int			pos_x;
	int			pos_y;
	int			*links;
}				t_room;

int		g_n_of_ants;
t_room*	ft_parse(void);
#endif