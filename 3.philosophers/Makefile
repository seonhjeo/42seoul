# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:01:14 by seonhjeo          #+#    #+#              #
#    Updated: 2021/11/16 11:05:57 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
DELETE = rm -rf

NAME = philo

INCLUDES = ./philo_mandatory
INCLUDES_BOUNS = ./philo_bonus

SRCS =	philo_mandatory/main.c \
		philo_mandatory/error_manager.c \
		philo_mandatory/init.c \
		philo_mandatory/launcher.c \
		philo_mandatory/utils.c


SRCS_BONUS =

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS)
	$(DELETE) $(NAME)
	$(CC) $(OBJSRCS) -I$(INCLUDES) $(CFLAGS) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJSRCS) $(OBJSRCSBONUS)

fclean : clean
	$(DELETE) $(NAME)

re : fclean all

bonus : $(OBJSRCSBONUS)
	$(DELETE) $(NAME)
	$(CC) $(OBJSRCSBONUS) -I$(INCLUDESBONUS) $(CFLAGS) -o $(NAME)

.PHONY: 		all fclean clean re
