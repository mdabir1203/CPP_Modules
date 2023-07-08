# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 12:27:56 by mabbas            #+#    #+#              #
#    Updated: 2023/07/08 12:28:01 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=c++
SRC=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98
DFLAGS=-g
NAME=FragTrap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
