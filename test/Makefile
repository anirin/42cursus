CC = gcc
NAME = exe_test

SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)


%.o: %.c
	$(CC) -I ./header -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

fclean : 
	rm -rf $(OBJ) 

clean : fclean
	rm -rf $(NAME)

re : clean all