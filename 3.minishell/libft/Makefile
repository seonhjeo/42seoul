# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 10:26:07 by seonhjeo          #+#    #+#              #
#    Updated: 2021/12/28 17:02:10 by seonhjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_putendl_fd.c \
			ft_atoi.c \
			ft_putnbr.c \
			ft_bzero.c \
			ft_putnbr_fd.c \
			ft_calloc.c \
			ft_putstr.c \
			ft_isalnum.c \
			ft_putstr_fd.c \
			ft_isalpha.c \
			ft_split.c \
			ft_isascii.c \
			ft_strchr.c \
			ft_isdigit.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_isprint.c \
			ft_strjoin.c \
			ft_isspace.c \
			ft_strlcat.c \
			ft_itoa.c \
			ft_strlcpy.c \
			ft_memccpy.c \
			ft_strlen.c \
			ft_memchr.c \
			ft_strmapi.c \
			ft_memcmp.c \
			ft_strncmp.c \
			ft_memcpy.c \
			ft_strnstr.c \
			ft_memmove.c \
			ft_strrchr.c \
			ft_memset.c \
			ft_strtrim.c \
			ft_putchar.c \
			ft_substr.c \
			ft_putchar_fd.c \
			ft_tolower.c \
			ft_putendl.c \
			ft_toupper.c
OBJS	=	$(SRCS:%.c=%.o)

BSRCS	=	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
BOBJS	=	$(BSRCS:%.c=%.o)

LIBC	=	ar rc
LIBR	=	ranlib
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -c
RM		=	rm -f

all			:	$(NAME)

$(NAME) 	:	$(OBJS)
	$(LIBC) $(NAME) $(OBJS)

$(OBJS) 	:	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

$(BOBJS) 	:	$(BSRCS)
	$(CC) $(CFLAGS) $(BSRCS)

n			:
	$(NORM)

bonus 		:	fclean $(OBJS) $(BOBJS)
	$(LIBC) $(NAME) $(OBJS) $(BOBJS)

clean		:
	$(RM) $(OBJS) $(BOBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY: bonus all clean fclean re
