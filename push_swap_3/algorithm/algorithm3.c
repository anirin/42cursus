/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:21:28 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 13:26:08 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"
#include "../header/algorithm.h"

int first_finish_condition(t_three_lists *three_lists)
{
    int finish_size;
    t_list **list_a;
    t_list **list_b;
    t_list **swap_result;

    list_a = three_lists->sub_list_a;
    list_b = three_lists->sub_list_b;
    swap_result = three_lists->sub_swap_result;
    finish_size = 30; //change here
    
    if (ft_lstsize(*list_a) <= finish_size)
    {
        sort_recursive_a(list_a, list_b, ft_lstsize(*list_a), swap_result);
        return (OK);
    }
    else
        return (NG);
}

int finish_condition(t_three_lists *three_lists)
{
    int finish_size;
    t_list **list_a;
    t_list **list_b;
    t_list **swap_result;

    list_a = three_lists->sub_list_a;
    list_b = three_lists->sub_list_b;
    swap_result = three_lists->sub_swap_result;

    finish_size = 25; //change here
    
    if (*list_b == NG)
        return (OK);
    if (ft_lstsize(*list_b) <= finish_size)
    {
        sort_recursive_b(list_a, list_b, ft_lstsize(*list_b), swap_result);
        return (OK);
    }
    else
        return (NG);
}

void half_push_to_a(t_three_lists *three_lists, int *pivot, int size)
{
    int i;
    t_list **list_a;
    t_list **list_b;
    t_list **swap_result;

    list_a = three_lists->sub_list_a;
    list_b = three_lists->sub_list_b;
    swap_result = three_lists->sub_swap_result;

    i = 0;
    while (i < size) 
    {
        if ((int)(*list_b)->content > pivot[1])
        {
            push(list_b, list_a, A, swap_result);
            i++;
        }
        else
            rotate(list_b, B, swap_result);
    }
}

void half_push_back_to_b(t_three_lists *three_lists, int size)
{
    int i;
    int sorted_arry[size];
    t_list **list_a;
    t_list **list_b;
    t_list **swap_result;

    list_a = three_lists->sub_list_a;
    list_b = three_lists->sub_list_b;
    swap_result = three_lists->sub_swap_result;

    i = 0;
    set_arry_num_by_size(sorted_arry, *list_a, size); //size < list size
    bub_sort_arry(sorted_arry, size);
    while (i < size)
    {
        if (can_rotate(three_lists) == OK)
            i++;
        else if (can_swap_rotate(three_lists) == OK)
            i += 2;
        else
        {
            if (!(*list_b == NULL && i == size - 1))
            {
                push(list_a, list_b, B, swap_result);
                if (rotate_nmax_and_nmin(*list_b, sorted_arry, size, i) == OK)
                {
                    rotate(list_b, B, swap_result);
                }
            }
            i++;
        }
    }
}

int rotate_nmax_and_nmin(t_list *list, int *sorted_arry, int size, int i)
{
    int finish_size_1;
    int finish_size_2;
    int n;

    finish_size_1 = 1; //change !! 1 max!
    finish_size_2 = 4; //change !! 1 max!
    n = 3; //change !! n 1~ n 3 max!!
    if (ft_lstsize(list) <= finish_size_1 || size - i <= finish_size_2)
        return (NG);
    if ((int)list->content >= sorted_arry[size - n] || (int)list->content <= sorted_arry[n - 1])
        return (OK); //change
    else
        return (NG);
}