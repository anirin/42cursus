/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:58:07 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 14:49:46 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"
#include "../header/algorithm.h"

void first_half_push(t_list **list_a, t_list **list_b, int *pivot, int size, t_list **swap_result)
{
    int i;

    i = 0;
    while (i < size)
    {
        if ((int)(*list_a)->content <= pivot[1])
        {
            push(list_a, list_b, B, swap_result);
            i++;
        }
        else
        {
            if (*list_b != NULL && (int)(*list_b)->content <= pivot[0])
            {
                // printf("-------RR----------\n");
                rotate(list_a, R, swap_result);
                rotate(list_b, C, swap_result);
            }
            else
                rotate(list_a, A, swap_result);
            // rotate(list_a, A);
        }
    }
}

void second_half_push(t_list **list_a, t_list **list_b, int *pivot, int size, t_list **swap_result)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (can_rotate(list_a, swap_result) == OK)
            i++;
        else if (can_swap_rotate(list_a, swap_result) == OK)
            i += 2;
        else if ((int)(*list_a)->content > pivot[1])
        {
            if (!(*list_b == NULL && i == size - 1))
            {
                push(list_a, list_b, B, swap_result);
                // if ((int)(*list_b)->content > pivot[2])
                //     rotate(list_b, B);
            }
            i++;
        }
        else
            rotate(list_a, A, swap_result);
    }
}

void recursive_half_push(t_list **list_a, t_list **list_b, t_list **swap_result)
{
    int pivot[3];
    int size;

    if (finish_condition(list_a, list_b, swap_result) == OK)
        return ;
    size = ft_lstsize(*list_b);
    get_three_pivot(list_b, size, pivot);
    
    //print
    // printf("size = %d\n", size);
    // printf("pivot[1] = %d\n", pivot[1]);

    half_push_to_a(list_a, list_b, pivot, size - (size / 2), swap_result);
    if (finish_condition(list_a, list_b, swap_result) == NG)
        recursive_half_push(list_a, list_b, swap_result);

    half_push_back_to_b(list_a, list_b, size - (size / 2), swap_result);
    if (finish_condition(list_a, list_b, swap_result) == NG)
        recursive_half_push(list_a, list_b, swap_result);
}

void push_swap(t_list **list_a, t_list **list_b, t_list **swap_result)
{
    int pivot[3];
    int size;

    if (first_finish_condition(list_a, list_b, swap_result) == OK)
        return ;
 
    size = ft_lstsize(*list_a);
    get_three_pivot(list_a, size, pivot);
    // printf("pivot[0] = %d\n", pivot[0]);
    // printf("pivot[1] = %d\n", pivot[1]);
    // printf("pivot[2] = %d\n", pivot[2]);
    // printf("size / 2 = %d\n", size / 2);

    first_half_push(list_a, list_b, pivot, size / 2, swap_result);
    if (finish_condition(list_a, list_b, swap_result) == NG)
        recursive_half_push(list_a, list_b, swap_result);

    second_half_push(list_a, list_b, pivot, size - (size / 2), swap_result);
    if (finish_condition(list_a, list_b, swap_result) == NG)
        recursive_half_push(list_a, list_b, swap_result);
}