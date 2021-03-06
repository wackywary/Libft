# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btanja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:39:33 by btanja            #+#    #+#              #
#    Updated: 2019/04/11 15:06:29 by btanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/*.c

INCLUDES = ./

O = *.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
		ar rc $(NAME) $(O)

clean:
		/bin/rm -f $(O)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

gcc:
	gcc ./mains/$(FT)_main.c ./srcs/ft_$(FT).c -I ./

www:
	gcc -Wall -Wextra -Werror ./mains/$(FT)_main.c ./srcs/$(FT).c -I ./
lib:
	gcc -Wall -Wextra -Werror ./srcs/ft_$(FT).c ./mains/$(FT)_main.c $(NAME) -I ./
