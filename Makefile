# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/05/04 16:56:13 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror
NAME = libftprintf.a
SRC1 = detect.c \
	flag.c\
	ft_printf.c\
	next1.c\
	next2.c\
	next3.c\
	next_bonus.c\
	put_d.c\
	put_d_unicode.c\
	put_s.c\
	put_s_unicode.c

SRC2 = utility/ft_bzero.c\
	utility/ft_isdigit.c\
	utility/ft_itoab_ll.c\
	utility/ft_itoab_ll_s.c\
	utility/ft_putchar.c\
	utility/ft_putchar_unicode.c\
	utility/ft_putnchar.c\
	utility/ft_putnchar_unicode.c\
	utility/ft_putstr.c\
	utility/ft_strchr.c\
	utility/ft_strdel.c\
	utility/ft_strnew.c\
	utility/ft_strlen.c

OBJ1 = $(patsubst %.c,%.o,$(SRC1))
OBJ2 = $(patsubst utility/%.c,%.o,$(SRC2))

IPATH = includes
VPATH = srcs

all : $(NAME)

$(NAME) : $(SRC1) $(SRC2)
	@$(CC) $(CFLAGS) -c $^ -I $(IPATH) 
	@ar rc $(NAME) $(OBJ1) $(OBJ2) 
	@ranlib $(NAME)
	
clean :
	@rm -f $(OBJ1) $(OBJ2)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

test : $(SRC1) $(SRC2) main.c
	@$(CC) $(CFLAGS) $^ -I $(IPATH)
	