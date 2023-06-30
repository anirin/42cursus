/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:09:10 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 15:27:32 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"
#include "../header/algorithm.h"

int main(int argc, char **argv)
{
    int *arry;
    int *sorted_arry;
    int size;
    int sort_count;
    t_list *list_a;
    t_list *list_b;
    t_list *swap_result;

    size = argc - 1; //tmp
    list_a = NULL;
    list_b = NULL;
    swap_result = NULL;
    
    //set arry
    arry = malloc(sizeof(int) * size);
    sorted_arry = malloc(sizeof(int) * size);
    set_arry(arry, size, argv);
    set_arry(sorted_arry, size, argv);
    sort_count = bub_sort_arry(sorted_arry, size);
    compress_arry(arry, sorted_arry, size);
    //print
    //print_arry(sorted_arry, size);

    //set list
    list_a = set_list(size, arry);

    //sort!!
    //if (sort_count != 0) 
    push_swap(&list_a, &list_b, &swap_result);

    print_list(swap_result);
    // print_list(list_a);

    //end
    free(arry);
    free(sorted_arry);
    ft_lstclear(&list_a, &del);
    ft_lstclear(&swap_result, &del);
}


    //print
    //print_arry(arry, size);

//gcc *.c ./*/*.c -I ./header  