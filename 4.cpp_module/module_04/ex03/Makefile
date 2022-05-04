# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:20:56 by seonhjeo          #+#    #+#              #
#    Updated: 2022/03/24 12:46:12 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  myMateria

SRCS =	main.cpp \
		srcs/AMateria.cpp \
		srcs/Character.cpp \
		srcs/Cure.cpp \
		srcs/Ice.cpp \
		srcs/MateriaSource.cpp

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
