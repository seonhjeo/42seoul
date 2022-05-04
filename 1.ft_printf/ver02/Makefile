# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 12:00:33 by seonhjeo          #+#    #+#              #
#    Updated: 2021/03/23 12:07:56 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					ft_printf_utils.c \
					ft_printf_utils2.c \
					ft_printf_char.c \
					ft_printf_str.c \
					ft_printf_num.c


SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror -g
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:
				@${RM} ${NAME}
				@${RM} ${OBJS}
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
