/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:09:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:02 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"
#include "../header/algorithm.h"


t_three_lists set_main_lists(t_three_lists three_lists, int size, int *arry)
{
    t_three_lists three_lists;

    *three_lists.list_a == set_list(size, arry);
    *three_lists.list_b == NULL;
    *three_lists.swap_result == NULL;
    return (three_lists);
}

int *set_main_arry(int size, char **argv)
{
    int sorted_arry[size];
    
    arry = malloc(sizeof(int) * size);
    if (arry == NULL)
        return (NULL);
    set_arry(arry, size, argv);
    set_arry(sorted_arry, size, argv);
    sort_count = bub_sort_arry(sorted_arry, size);
    compress_arry(arry, sorted_arry, size);
    return (arry); 
}

int main(int argc, char **argv)
{
    int *arry;
    int size;
    t_three_lists three_lists;

    size = argc - 1; 
    arry = set_arry_in_main(size, argv);
    if (arry == NULL)
        return (NG);
    three_lists = set_list(size, arry);
    push_swap(&three_lists);
    print_list(swap_result);

    //end
    free(arry);
    ft_lstclear(three_lists.list_a, &del);
    ft_lstclear(three_lists.swap_result, &del);
}


    //print
    //print_arry(arry, size);

//gcc *.c ./*/*.c -I ./header  