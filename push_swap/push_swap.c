/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:18:33 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 21:49:31 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *set_list(int argc, char **argv)
{
    int i;
    long num;
    t_list *new;
    t_list *list;

    i = 1;
    list = NULL;
    while (i < argc)
    {
        num = (long)ft_atoi(argv[i++]);
        new = ft_lstnew((void *)num);
        if (new == NULL)
        {
            ft_lstclear(&list, &del);
            return (NULL);
        }
        ft_lstadd_back(&list, new);
    }
    return (list);
}

int check_error(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return (OK);
}

void print_list(t_list *list)
{
    int i;

    i = 1;
    if (ft_lstsize(list) == 0)
        return ;
    while (list != NULL)
    {
        printf("%d: %d\n", i, (int)list->content);
        list = list->next;
        i++;
    }
    return ;
}

int main(int argc, char *argv[])
{
    t_list *list_a;
    t_list *list_b;
    int *arry;
    
    list_a = NULL;
    list_b = NULL;
    if (check_error(argc, argv) == NG)
    {
        write(STDERR_FILENO, "error", 6);
        return (NG);
    }
    list_a = set_list(argc, argv);

    //arry
    arry = malloc(sizeof(int) * ft_lstsize(list_a));
    set_arry(list_a, arry);
    //print_arry(arry, argc - 1);

    //plan push_b!!
    sort_push(&list_a, &list_b, arry);
    all_push(&list_a, &list_b);
    //print_list(list_a);

    //end
    free(arry);
    return 0;
}