# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 16:00:00 by seonhjeo          #+#    #+#              #
#    Updated: 2021/10/26 13:32:50 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
DELETE = rm -rf

NAME = push_swap

LIBFTDIR = ./libft
LIBFTLIB = ./libft/libft.a

INCLUDES = ./includes
INCLUDESBONUS = ./includesbonus
USRINCLUDES = ./usr/include

SRCS =	srcs/main.c \
		srcs/inputparsing.c \
		srcs/free.c \
		srcs/list_utils.c \
		srcs/list_command.c \
		srcs/list_command2.c \
		srcs/list_command3.c \
		srcs/is_sorted.c \
		srcs/get_pivot.c \
		srcs/sort2.c \
		srcs/sort_less.c \
		srcs/sort_under_three2.c \
		srcs/sort_under_three3.c \
		srcs/sort_fourfive.c \
		srcs/sort_utils.c \

SRCS_BONUS =

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSRCS) -I$(INCLUDES) $(CFLAGS) $(LIBFTLIB) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	$(DELETE) $(LIBFTLIB)
	$(DELETE) $(NAME)

re : fclean all

bonus : $(OBJSRCSBONUS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSRCSBONUS) -I$(INCLUDESBONUS) $(CFLAGS) $(LIBFTLIB) -o $(NAME)

.PHONY: 		all fclean clean re
