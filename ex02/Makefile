# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 20:05:30 by mabbas            #+#    #+#              #
#    Updated: 2023/05/23 01:35:25 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := Account.cpp
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