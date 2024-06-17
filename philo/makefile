CFLAGS = -Wall -Wextra -Werror
SANITIZE_FLAGS = -fsanitize=address
# THREAD_FLAGS = -fsanitize=thread

NAME = philo

SRC_DIR = ./
OBJ_DIR = obj
INC_DIR = include

SRCS = \
	./main.c \
	./logic/simulation.c \
	./logic/monitor.c \
	./routine/eat.c \
	./routine/get_fork.c \
	./routine/change_fork_owner.c \
	./routine/sleep.c \
	./routine/think.c \
	./init/init_common.c \
	./init/init_fork.c \
	./init/init_philo.c \
	./init/set_data.c \
	./util/cleanup.c \
	./util/error.c \
	./util/print.c \
	./util/time.c \
	./util/my_usleep.c \
	./util/ft_atoi.c


OBJCS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

RED=\033[31m
GREEN=\033[32m
RESET=\033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJCS)
	@$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(THREAD_FLAGS) -o $@ $(OBJCS)
	@echo "$(GREEN)✅ $(NAME) created$(RESET)"

clean:
	@$(RM) $(OBJCS)
	@echo "🧹CLEANed"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo "🧹fcleaned"

re: fclean all

run: fclean all
	./philo 5 1000 200 200 10

files:
	@echo $(SRCS) | tr ' ' '\n'

.PHONY: all clean fclean re run files
