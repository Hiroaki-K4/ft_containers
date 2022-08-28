NAME := grade

TEST_DIR := ./tester/
SRC := tester/main.cpp tester/test_vector.cpp tester/test_enable_if.cpp tester/test_is_integral.cpp
OBJ := $(SRC:.cpp=.o)
INCLUDE := -I./containers
HEADER := containers/vector.hpp

RM := rm -rf
CC := c++
# FLAGS := -Wall -Wextra -Werror -std=c++98
FLAGS := -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(TEST_DIR)%.o: $(TEST_DIR)%.cpp
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

lint:
	cpplint --filter=-legal/copyright,-build/header_guard $(SRC) $(HEADER)

test: debug
# test: lint
test: ./grade

.PHONY: all clean fclean re test lint
