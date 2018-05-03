# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 20:54:09 by mkorniie          #+#    #+#              #
#    Updated: 2017/11/02 16:06:19 by mkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
LEMIN_CFILES = ft_lem-in.c ft_parse.c get_next_line.c
LEMIN_OFILES = $(LEMIN_CFILES:.c=.o)

HEADER = libft.h

all: $(NAME)
$(NAME): $(LEMIN_OFILES)
	make -C libft/ 
	gcc $(FLAGS) -o $(NAME) $(LEMIN_OFILES) -L. -lft
clean:
	rm -f $(LEMIN_OFILES) 
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
do: all
	./$(NAME)
doc: all
	./$(NAME)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do