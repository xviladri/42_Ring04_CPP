# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 19:20:52 by xviladri          #+#    #+#              #
#    Updated: 2026/01/17 13:52:23 by xviladri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
