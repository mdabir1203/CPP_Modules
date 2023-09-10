NAME = bureaucrat
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCDIR = src
OBJDIR = .objFiles
HEADERDIR = header

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
HEADER = $(wildcard $(HEADERDIR)/*.hpp)

# Colors
GREEN = \e[92;5;118m
YELLOW = \e[93;5;226m
RESET = \e[0m

# Debug
ifeq ($(DEBUG), 1)
OPTS = -g
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(GREEN)- Executable ready.$(RESET)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@printf "$(YELLOW)- Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed.$(RESET)\n"

re: fclean all