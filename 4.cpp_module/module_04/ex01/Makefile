# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:26:34 by seonhjeo          #+#    #+#              #
#    Updated: 2022/03/24 12:42:09 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  myAnimal

SRCS =	main.cpp \
		srcs/Animal.cpp \
		srcs/Cat.cpp \
		srcs/Dog.cpp \
		srcs/Brain.cpp

OBJS = ${SRCS:.cpp=.o}
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
