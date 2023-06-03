CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a
POBJS = $(PSRCS:%.c=%.o)
PSRCS = ft_format1.c\
	ft_format2.c\
	ft_get_numlen.c\
	ft_tohex.c\
	ft_printf.c\
	ft_putunbr_fd.c
INCLUDE = -I ./libft


$(NAME): $(POBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	$(AR) $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(POBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re : fclean all	
