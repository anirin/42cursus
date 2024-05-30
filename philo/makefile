# CFLAGS = -Wall -Wextra -Werror
ADDRESS = -fsanitize=address
# THREAD = -fsanitize=thread
NAME = philo
CC = gcc
SRCS = init.c main.c print.c simulation.c time.c cleanup.c error.c
OBJCS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = obj

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) $(ADDRESS) $(THREAD) -o $@ $(OBJCS)

clean:
	$(RM) $(OBJCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

run : fclean all
	./philo 5 1000 200 200 10 

files :
	ls *.c | tr '\n' ' '