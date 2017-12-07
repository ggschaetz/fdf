# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 11:05:36 by gschaetz          #+#    #+#              #
#    Updated: 2017/02/10 12:55:00 by gschaetz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft/libft.a

FLAG = -Wextra -Werror -Wall

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

INC = fdf.h

SRC = src/ft_bresenham.c src/ft_col_and_row.c src/main_fdf.c src/ft_fdf.c \
	  src/ft_stock_save.c src/ft_convert.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	gcc -o $(NAME) $(FLAG) $(SRC) -Llibft -lft $(FLAGMLX)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
	
.PHONY: all fclean re clean
