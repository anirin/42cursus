/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:18:33 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/24 08:23:19 by atokamot         ###   ########.fr       */
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
    t_arry arry_info;
    
    list_a = NULL;
    list_b = NULL;
    if (check_error(argc, argv) == NG)
    {
        write(STDERR_FILENO, "error", 6);
        return (NG);
    }
    list_a = set_list(argc, argv);
    //print_list(list_a);

    //arry
    arry_info.arry = malloc(sizeof(int) * ft_lstsize(list_a));
    set_arry(list_a, arry_info.arry);
    arry_info.size = argc - 1;
    //print_arry(arry, argc - 1);
    print_list(list_a);
    
    half_push(&list_a, &list_b, A, UNDER);
    while (1)
    {
        /*
        printf("------------\n");
        print_list(list_a);
        printf("-\n");
        print_list(list_b);
        printf("------------\n");
        */
        if(ft_lstsize(list_b) <= 3)
            break;
        half_push(&list_b, &list_a, B, OVER);
    }
    sort_three(&list_b, B);

    printf("------------\n");
    print_list(list_a);
    printf("-\n");
    print_list(list_b);
    printf("------------\n");

    //end
    free(arry_info.arry);
    ft_lstclear(&list_a, &del);
    return 0;
}