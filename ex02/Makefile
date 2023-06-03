# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 20:05:30 by mabbas            #+#    #+#              #
#    Updated: 2023/06/04 00:32:05 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := Account.cpp tests.cpp
OBJS := $(SRCS:.cpp=.o)
CXX = g++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic
INCDIR = ./includes/
NAME = Account

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I $(INCDIR)  -o $(NAME) $(OBJS)
	@echo "Compiled successfully"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: clean all

.PHONY: all clean fclean re