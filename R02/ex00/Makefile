# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 19:02:46 by bemoreau          #+#    #+#              #
#    Updated: 2019/08/18 23:26:28 by abarbour         ###   ########.fr        #
#    Updated: 2019/08/18 22:55:49 by bemoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRCS = srcs/main.c \
	   srcs/ft_parse.c \
	   srcs/ft_fill.c \
	   srcs/ft_check_arg.c \
	   srcs/ft_check.c \
	   srcs/ft_plus.c \
	   srcs/ft_plus2.c \

FLAGS = -Wall -Werror -Wextra

CC = gcc

OBJ = $(SRCS:.c=.o)

.PHONY:     all clean re fclean

all:        $(NAME)

$(NAME):    $(OBJ)
	$(CC) $(FLAGS) -I./includes $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
