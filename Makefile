#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:21:22 by adebray           #+#    #+#              #
#    Updated: 2014/03/11 06:45:07 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf
HEADDIR		=	inc
HEADFLAG	=	-I ./$(HEADDIR)
SRCDIR		=	src

SRC			= $(SRCDIR)/main.c
OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -O3 -g

LIBLIBFT	= -L$(SRCDIR)/libft -lft
LIBPRINTF	= -L$(SRCDIR)/ft_printf -lftprintf
LIBENV		= -L$(SRCDIR)/env -lenv
LIBBASIC	= -L$(SRCDIR)/basics -lbasic
LIBX11		= -lmlx -framework OpenGL -framework AppKit

LIBFLAG		= $(LIBLIBFT) $(LIBPRINTF) $(LIBBASIC) $(LIBX11) $(LIBENV)

.PHONY:		all clean fclean re $(NAME)

all:		makelib $(NAME)

makelib:	_libft _printf _basic _env

$(NAME):	$(OBJ) $(HEADDIR)/info.h
			@$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) $(OBJ)
			@echo '!'
			@echo "\033[32m•\033[0m compil: \033[32m$(NAME)\033[0m"

_libft:		$(HEADDIR)/libft.h
			@make -C $(SRCDIR)/libft

_printf:	$(HEADDIR)/ft_printf.h
			@make -C $(SRCDIR)/ft_printf

_basic:		$(HEADDIR)/basics.h
			@make -C $(SRCDIR)/basics

_env:		$(HEADDIR)/env.h
			@make -C $(SRCDIR)/env

%.o:		%.c
			@echo '.''\c'
			@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
			@make -C $(SRCDIR)/libft clean
			@make -C $(SRCDIR)/ft_printf clean
			@make -C $(SRCDIR)/basics clean
			@make -C $(SRCDIR)/env clean
			@rm -f $(OBJ)
			@echo "\033[31m•\033[0m clean: \033[31m$(NAME)\033[0m"

fclean:
			@make -C $(SRCDIR)/libft fclean
			@make -C $(SRCDIR)/ft_printf fclean
			@make -C $(SRCDIR)/basics fclean
			@make -C $(SRCDIR)/env fclean
			@rm -f $(OBJ)
			@rm -f $(NAME)
			@echo "\033[31m•\033[0m fclean: \033[31m$(NAME)\033[0m"

re:			fclean all
