# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:33:40 by seonhjeo          #+#    #+#              #
#    Updated: 2022/03/24 12:48:08 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  crat

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

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
