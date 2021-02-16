# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 11:19:31 by bemoreau          #+#    #+#              #
#    Updated: 2019/08/21 09:31:41 by bemoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs

INCDIR = includes

SOURCES = do_op.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi.c

OBJECTS = $(SOURCES:%.c=$(SRCDIR)/%.o)

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
