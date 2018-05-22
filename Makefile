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
LEMIN_CFILES = ft_lem-in.c ft_parse.c ft_exit.c ft_fill_data.c get_next_line.c ft_util.c ft_list.c ft_matrix.c ft_valid.c ft_algorithm.c ft_optimal.c ft_go.c
LEMIN_OFILES = $(LEMIN_CFILES:.c=.o)

HEADER = libft.h

all: $(NAME)
$(NAME): $(LEMIN_OFILES)
	make -C libft/
	make -C ft_printf/
	gcc $(FLAGS) -o $(NAME) $(LEMIN_OFILES) -L. -lft ft_printf/libftprintf.a
clean:
	rm -f $(LEMIN_OFILES) 
	make -C libft/ clean
	make -C ft_printf/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean
re: fclean all
do: all
	./$(NAME)
doc: all
	./$(NAME)
test:
	sh valid_parsing_tests/test.sh
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do doc