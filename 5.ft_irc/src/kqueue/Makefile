SRCS =	main.cpp \
		client.cpp \
		server.cpp \
		channel.cpp \
		message.cpp \
		command.cpp \
		commands/pass.cpp \
		commands/nick.cpp \
		commands/user.cpp \
		commands/help.cpp \
		commands/ison.cpp \
		commands/quit.cpp \
		commands/ping.cpp \
		commands/pong.cpp \
		commands/list.cpp \
		commands/join.cpp \
		commands/part.cpp \
		commands/kick.cpp \
		commands/privmsg.cpp
		
OBJS = ${SRCS:%.cpp=%.o}

CXX = c++
CXXFLAGE = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

NAME = ircserv

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGE) -c $< -o $@

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGE) $(SRCS) -o $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)


re:	fclean all

.PHONY: all clean fclean re
