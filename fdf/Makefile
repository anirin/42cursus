CC = gcc
NAME = fdf_exe

SRC = main.c ./fdf_main/map.c ./fdf_main/print.c
OBJ = $(SRC:.c=.o)


%.o: %.c
	$(CC) -I ./header -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -g -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a
#	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

all : $(NAME)

fclean : 
	rm -rf $(OBJ) 

clean : fclean
	make fclean -C ./libft
	rm -rf $(NAME)

re : clean all