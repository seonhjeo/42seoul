# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:52:42 by seonhjeo          #+#    #+#              #
#    Updated: 2021/06/17 14:18:13 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -lm -framework OpenGL -framework AppKit
DELETE = rm -rf

NAME = cub3D

LIBFTDIR = ./libft
LIBFTLIB = ./libft/libft.a

INCLUDES = ./includes
INCLUDESBONUS = ./includesbonus
USRINCLUDES = ./usr/include

SRCS =	main.c \
		srcs/data/alloc.c \
		srcs/data/init.c \
		srcs/data/free.c \
		srcs/data/gnl.c \
		srcs/data/mapparsing.c \
		srcs/data/mapparsing2.c \
		srcs/data/mapparsing_utils.c \
		srcs/data/mapparsing_utils2.c \
		srcs/render/initmlx.c \
		srcs/render/renderscreen.c \
		srcs/render/drawminimap.c \
		srcs/render/drawline.c \
		srcs/render/player.c \
		srcs/render/keypress.c \
		srcs/render/renderutils.c \
		srcs/render/ray.c \
		srcs/render/ray2.c \
		srcs/render/ray3.c \
		srcs/render/rayutils.c \
		srcs/render/wall.c
SRCS_BONUS =	main.c \
				srcsbonus/data/alloc.c \
				srcsbonus/data/init.c \
				srcsbonus/data/free.c \
				srcsbonus/data/gnl.c \
				srcsbonus/data/mapparsing.c \
				srcsbonus/data/mapparsing2.c \
				srcsbonus/data/mapparsing_utils.c \
				srcsbonus/data/mapparsing_utils2.c \
				srcsbonus/render/initmlx.c \
				srcsbonus/render/renderscreen.c \
				srcsbonus/render/drawminimap.c \
				srcsbonus/render/drawline.c \
				srcsbonus/render/player.c \
				srcsbonus/render/keypress.c \
				srcsbonus/render/renderutils.c \
				srcsbonus/render/ray.c \
				srcsbonus/render/ray2.c \
				srcsbonus/render/ray3.c \
				srcsbonus/render/rayutils.c \
				srcsbonus/render/wall.c

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSRCS) -I$(INCLUDES) -I$(USRINCLUDES) $(CFLAGS) $(MLX) $(LIBFTLIB) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(DELETE) $(NAME)

re : fclean all

bonus : $(OBJSRCSBONUS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSRCSBONUS) -I$(INCLUDESBONUS) -I$(USRINCLUDES) $(CFLAGS) $(MLX) $(LIBFTLIB) -o $(NAME)
