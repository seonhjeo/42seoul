# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:40:19 by seonhjeo          #+#    #+#              #
#    Updated: 2022/02/15 16:42:45 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  replace

SRCS =	main.cpp \

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

rclean: fclean
	@${RM} *.replace

re: fclean all

.PHONY: clean fclean rclean re all