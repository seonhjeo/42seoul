# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 11:28:11 by seonhjeo          #+#    #+#              #
#    Updated: 2022/01/05 11:51:30 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RLFLAGS = -l readline
DELETE = rm -rf

NAME = minishell

LIBFTDIR = ./libft
LIBFTLIB = ./libft/libft.a

INCLUDES = ./srcs
INCLUDES_BOUNS = ./srcs_bonus

SRCS =	srcs/main.c \
		srcs/error/error.c \
		srcs/init/init.c \
		srcs/parsing/get_command.c \
		srcs/parsing/check_input.c \
		srcs/parsing/tokenize_input.c \
		srcs/parsing/tokenize_input2.c \
		srcs/parsing/treeing_input.c \
		srcs/parsing/treeing_input2.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/parsing_utils2.c \
		srcs/utils/utils.c \
		srcs/utils/env_list_utils.c \
		srcs/utils/env_node_utils.c \
		srcs/utils/token_utils.c \
		srcs/utils/tree_utils.c \
		srcs/utils/utils_signal.c \
		srcs/builtin/ft_env.c \
		srcs/builtin/ft_unset.c \
		srcs/builtin/ft_export.c \
		srcs/builtin/ft_exit.c \
		srcs/builtin/ft_pwd.c \
		srcs/builtin/ft_cd.c \
		srcs/builtin/ft_echo.c \
		srcs/redirection/redirecting_output.c \
		srcs/redirection/redirecting_input.c \
		srcs/redirection/appending_redirected_output.c \
		srcs/redirection/here_documents.c \
		srcs/execute/tree_traversal.c \
		srcs/execute/ft_pipe.c \

SRCS_BONUS =

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJS) -I$(INCLUDES) $(CFLAGS) $(RLFLAGS) $(LIBFTLIB) -o $(NAME)

all : $(NAME)

clean :
	$(DELETE) $(OBJS) $(OBJSBONUS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(DELETE) $(NAME)

re : fclean all

bonus : $(OBJSBONUS)
	$(DELETE) $(NAME)
	$(MAKE) bonus -C $(LIBFTDIR)
	$(CC) $(OBJSBONUS) -I$(INCLUDESBONUS) $(CFLAGS) $(LIBFTLIB) -o $(NAME)

.PHONY: all fclean clean re bonus
