CC = gcc #変更
# FLAG = -Wall -Wextra -Werror
SEGV = -g -fsanitize=address
NAME = philo

SRC = main.c init.c philo.c utils.c print.c time.c 

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAG) $(SEGV) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(SEGV)

all: $(NAME)

clean: 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: clean all