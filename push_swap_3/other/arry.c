/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 19:22:07 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"

void swap_arry(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int bub_sort_arry(int *arry, int size)
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

void set_arry(int *arry, int size, char **argv)
{
    int i;

    i = 0;
    while (i < size)
    {
        arry[i] = ft_atoi(argv[i + 1]);
        i++;
    }
}

void set_arry_num(int *arry, t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        arry[i++] = (int)list->content;
        list = list->next;
    }
}

void compress_arry(int *arry, int *sorted_arry, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while(j < size)
        {
            if (arry[i] == sorted_arry[j])
            {
                arry[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
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