/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/27 11:41:12 by atokamot         ###   ########.fr       */
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

int bsort_arry(int *arry, int size)
{
    int i;
    int j;
    int count;

    count = 0;
    j = 1;
    while(j <= size)
    {
        i = 0;
        while(i < size - j)
        {
            if (arry[i] > arry[i + 1])
            {
                swap_arry(&arry[i], &arry[i + 1]);
                count++;
            }
            i++;
        }
        j++;
    }
    return (count);
}

int set_arry(t_list *list, int *arry)
{
    int i;
    int size;

    i = 0;
    size = ft_lstsize(list);
    while (list != NULL)
    {
        arry[i++] = (int)list->content;
        list = list->next;
    }
    if (bsort_arry(arry, size) == 0)
        return (OK);
    else
        return (NG);
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