CXX = c++
CXXFLAG = -std=c++98 -Wall -Wextra -Werror
NAME = serializer
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
HEAD = Base.hpp A.hpp B.hpp C.hpp
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