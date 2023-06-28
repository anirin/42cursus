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

void get_pivot(t_list **list, int size, int *pivot)
{
    int arry[size];

    set_arry(*list, arry);
    *pivot = arry[size / 2 - 1];
}

void get_three_pivot(t_list **list, int size, int *pivot)
{
    int arry[size];

    set_arry(*list, arry);
    pivot[0] = arry[(size / 4) - 1];
    pivot[1] = arry[(size / 2) - 1];
    pivot[2] = arry[(size / 2) + (size / 4) - 1];
}

void half_push(t_list **list_a, t_list **list_b, int *pivot, int size)
{
    int count;

    count = 0;
    while(count < size - size / 2)
    {
        if ((int)(*list_b)->content > pivot[1])
        {
            push(list_b, list_a, A);
            count++;
        }
        else
            rotate(list_b, B);
    }
}

void half_push_back(t_list **list_a, t_list **list_b, int size)
{
    int count;

    count = 0;
    while(count < size - size / 2)
    {
        push(list_a, list_b, B);
        count++;
    }
}


void first_half_push(t_list **list_a, t_list **list_b, int *pivot, int size)
{
    int count;

    count = 0;
    while(count < size / 2)
    {
        if ((int)(*list_a)->content <= pivot[1])
        {
            push(list_a, list_b, B);
            if ((int)(*list_b)->content <= pivot[0])
                rotate(list_b, B);
            count++;
        }
        else
            rotate(list_a, A);
    }
}

void second_half_push(t_list **list_a, t_list **list_b, int *pivot, int size)
{
    int count;

    count = 0;
    while(count < size - (size / 2))
    {
        if ((int)(*list_a)->content > pivot[1])
        {
            push(list_a, list_b, B);
            if ((int)(*list_b)->content <= pivot[2])
                rotate(list_b, B);
            count++;
        }
        else
            rotate(list_a, A);
    }
}
