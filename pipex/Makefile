NAME = pipex

SRC = close_error.c dup_error.c exec_child_and_parent.c free_split.c get_path.c open.c pipe_error.c pipex.c waitpid_error.c fork_error.c
SRCS = $(addprefix srcs/,$(SRC))
OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -Llibft -lft -o $(NAME) 

all: $(NAME)

clean: 
	make clean -C ./libft
	rm -rf $(OBJ) 

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: clean all

ex :
	./pipex infile "grep a" "wc -w" outfile
	@cat outfile
	@echo -----------

true :
	< infile grep a | wc -w > outfile
	@cat outfile
	@echo -----------

norm :
	norminette includes libft srcs