# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:00:29 by seonhjeo          #+#    #+#              #
#    Updated: 2022/04/15 10:18:06 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  easyfind

CPP = 		c++

CPPFLAGS =	-std=c++98 -Wall -Wextra -Werror

SRCS =		main.cpp \

OBJS =		$(SRCS:.cpp=.o)

.PHONY:		all clean fclean re

%.o : %.cpp
			$(CPP) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
			@echo "\033[0m"

clean:
			@echo "\n\033[0;31mCleaning..."
			rm -rf $(OBJS)
			@echo "\033[0m"

fclean:		clean
			@echo "\033[0;31mRemoving executable..."
			rm -f $(NAME)
			@echo "\033[0m"

re: 		fclean all
