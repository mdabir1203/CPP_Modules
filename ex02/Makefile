
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC  = g++
RM  = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wfatal-errors

NAME = strings

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
