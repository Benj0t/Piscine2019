# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreho <mreho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 14:36:29 by mreho             #+#    #+#              #
#    Updated: 2019/08/21 23:24:48 by bemoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
FLAGS	= -Wall -Wextra -Werror
SRCDIR	= srcs
INCDIR	= includes
SOURCES	= main.c \
		  ft_putchar.c ft_putstr.c ft_strtoui.c ft_strncpy.c \
		  ft_strdup.c ft_split.c ft_strlen.c \
		  bsq.c reader.c parser.c printer.c converter.c processor.c calculator.c
OBJECTS	= $(SOURCES:%.c=$(SRCDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	/usr/bin/gcc -o $(NAME) $(FLAGS) -I$(INCDIR) $(OBJECTS)

%.o: %.c
	/usr/bin/gcc -o $@ $(FLAGS) -I$(INCDIR) -c $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
