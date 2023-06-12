# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 04:05:09 by mabbas            #+#    #+#              #
#    Updated: 2023/06/09 04:10:33 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
CXX  = g++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -pedantic
NAME = Zombie

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "cpp compiled"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: clean all

.PHONY: all clean fclean re