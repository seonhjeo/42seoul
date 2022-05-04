# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 08:18:58 by seonhjeo          #+#    #+#              #
#    Updated: 2022/02/15 08:41:06 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myAccount

SRCS =	Account.cpp \
		tests.cpp

OBJS = ${SRCS:.cpp=.o}
CC = c++
CFLAGS = -Wall -Wextra -Werror
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