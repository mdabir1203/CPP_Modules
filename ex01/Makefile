# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:58 by mabbas            #+#    #+#              #
#    Updated: 2023/05/15 01:05:15 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := PhoneBook.cpp Contact.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
CXX = g++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic -Wfatal-errors
INCDIR = ./includes/
NAME = phonebook

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