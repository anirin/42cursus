TARGET = push_swap
BONUS_TARGET = checker
INCLUDES = -I ./header
CFLAGS = -Wall -Werror -Wextra

#filses
ALGOFILES = algo_main.c finish_condi_and_half_push.c rotate_pivot.c
FTLSTFILES = ft_atoi.c ft_lstadd.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_split.c ft_is_check.c ft_strcmp.c 
SORTFILES = rotate_max_or_min.c sort_2_3.c sort_recursive.c
OPEFILES = operate.c swap_result_exit.c
UTILSFILES = array_util.c main.c set_and_print_list.c set_array.c error_check.c set_main.c
CHECKFILES = check_operate.c check_main.c
GNLFILES = get_next_line.c get_next_line_utils.c
CHECK_UTILSFILES = array_util.c set_and_print_list.c set_array.c error_check.c set_main.c

#sources
ALGOSRCS = $(addprefix $(ALGODIR),$(ALGOFILES))
FTLSTSRCS = $(addprefix $(FTLSTDIR),$(FTLSTFILES))
SORTSRCS = $(addprefix $(SORTDIR),$(SORTFILES))
OPESRCS = $(addprefix $(OPEDIR),$(OPEFILES))
UTILSSRCS = $(addprefix $(UTILSDIR),$(UTILSFILES)) 
CHECKSRCS = $(addprefix $(CHECKDIR),$(CHECKFILES))
GNLSRCS = $(addprefix $(GNLDIR), $(GNLFILES))
CHECK_UTILSSRCS = $(addprefix $(UTILSDIR),$(CHECK_UTILSFILES)) 

#dir
ALGODIR = ./algorithm/
FTLSTDIR = ./ft_lst/
OPEDIR = ./operate/
SORTDIR = ./sort/
UTILSDIR = ./utils/
CHECKDIR = ./check_bonus/
GNLDIR = ./get_next_line/

#objects
ALGOOBJS = $(ALGOSRCS:.c=.o)
FTLSTOBJS = $(FTLSTSRCS:.c=.o)
SORTOBJS = $(SORTSRCS:.c=.o)
OPEOBJS = $(OPESRCS:.c=.o)
UTILSOBJS = $(UTILSSRCS:.c=.o)
CHECKOBJS = $(CHECKSRCS:.c=.o)
GNLOBJS = $(GNLSRCS:.c=.o)
CHECK_UTILSOBJS = $(CHECK_UTILSSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

all : $(TARGET)

$(TARGET) : $(ALGOOBJS) $(FTLSTOBJS) $(SORTOBJS) $(OPEOBJS) $(UTILSOBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(BONUS_TARGET) : $(ALGOOBJS) $(FTLSTOBJS) $(SORTOBJS) $(OPEOBJS) $(CHECK_UTILSOBJS) $(CHECKOBJS) $(GNLOBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

bonus : $(BONUS_TARGET)

fclean :
	rm -rf $(ALGOOBJS) $(FTLSTOBJS) $(SORTOBJS) $(OPEOBJS) $(UTILSOBJS) $(GNLOBJS) $(CHECKOBJS)

clean : fclean
	rm -rf $(TARGET) $(BONUS_TARGET)

re : clean all

.PHONY : all clean fclean re

echo :
	echo $(UTILSSRCS)

debug : clean
	gcc ./*/*.c -I ./header -g -fsanitize=address -o push_swap