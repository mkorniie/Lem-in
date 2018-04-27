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
LIBFT_CFILES = ft_numsize.c ft_memccpy.c ft_strsub.c ft_strmapi.c ft_strcpy.c ft_memalloc.c ft_putendl.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_abs.c ft_pow.c ft_printlst.c

HEADER = libft.h

all: $(NAME)
$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f libft.a
re: fclean all
cm: all clean
doc:
	gcc -Wall -Wextra -Werror ft_lem-in.c 
	./a.out
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
.PHONY: all clean fclean re cm