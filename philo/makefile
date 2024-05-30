CC = gcc
CFLAGS = -Wall -Wextra -Werror
ADDRESS = -fsanitize=address
# THREAD = -fsanitize=thread

NAME = philo

SRC_DIR = ./
OBJ_DIR = obj
INC_DIR = include

SRCS = \
	./main.c \
	./logic/simulation.c \
	./routine/eat.c \
	./routine/get_fork.c \
	./routine/other.c \
	./routine/sleep.c \
	./routine/think.c \
	./util/cleanup.c \
	./util/error.c \
	./util/init.c \
	./util/print.c \
	./util/time.c

OBJCS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/logic $(OBJ_DIR)/routine $(OBJ_DIR)/util

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) $(ADDRESS) $(THREAD) -o $@ $(OBJCS)

clean:
	$(RM) $(OBJCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: fclean all
	./philo 5 1000 200 200 10

files:
	@echo $(SRCS) | tr ' ' '\n'

.PHONY: all clean fclean re run files