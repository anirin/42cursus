#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define OK 1
#define NG 0
#define A 0
#define B 1
#define C 2
#define R 3
#define OVER 0
#define UNDER 1
# define IS_SEP 1
# define NOT_SEP 0
# define HEAD 1
# define NOT_HEAD 0

typedef struct s_list
{
    void  *content;
    struct s_list *next;
}              t_list;

typedef struct s_arry
{
    int *arry;
    int size;
}              t_arry;

#include <libc.h>

//libft
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

//list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstseclast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);

//list add
void del(void *content);
t_list  *set_list(int argc, char **argv);
void print_list(t_list *list);

//arry
void swap_arry(int *a, int *b);
int bsort_arry(int *arry, int size);
int set_arry(t_list *list, int *arry);
void print_arry(int *arry, int size);

//operate
int check_list(t_list **list);
void swap(t_list **list, int flag);
void push(t_list **list_a, t_list **list_b, int flag);
void rotate(t_list **list, int flag);
void rev_rotate(t_list **list, int flag);

//func typedef
typedef void t_operate(t_list **list, int flag);

//algorithm
int get_location(int num, int *arry, int size);
void num_min_rotate(t_list **list, int num, int *arry, int size, int flag);
void all_push_rotate(t_list **list_a, t_list **list_b);
int first_finish_condition(t_list **list_a, t_list **list_b);
int finish_condition(t_list **list_a, t_list **list_b);
//algorithm one third
void one_third_push(t_list **list_a, t_list **list_b, int pivot, int push_num);
void first_one_third_push(t_list **list_a, t_list **list_b, int pivot, int push_num);
void one_third_push_back(t_list **list_a, t_list **list_b, int push_back_num);
void get_pivot(t_list **list, int size, int *pivot);
void two_third_push(t_list **list_a, t_list **list_b, int size);
void first_one_third(t_list **list_a, t_list **list_b);
void recursive_one_third(t_list **list_a, t_list **list_b);


//tool
int check_error(int argc, char **argv);
int rev_flag(int flag);

//sort 3~5
void sort_two_b(t_list **list);
void sort_two_a(t_list **list);
void sort_three_b(t_list **list);
void sort_three_a(t_list **list);
void sort_four_a(t_list **list_a, t_list **list_b);
void sort_four_b(t_list **list_a, t_list **list_b);
void sort_five_a(t_list **list_a, t_list **list_b);
void sort_five_b(t_list **list_a, t_list **list_b);

#endif