# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:58:16 by aisidore          #+#    #+#              #
#    Updated: 2025/06/10 19:04:39 by aisidore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp \
	  Account.cpp

OBJ = $(SRC:%.cpp=objets/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

objets/%.o: %.cpp
	mkdir -p objets
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f objets/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

