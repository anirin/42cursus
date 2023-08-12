CC = cc
NAME = pipex

SRC = ${wildcard srcs/*.c}
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -o $(NAME) libft.a

all: $(NAME)

clean: 
	make clean -C ./libft
	rm -rf $(OBJ) 

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: clean all

ex :
	./pipex infile "grep a1" "wc -w" outfile
