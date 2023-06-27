/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:53:00 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/27 19:57:24 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    arry = malloc(sizeof(int) * ft_lstsize(list_a));
    if (set_arry(list_a, arry) == NG)
        push_swap(&list_a, &list_b);

    //result print
    // printf("------------\n");
    // print_list(list_a);
    // printf("-\n");
    // print_list(list_b);
    // printf("------------\n");

    ft_lstclear(&list_a, &del);
    free(arry);
    return 0;
}

    //result print

    // printf("------------\n");
    // print_list(list_a);
    // printf("-\n");
    // print_list(list_b);
    // printf("------------\n");