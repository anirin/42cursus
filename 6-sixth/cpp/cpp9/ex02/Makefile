CXX = c++
CXXFLAG = -std=c++98 -Wall -Wextra -Werror
NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re format

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

format:
	clang-format -i $(SRC) $(HEAD)

leaks:
	valgrind --leak-check=full ./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

test:
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

mac:
	./$(NAME) `jot -r 30000 1 100000 | tr "\n" " "`