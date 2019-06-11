# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpasty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 11:44:16 by jpasty            #+#    #+#              #
#    Updated: 2019/05/21 14:40:35 by jpasty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

NAME = test_gnl
OBJ = main.o get_next_line.o
SRCS = main.c get_next_line.c
FLAGS = -Wall -Wextra -Werror -I libft/
LIB = -I libft/ -L libft/ -lft

all:
	@clear
	@make -C libft fclean && make -C libft
	gcc $(FLAGS) -o get_next_line.o -c get_next_line.c
	gcc $(FLAGS) -o main.o -c main.c
	gcc -g -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	make -C libft/ fclean

re: fclean all
