/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:53:00 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/26 18:36:00 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_list *list_a;
    t_list *list_b;
    
    list_a = NULL;
    list_b = NULL;
    if (check_error(argc, argv) == NG)
    {
        write(STDERR_FILENO, "error", 6);
        return (NG);
    }
    list_a = set_list(argc, argv);
    if (list_a == NULL)
        return (NG);
    if(ft_lstsize(list_a) == 2)
        sort_two_a(&list_a, A);
    else if(ft_lstsize(list_a) == 3)
        sort_three_a(&list_a, A);
    else if(ft_lstsize(list_a) == 4)
        sort_four_a(&list_a, &list_b, A, 4);
    else if(ft_lstsize(list_a) == 5)
        sort_five_a(&list_a, &list_b, A, 5);
    else
    {
        half_push(&list_a, &list_b, A, UNDER, ft_lstsize(list_a));
        recursive_push(&list_a, &list_b);
        half_push(&list_a, &list_b, A, OVER, ft_lstsize(list_a));
        recursive_push(&list_a, &list_b);
    }
    ft_lstclear(&list_a, &del);
    return 0;
}

    //result print

    // printf("------------\n");
    // print_list(list_a);
    // printf("-\n");
    // print_list(list_b);
    // printf("------------\n");