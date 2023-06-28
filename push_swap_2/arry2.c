/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:55:25 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/28 12:05:27 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_arry_index(int *arry, int num)
{
    int index;

    index = 0;
    while(1)
    {
        if (arry[index] == num)
            break;
        index++;
    }
    return (index);
}

int is_next_list(int *arry, t_list *list_a)
{
    int head_index;
    int tail_index;

    head_index = get_arry_index(arry, (int)list_a->content);
    tail_index = get_arry_index(arry, (int)ft_lstlast(list_a)->content);
    if (head_index == tail_index + 1)
    {
        return (OK);
    }
    else
        return (NG);
}

int is_swap_next_list(int *arry, t_list *list_a)
{
    int head_index1;
    int head_index2;
    int tail_index;

    head_index1 = get_arry_index(arry, (int)list_a->content);
    head_index2 = get_arry_index(arry, (int)list_a->next->content);
    tail_index = get_arry_index(arry, (int)ft_lstlast(list_a)->content);
    if (head_index2 == tail_index + 1 && head_index1 == head_index2 + 1)
    {
        return (OK);
    }
    else
        return (NG);
}
