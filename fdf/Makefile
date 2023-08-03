CC = gcc
NAME = fdf_exe

FDF_DIR = ./fdf_main/
FDF_FILES = connect_color.c map.c connect_dot.c print.c equation.c rotate.c get_color.c zoom_cor.c create_trgb.c
FDF_SRC = $(addprefix $(FDF_DIR),$(FDF_FILES))

SRC = main.c $(FDF_SRC)

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -I ./header -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

all: $(NAME)

clean: 
	make clean -C ./libft
	rm -rf $(OBJ) 

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf libft.a

re: clean all

norm :
	norminette ./header ./fdf_main ./libft main.c

f :
	./fdf_exe test_maps/42.fdf