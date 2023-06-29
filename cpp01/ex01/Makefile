# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 23:42:00 by mabbas            #+#    #+#              #
#    Updated: 2023/06/22 23:59:17 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = zombieHorde
SRCS := Zombie.cpp zombieHorde.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
CXX  = g++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -pedantic -g #-fsanitize=address
RM   = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "zombies compiled"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: clean all

.PHONY: all clean fclean re