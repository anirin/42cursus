/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:18:33 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/21 14:24:31 by atokamot         ###   ########.fr       */
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
    
    if (check_error(argc, argv) == NG)
    {
        write(STDERR_FILENO, "error", 6);
        return (NG);
    }
    list_a = set_list(argc, argv);
    // print_list(list_a);
    //operate test
    printf("----------\n");
    print_list(list_a);
    printf("----------\n");
    rotate(&list_a);
    print_list(list_a);
    return 0;
}