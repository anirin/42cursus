/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _algorithm3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:01:14 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/27 10:12:17 atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void one_third_push(t_list **list_a, t_list **list_b, int pivot, int push_num)
{
    int count;

    count = 0;
    while(count < push_num)
    {
        if ((int)(*list_b)->content > pivot)
        {
            push(list_b, list_a, A);
            count++;
        }
        else
            rotate(list_b, B);
    }
}

void first_one_third_push(t_list **list_a, t_list **list_b, int pivot, int push_num)
{
    int count;

    count = 0;
    while(count < push_num)
    {
        if ((int)(*list_b)->content <= pivot)
        {
            push(list_b, list_a, A);
            count++;
        }
        else
            rotate(list_b, B);
    }
}

void one_third_push_back(t_list **list_a, t_list **list_b, int push_back_num)
{
    int count;

    count = 0;
    while(count < push_back_num)
    {
        push(list_a, list_b, B);
        count++;
    }
}

void get_pivot(t_list **list, int size, int *pivot)
{
    int arry[size];

    set_arry(*list, arry);
    pivot[0] = arry[size / 3 - 1];
    pivot[1] = arry[(size / 3) * 2 - 1];
}

void two_third_push(t_list **list_a, t_list **list_b, int size)
{
    int pivot[2];

    get_pivot(list_b, size, pivot);
    one_third_push(list_a, list_b, pivot[1], size - (size / 3) * 2);
    one_third_push(list_a, list_b, pivot[0], size / 3);
}