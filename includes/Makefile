# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 16:07:50 by zdawnsta          #+#    #+#              #
#    Updated: 2020/12/21 16:07:56 by zdawnsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRCS = ../mainList.cpp

HEADER = utils.hpp list.hpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
# FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS = -Wall -Wextra -Werror -std=c++11
RM = rm -f
RMR = rm -rf

all: $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n\033[0;33mCompiling $(NAME)..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	$(RMR) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	$(RM) $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re
