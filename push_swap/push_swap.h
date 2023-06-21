#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define OK 1
#define NG 0
# define IS_SEP 1
# define NOT_SEP 0
# define HEAD 1
# define NOT_HEAD 0

typedef struct s_list
{
    void  *content;
    struct s_list *next;
}              t_list;

#include <libc.h>

int	ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstseclast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
void del(void *content);

//operate
int check_list(t_list **list);
void swap(t_list **list);
void push(t_list **list_a, t_list **list_b);
void rotate(t_list **list);
void rev_rotate(t_list **list);


#endif