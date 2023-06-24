/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:53:00 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/24 12:05:54 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    //print_list(list_a);
    
    //algorithm
    half_push(&list_a, &list_b, A, UNDER);
    recursive_push(&list_a, &list_b);

    //result print
    // printf("------------\n");
    // print_list(list_a);
    // printf("-\n");
    // print_list(list_b);
    // printf("------------\n");
    
    half_push(&list_a, &list_b, A, OVER);
    recursive_push(&list_a, &list_b);

    //result print
    // printf("------------\n");
    // print_list(list_a);
    // printf("-\n");
    // print_list(list_b);
    // printf("------------\n");

    //end
    free(arry_info.arry);
    ft_lstclear(&list_a, &del);
    return 0;
}