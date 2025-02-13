CXX = c++
CXXFLAG = -std=c++98 -Wall -Wextra -Werror -I ./includes
NAME = mergeInsertionSort
SRC = main.cpp Chain.cpp mergePart.cpp sort.cpp insertPart.cpp makeLayer.cpp print.cpp
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