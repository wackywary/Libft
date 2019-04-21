# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btanja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:39:33 by btanja            #+#    #+#              #
#    Updated: 2019/04/11 17:29:09 by btanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./*.c

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
