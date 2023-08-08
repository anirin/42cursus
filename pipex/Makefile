CC = gcc
NAME = pipex

SRC = srcs/*.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -C ../includes/libft
	$(CC) $(OBJ) -o $(NAME) libft.a

all: $(NAME)

clean: 
	make clean -C ../includes/libft
	rm -rf $(OBJ) 

fclean: clean
	make fclean -C ../includes/libft
	rm -rf $(NAME)

re: clean all
