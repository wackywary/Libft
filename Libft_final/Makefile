# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btanja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:39:33 by btanja            #+#    #+#              #
#    Updated: 2019/04/26 19:46:06 by btanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_strlcat.c ft_putchar_fd.c ft_strlen.c ft_putendl.c ft_strmap.c ft_atoi.c ft_putendl_fd.c ft_strmapi.c ft_bzero.c ft_putnbr.c ft_strncat.c ft_count_words.c ft_putnbr_fd.c ft_strncmp.c ft_isalnum.c ft_putstr.c ft_strncpy.c ft_isalpha.c ft_putstr_fd.c ft_strnequ.c ft_isascii.c ft_reslen.c ft_strnew.c ft_isdigit.c ft_strcat.c ft_strnstr.c ft_isprint.c ft_strchr.c ft_strrchr.c ft_itoa.c ft_strclr.c ft_strsplit.c ft_memalloc.c ft_strcmp.c ft_strstr.c ft_memccpy.c ft_strcpy.c ft_strsub.c ft_memchr.c ft_strdel.c ft_strtrim.c ft_memcmp.c ft_strdup.c ft_tolower.c ft_memcpy.c ft_strequ.c ft_toupper.c ft_memdel.c ft_striter.c ft_wordalloc.c ft_memmove.c ft_striteri.c ft_memset.c ft_strjoin.c ft_itoa.c ft_strclr.c ft_strsplit.c ft_memalloc.c ft_strcmp.c ft_strstr.c ft_memccpy.c ft_strcpy.c ft_strsub.c ft_memchr.c ft_strdel.c ft_strtrim.c ft_memcmp.c ft_strdup.c ft_tolower.c ft_memcpy.c ft_strequ.c ft_toupper.c ft_memdel.c ft_striter.c ft_wordalloc.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 

INCLUDES = ./

O = ft_putchar.o ft_strlcat.o ft_putchar_fd.o ft_strlen.o ft_putendl.o ft_strmap.o ft_atoi.o ft_putendl_fd.o ft_strmapi.o ft_bzero.o ft_putnbr.o ft_strncat.o ft_count_words.o ft_putnbr_fd.o ft_strncmp.o ft_isalnum.o ft_putstr.o ft_strncpy.o ft_isalpha.o ft_putstr_fd.o ft_strnequ.o ft_isascii.o ft_reslen.o ft_strnew.o ft_isdigit.o ft_strcat.o ft_strnstr.o ft_isprint.o ft_strchr.o ft_strrchr.o ft_itoa.o ft_strclr.o ft_strsplit.o ft_memalloc.o ft_strcmp.o ft_strstr.o ft_memccpy.o ft_strcpy.o ft_strsub.o ft_memchr.o ft_strdel.o ft_strtrim.o ft_memcmp.o ft_strdup.o ft_tolower.o ft_memcpy.o ft_strequ.o ft_toupper.o ft_memdel.o ft_striter.o ft_wordalloc.o ft_memmove.o ft_striteri.o ft_memset.o ft_strjoin.o ft_itoa.o ft_strclr.o ft_strsplit.o ft_memalloc.o ft_strcmp.o ft_strstr.o ft_memccpy.o ft_strcpy.o ft_strsub.o ft_memchr.o ft_strdel.o ft_strtrim.o ft_memcmp.o ft_strdup.o ft_tolower.o ft_memcpy.o ft_strequ.o ft_toupper.o ft_memdel.o ft_striter.o ft_wordalloc.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o


all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
		ar rc $(NAME) $(O)
		ranlib $(NAME)

clean:
		/bin/rm -f $(O)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
	
lib:
	gcc -Wall -Wextra -Werror ./mains/$(FT)_main.c ./srcs/$(FT).c -I ./
