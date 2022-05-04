# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:52:42 by seonhjeo          #+#    #+#              #
#    Updated: 2021/05/26 13:12:18 by seonhjeo         ###   ########.fr        #
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
USRINCLUDES = ./usr/include

SRCS =	main.c \
		srcs/data/alloc.c \
		srcs/data/alloc2.c \
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
		srcs/render/drawsprite.c \
		srcs/render/sprite.c \
		srcs/render/sprite2.c \
		srcs/render/wall.c
SRCS_BONUS =

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS) $(OBJSRCSBONUS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSRCSBONUS) $(OBJSRCS) -I$(INCLUDES) -I$(USRINCLUDES) $(CFLAGS) $(MLX) $(LIBFTLIB) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(DELETE) $(NAME)
	$(DELETE) cub3d.bmp

re : fclean all

bonus : $(NAME)
