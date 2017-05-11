# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/05/11 19:31:40 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror
NAME = libftprintf.a
SRC1 = ft_printf.c\
	get_info/get_info.c\
	get_info/get_flag.c\
	get_info/cv_s.c\
	get_info/cv_d.c\
	get_info/cv_dm.c\
	get_info/cv_o.c\
	get_info/cv_om.c\
	get_info/cv_p.c\
	get_info/cv_u.c\
	get_info/cv_um.c\
	get_info/cv_x.c\
	get_info/cv_xm.c\
	get_info/cv_c.c\
	get_info/cv_cm.c\
	get_info/cv_b.c\
	print/print_format.c\
	print/print_flag.c\
	print/prt_cm.c\
	print/prt_u.c\
	print/prt_d.c\
	print/prt_s.c\
	print/prt_c.c\
	print/prt_o.c\
	print/prt_p.c\
	print/prt_sm.c\

SRC2 = utility/ft_putchar.c\
	utility/ft_putnchar.c\
	utility/ft_putstr.c\
	utility/ft_strjoin.c\
	utility/ft_strlen.c\
	utility/ft_strchr.c\
	utility/ft_itoab_ll.c\
	utility/ft_down.c

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
	