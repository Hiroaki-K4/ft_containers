NAME := test

SRCS_DIR := ./tester/
SRC := tester/main.cpp
OBJ := $(SRC:.cpp=.o)
INCLUDE := -I.

RM := rm -rf
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: $(SRCS_DIR)%.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: FLAGS += -fsanitize=address
debug: re

.PHONY: all clean fclean re
