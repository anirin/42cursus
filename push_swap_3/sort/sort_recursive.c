/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:25:06 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 14:56:04 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"

//recursive A (3~ ok)
void sort_recursive_a(t_list **list_a, t_list **list_b, int size, t_list **swap_result)
{
    int flag;

    if (size == 2)
    {
        sort_two_a(list_a, swap_result);
        return ;
    }
    if (size == 3)
    {
        sort_three_a(list_a, swap_result);
        return ;
    }
    flag = rotate_max_or_min(list_a, size , A, swap_result); //1 give priority MIN 
    push(list_a, list_b, B, swap_result);
    if (flag == BIG)
    {
        sort_recursive_a(list_a, list_b, size - 1, swap_result);
        push(list_b, list_a, A, swap_result);
        rotate(list_a, A, swap_result);
    }
    if (flag == SMALL)
    {
        sort_recursive_a(list_a, list_b, size - 1, swap_result);
        push(list_b, list_a, A, swap_result);
    }
}

//recursive B (1~ ok)
void sort_recursive_b(t_list **list_a, t_list **list_b, int size, t_list **swap_result)
{
    int flag;

    if (size == 1)
    {
        push(list_b, list_a, A, swap_result);
        rotate(list_a, A, swap_result);
        return ;
    }
    flag = rotate_max_or_min(list_b, size, B, swap_result); //1
    if (flag == BIG)
    {
        push(list_b, list_a, A, swap_result);
        sort_recursive_b(list_a, list_b, size - 1, swap_result);
        rotate(list_a, A, swap_result);
    }
    if (flag == SMALL)
    {
        push(list_b, list_a, A, swap_result);
        rotate(list_a, A, swap_result);
        sort_recursive_b(list_a, list_b, size - 1, swap_result);
    }
}

int get_min(int i, int size)
{
    if (i < size - i)
        return (i);
    else
        return (size - i);
}

t_location get_location(t_list *list, int size)
{
    int arry[size];
    int i;
    t_location location;

    i = 0;
    set_arry_num(arry, list);
    bub_sort_arry(arry, size);
    while (list != NULL)
    {
        if (arry[0] == (int)list->content)
            location.min= i;
        if (arry[size - 1] == (int)list->content)
            location.max = i;
        list = list->next;
        i++;
    }
    return (location);
}

int rotate_max_or_min(t_list **list, int size, int flag, t_list **swap_result)
{
    t_location location;
    int i;
    int min_rotate_num;
    int max_rotate_num;

    location = get_location(*list, size);
    //printf("size = %d, min = %d, max = %d\n", size, location.min, location.max);
    i = 0;
    //if (get_min(location.min, size) <= get_min(location.max, size))
    if (get_min(location.min, size) <= get_min(location.max, size))
    {
        if (location.min < size / 2 + 1)
        {
            while (i < get_min(location.min, size))
            {
                rotate(list, flag, swap_result);
                i++; 
            }
        }
        else
        {
            while (i < get_min(location.min, size))
            {
                rev_rotate(list, flag, swap_result);
                i++; 
            }
        }
        return (SMALL);
    }
    else
    {
        if (location.max < size / 2 + 1)
        {
            while (i < get_min(location.max, size))
            {
                rotate(list, flag, swap_result);
                i++; 
            }
        }
        else
        {
            while (i < get_min(location.max, size))
            {
                rev_rotate(list, flag, swap_result);
                i++; 
            }
        }
        return (BIG);
    }
}