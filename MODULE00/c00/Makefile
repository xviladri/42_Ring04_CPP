NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

RESET	=	\033[0m
YELLOW	=	\033[32m
BLUE	=	\033[34m
RED	=	\033[31m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "$(BLUE)Finished [$(NAME)]$(RESET)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
