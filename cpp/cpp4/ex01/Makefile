CXX = c++
CXXFLAG = -std=c++98 -Wall -Wextra -Werror -g
# CXXFLAG = -std=c++98 -Wall -Wextra -Werror
# valgrind --leak-check=full -s ./main
NAME = main
SRC = main.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp
HEAD = Cat.hpp Dog.hpp Animal.hpp Brain.hpp
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