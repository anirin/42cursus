/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/25 18:55:29 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_arry(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bsort_arry(int *arry, int size)
{
    int i;
    int j;

    j = 1;
    while(j <= size)
    {
        i = 0;
        while(i < size - j)
        {
            if (arry[i] > arry[i + 1])
            {
                swap_arry(&arry[i], &arry[i + 1]);
            }
            i++;
        }
        j++;
    }
}

void set_arry(t_list *list, int *arry)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = list;
    while (tmp != NULL)
    {
        arry[i++] = (int)tmp->content;
        tmp = tmp->next;
    }
    bsort_arry(arry, ft_lstsize(list));
}

int check_half_arry(t_list *list, t_arry arry_info, int flag)
{
    int start;
    int end;

    if (flag == UNDER)
    {
        start = 0;
        end = arry_info.size / 2;
        if (arry_info.size % 2 == 1)
            end += 1;
    }
    else
    {
        start = arry_info.size / 2;
        end = arry_info.size;
    }
    while (start < end)
    {
        if ((int)list->content == arry_info.arry[start++])
            return (OK);
    }
    return (NG);
}

int check_num_arry(t_list *list, t_arry arry_info, int num)
{
    int count;

    count = 1;
    while (count <= num)
    {
        if ((int)list->content == arry_info.arry[arry_info.size - count])
            return (OK);
        count++;
    }
    return (NG);
}

void print_arry(int *arry, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        printf("arry[%d]=%d\n", i, arry[i]);
        i++;
    }
}