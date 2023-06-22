# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 01:23:23 by mabbas            #+#    #+#              #
#    Updated: 2023/06/23 01:28:19 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sedReplacer
SRC = main.cpp replace.cpp
OBJ = $(SRC:.cpp=.o)
CC  = g++
RM  = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wfatal-errors


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
