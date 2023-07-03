# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 16:23:08 by mabbas            #+#    #+#              #
#    Updated: 2023/07/01 16:23:08 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
SRC = main.cpp Fixed.cpp
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
