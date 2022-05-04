# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 14:10:11 by seonhjeo          #+#    #+#              #
#    Updated: 2021/06/17 12:39:49 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -lm -framework OpenGL -framework AppKit
DELETE = rm -rf

NAME = so_long

PRINTFDIR = ./printf
PRINTFLIB = ./printf/libftprintf.a

INCLUDES = ./includes
INCLUDESBONUS = ./includesbonus
USRINCLUDES = ./usr/include

SRCS =			main.c \
				srcs/data/alloc.c \
				srcs/data/init.c \
				srcs/data/free.c \
				srcs/data/gnl.c \
				srcs/data/dataparsing.c \
				srcs/data/dataparsing_utils.c \
				srcs/data/dataparsing_utils2.c \
				srcs/render/render.c \
				srcs/render/renderutils.c \
				srcs/render/player.c \
				srcs/render/draw.c

SRCS_BONUS =

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(PRINTFDIR)
	$(CC) $(OBJSRCS) -I$(INCLUDES) -I$(USRINCLUDES) $(CFLAGS) $(MLX) $(PRINTFLIB) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C $(PRINTFDIR)

fclean : clean
	$(MAKE) fclean -C $(PRINTFDIR)
	$(DELETE) $(NAME)

re : fclean all

bonus : $(OBJSRCSBONUS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(PRINTFDIR)
	$(CC) $(OBJSRCSBONUS) -I$(INCLUDESBONUS) -I$(USRINCLUDES) $(CFLAGS) $(MLX) $(PRINTFLIB) -o $(NAME)
