CC = g++
FLAG = -std=c++98
NAME = phonebook
SRC = phonebook.cpp contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re format

%.o: %.cpp
	$(CC) $(FLAG) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)
	rm -rf megaphone

re: fclean all

format:
	clang-format -i $(SRC)