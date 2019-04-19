# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpasty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 16:45:56 by jpasty            #+#    #+#              #
#    Updated: 2019/04/15 16:53:31 by jpasty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJ = *.o
FLAGS = -Wall -Wextra -Werror -c
HEAD = -I libft.h

$(NAME): 
	gcc $(FLAGS) $(SRCS) $(HEAD) 
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
