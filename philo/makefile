# CFLAGS = -Wall -Wextra -Werror
NAME = philo
CC = gcc
SRCS = main.c init.c simulation.c
OBJ_DIR = obj
OBJCS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) -o $@ $(OBJCS)

clean:
	$(RM) $(OBJCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re