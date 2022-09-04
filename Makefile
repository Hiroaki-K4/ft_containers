NAME := grade

TEST_DIR := ./tester/
SRC := tester/main.cpp \
	   tester/test_vector.cpp \
	   tester/test_enable_if.cpp \
	   tester/test_is_integral.cpp \
	   tester/test_iterator_traits.cpp \
	   tester/test_reverse_iterator.cpp
OBJ := $(SRC:.cpp=.o)
INCLUDE := -I./includes
HEADER := includes/vector.hpp includes/type_traits.hpp

RM := rm -rf
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

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
