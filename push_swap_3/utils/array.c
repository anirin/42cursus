/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:08 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 10:48:59 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"

void swap_array(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int bub_sort_array(int *array, int size)
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
            if (array[i] > array[i + 1])
            {
                swap_array(&array[i], &array[i + 1]);
                count++;
            }
            i++;
        }
        j++;
    }
    return (count);
}

void set_array(int *array, int size, char **argv)
{
    int i;

    i = 0;
    while (i < size)
    {
        array[i] = ft_atoi(argv[i + 1]);
        i++;
    }
}

void set_array_num(int *array, t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        array[i++] = (int)list->content;
        list = list->next;
    }
}

void set_array_num_by_size(int *array, t_list *list, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        array[i++] = (int)list->content;
        list = list->next;
    }
}

void compress_array(int *array, int *sorted_array, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while(j < size)
        {
            if (array[i] == sorted_array[j])
            {
                array[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
}

void print_array(int *array, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        printf("array[%d]=%d\n", i, array[i]);
        i++;
    }
}