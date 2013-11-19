# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <amerle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:29:45 by amerle            #+#    #+#              #
#    Updated: 2013/11/19 14:33:29 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LD = $(CC)
LDFLAGS = -lft -L../libft/
NAME = unit_test

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $^ $(LDFLAGS)

$(OBJS):
	$(CC) -o $*.o -c $*.c $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
