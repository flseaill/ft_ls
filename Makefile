# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianseailles <florianseailles@student.42.fr>+#+  +:+       +#+     #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 06:17:17 by flseaill          #+#    #+#              #
#    Updated: 2017/11/24 20:31:54 by flseaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror
#INC = libft/libft.h

CC = gcc -o

SRCO = $(SRC:.c=.o)

SRC += libft/libft.a
#SRC += ft_ls.c
SRC += ft_ls_a.c
#SRC += ft_ls_l.c
#SRC += ft_ls_r.c
#SRC += ft_ls_t.c
#SRC += ft_ls_rec.c
#SRC += ft_lsrec.c
all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(NAME) $(CFLAGS) $(SRC)

clean:
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
