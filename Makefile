# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <amerle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:39:05 by amerle            #+#    #+#              #
#    Updated: 2013/11/30 01:28:14 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LD = ar
CFLAGS = -Wall -Wextra -Werror -ggdb3
LDFLAGS = rcs
NAME = libft

SRCS = \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa_ccount.c \
	ft_itoa.c \
	ft_putendl.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putlnbr.c \
	ft_putulnbr.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_dlistnew.c \
	ft_dlistadd.c \
	ft_dlistlen.c \
	ft_dlistinsert.c \
	ft_dlistdel.c \
	ft_dlistrm.c \
	ft_printf.c \
	ft_printf_parse_2.c \
	ft_printf_parse_flags.c \
	ft_printf_parse_sublength.c \
	ft_printf_display.c \
	ft_putunbr.c \
	ft_puthex.c \
	ft_putlhex.c \
	ft_putdouble.c \
	ft_isinarray.c \
	ft_dlistsort.c \
	ft_dlistswap.c \
	ft_dlistcpy.c \
	ft_indexinarray.c \
	ft_regmatch.c \
	ft_regmatch_parser.c \
	ft_reg_create.c \
	ft_reg_matcher.c \
	ft_reg_match_rep.c \
	ft_match_any.c \
	ft_reg_match_begend.c \
	ft_reg_isinarray.c \
	ft_reg_match_sub.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME).a $^
	ranlib $(NAME).a

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME).a

re: fclean all

.PHONY: clean fclean re

