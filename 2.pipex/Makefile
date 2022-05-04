# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 11:05:18 by seonhjeo          #+#    #+#              #
#    Updated: 2021/08/23 13:36:59 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

INCLUDES = ./includes
SRCS =	srcs/main.c \
		srcs/pipex.c \
		srcs/pipex_utils.c


OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} -I${INCLUDES} ${CFLAGS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
